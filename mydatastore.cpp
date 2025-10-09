#include "mydatastore.h"
using namespace std; 

MyDataStore::MyDataStore() { 

}

MyDataStore::~MyDataStore() {
    // Delete all products and users to free dynamic memory  
    for (size_t i = 0; i < products.size(); i++) { 
        delete products[i]; 
  }
  for (std::map<std::string, User*>:: iterator it = users.begin(); it != users.end(); it++) { 
    delete it->second; 
  }  
}


void MyDataStore::addProduct(Product *p){ 
    products.push_back(p); 
    std::set<string> p_keywords = p->keywords(); 

    // Map each keyword to this product
    for (set<string>::iterator it = p_keywords.begin(); it != p_keywords.end(); it++) { 
        std::string kw = *it; 
        keywords[kw].insert(p);  
    }

}


void MyDataStore::addUser(User *u) { 
    users[convToLower(u->getName())] = u; 
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    std::vector<Product*> searchResults; 
    
    for (size_t i = 0; i < terms.size(); i++) { 
      terms[i] = convToLower(terms[i]); 
    }

    for(size_t i = 0; i < products.size(); i++) {
        Product* p = products[i];
        std::set<string> p_keywords = p->keywords(); 
        size_t searchCount = 0; 
        
        // AND search 
        if (type == 0) { 
            for (size_t j = 0; j < terms.size(); j++) { 
                if (p_keywords.find(terms[j]) != p_keywords.end()) { 
                    searchCount++;  
                } 

            }
            // Check if products matches all terms 
            if (searchCount == terms.size()) { 
                searchResults.push_back(p);
            }
        }

        // OR search
        if (type == 1) {  
            for (size_t j = 0 ; j < terms.size(); j++) { 
                if (p_keywords.find(terms[j]) != p_keywords.end()) { 
                    searchCount++; 
                }
            }
            // Check if product matches at least 1 term 
            if (searchCount > 0) { 
                searchResults.push_back(p);
            }
        }
    }

    recentSearches = searchResults; 
    return searchResults; 
}

bool MyDataStore::checkUser(const std::string& username) { 
    return (users.find(convToLower(username)) != users.end()); 
}

void MyDataStore::addToCart(const std::string& username , Product* p) { 
        if (!checkUser(username)) { 
            std::cout << "Invalid request" << endl; 
            return; 
    }

    carts[convToLower(username)].push_back(p); 
}


void MyDataStore::viewCart(const std::string& username){ 
    if (!checkUser(username)) { 
        std::cout << "Invalid username" << endl; 
        return; 
    }

    vector<Product*>& user_cart = carts[convToLower(username)]; 
    for (size_t i = 0; i < user_cart.size(); i++) { 
        std::cout << "Item " << i + 1 << "\n" << user_cart[i]->displayString() << endl; 
    }

}

void MyDataStore::dump(std::ostream& ofile){ 
    ofile << "<products>" << endl; 
    for (size_t i = 0; i < products.size(); i++) { 
        products[i]->dump(ofile); 
    }
    ofile << "</products>" << "\n" << "<users>" << "\n"; 

    for (std::map<std::string, User*>::iterator it = users.begin(); it != users.end(); it++) {
        it->second->dump(ofile); 
    }
    ofile << "</users>" << endl; 
}

void MyDataStore::buyCart(const std::string& username) { 
    if (!checkUser(username)) { 
        std:: cout << "Invalid username" << endl; 
        return; 
    }

    vector<Product*>& user_cart = carts[convToLower(username)]; 
    User* user = users[convToLower(username)]; 

    // Go through each item in cart 
    size_t i = 0; 
    while (i < user_cart.size()) { 
        
        // If item is in stock and the user has a sufficient balance, purchase the item 
        if (user_cart[i]->getQty() > 0 && (user->getBalance() >= user_cart[i]->getPrice())) { 
            user->deductAmount(user_cart[i]->getPrice()); 
            user_cart[i]->subtractQty(1); 
            user_cart.erase(user_cart.begin()); 
        }
        // If not, check the next item in cart 
        else { 
            i++; 
        } 
    }
    
}
