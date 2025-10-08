#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include <string>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "user.h"
#include "util.h"

void displayProducts(std::vector<Product*>& hits);


class MyDataStore : public DataStore {  
public: 
    MyDataStore();
    ~MyDataStore(); 
    void addProduct(Product *p); 
    void addUser(User *u); 
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile); 
    void addToCart(const std::string& username , Product* p); 
    void buyCart(const std::string& username);
    void viewCart(const std::string& username); 
    bool checkUser(const std::string& username); 

private: 
std::vector<Product*> products; 
std::map<std::string, User*> users; 
std::map<std::string, std::vector<Product*>> carts; 
std::map<std::string, std::set<Product*>> keywords; 
std::vector<Product*> recentSearches; 


};
#endif