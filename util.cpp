#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{

    std::set<std::string> keywords; 
    stringstream ss(rawWords);
    std::string word, temp_word; 

    // Read in each word from the string 
    while (ss >> word) { 
        for (size_t i = 0; i < word.length(); i++) {
            char letter = word[i]; 
            
            // If the current character is punctuation, only add it to the keywords if it is greater than 2 characters 
            if (ispunct(letter)) { 
              if (temp_word.length() >= 2) { 
                    keywords.insert(convToLower(temp_word)); 
              }
              // Reset for next word 
              temp_word.clear(); 
            } 
            // Otherwise, Add the next characters 
            else { 
                temp_word += letter; 
            }
        } 
        
        // Check if there are any valid words remaining
        if (temp_word.length() >= 2) { 
            keywords.insert(convToLower(temp_word)); 
            temp_word.clear(); 
        }
    }
    return keywords; 

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
