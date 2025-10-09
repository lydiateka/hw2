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

    std::set<std::string> genreWords = parseStringToWords(genre_); 
    keywords.insert(genreWords.begin(), genreWords.end());

    std::set<std::string> ratingWords = parseStringToWords(rating_);
    keywords.insert(ratingWords.begin(), ratingWords.end()); 

    return keywords; 
}

std::string Movie::displayString() const{
    std::ostringstream os; 
    os << name_ 
    << "\n" << "Genre: " << genre_ << " Rating: " << rating_ 
    << "\n" << fixed << setprecision(2) << price_ << " " << qty_ << " left."; 

    return os.str(); 
}

void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << fixed << setprecision(2) << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}




