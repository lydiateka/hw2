#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"

class Clothing : public Product { 
    public:
    Clothing(const std::string category, const std::string name, double price, int qty, const std::string brand, const std::string size);
    std::string getSize() const; 
    std::string getBrand() const; 
    std::set<std::string> keywords() const; 
    std::string displayString() const; 
    void dump(std::ostream& os) const; 
    

protected: 
std::string brand_; 
std::string size_; 

};

#endif 

