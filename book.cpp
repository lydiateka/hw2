#include "book.h"
#include "util.h"
#include <sstream>


using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string author, const std::string isbn) 
    : Product(category, name, price, qty), author_(author), isbn_(isbn)
{

}


std::string Book::getAuthor() const 
{
    return author_;
}

std::string Book::getIsbn() const
{
    return isbn_; 
}

std::set<std::string> Book::keywords() const{
    std::set<std::string> keywords; 
    std::set<std::string> product = parseStringToWords(name_); 

    keywords.insert(product.begin(), product.end()); 
    keywords.insert(isbn_);
    keywords.insert(author_); 

    return keywords; 
}

std::string Book::displayString() const{
    std::ostringstream os; 
    os << name_ << "\n" 
    << "Author: " << author_ << " ISBN: " << isbn_ 
    << "\n" << price_ << " " << qty_ << " left" << endl; 

    return os.str(); 
}

void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << isbn_ << "\n" << author_ << endl;
}




