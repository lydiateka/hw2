#include "clothing.h"
#include "util.h"
#include <sstream>

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string brand, const std::string size) 
    : Product(category, name, price, qty), brand_(brand), size_(size)
{
    
}

std::string Clothing::getBrand() const
{
    return brand_; 
}

std::string Clothing::getSize() const 
{
    return size_;
}



std::set<std::string> Clothing::keywords() const{
    std::set<std::string> keywords; 
    std::set<std::string> product = parseStringToWords(name_); 
    keywords.insert(product.begin(), product.end()); 

    std::set<std::string> brandWords = parseStringToWords(brand_); 
    keywords.insert(brandWords.begin(), brandWords.end());

    std::set<std::string> sizeWords = parseStringToWords(size_);
    keywords.insert(sizeWords.begin(), sizeWords.end()); 

    return keywords; 
}

std::string Clothing::displayString() const{
    std::ostringstream os; 
    os << name_ << "\n" 
    << "Size: " << size_ << " Brand: " << brand_ 
    << "\n" << fixed << setprecision(2) << price_ << " " << qty_ << " left."; 
    
    return os.str(); 
}

void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << fixed << setprecision(2) << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}




