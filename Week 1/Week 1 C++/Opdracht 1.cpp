#include <iostream>

bool search(std::string& s, char& key);

int main()
{
    std::string input;
    std::cout << "Give a input string: ";
    std::cin >> input;

    char searchChar;
    std::cout << "Give a character to find: ";
    std::cin >> searchChar;

    if (!search(input, searchChar)){
        std::cout << "Letter has not been found!";
    }
    else {
        std::cout << "Letter has been found!";
    }
}

bool search(std::string& s, char& key){
    if (s.find(key)<s.length()) {
        return true;
    }
    return false;
}