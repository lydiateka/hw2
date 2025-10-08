#include "movie.h"
#include "util.h"
#include <sstream>


using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) 
    : Product(category, name, price, qty), genre_(genre), rating_(rating)
{

}


std::string Movie::getGenre() const 
{
    return genre_;
}

std::string Movie::getRating() const
{
    return rating_; 
}

std::set<std::string> Movie::keywords() const{
    std::set<std::string> keywords; 
    std::set<std::string> product = parseStringToWords(name_); 

    keywords.insert(product.begin(), product.end()); 
    keywords.insert(genre_);
    keywords.insert(rating_); 

    return keywords; 
}

std::string Movie::displayString() const{
    std::ostringstream os; 
    os << name_ 
    << "\n" << "Genre: " << genre_ << "\n" << "Rating: " << rating_ 
    << "\n" << price_ << " " << qty_ << " left" << endl; 

    return os.str(); 
}

void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << genre_ << "\n" << rating_ << endl;
}




