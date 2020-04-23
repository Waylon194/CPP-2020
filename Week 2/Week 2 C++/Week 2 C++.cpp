#include <iostream>
#include "StopWatch.h"
#include <vector>
#include <algorithm>

#define numberamount 100000

bool isPalindrome(const std::string& s);

int main()
{
    // Stopwatch
    /*
    int ints[numberamount];
    std::vector<int> numbers(ints, ints + numberamount);
    StopWatch stopwatch;
    stopwatch.start();
    std::sort(numbers.begin(), numbers.end());
    stopwatch.stop();
    std::cout << "Sorting 100000 numbers took: " << stopwatch.getElapsedTime().count();
    */

    /* Genome */
    /*
    std::string beginTriplet = "ATG";
    std::vector<std::string> endingTriplets = { "TAG", "TTA", "TGA" };

    //std::cout << "Please enter a genome:\n";
    std::string input = "TTATGTTTTAAGGATGGGGCGTTAGTT";
    std::cout << "Input: " + input + '\n';
    //std::cin >> input;

    std::string start = "";
    std::string found = "";
    std::string end = "";
    bool endFound = false;

    for (std::string::iterator it = input.begin(); it != input.end(); ++it)
    {
        if (!endFound)
        {
            start += *it;

            if (start.length() > 3)
            {
                start.erase(0, 1);
            }

            if (start.length() == 3)
            {
                int boo = start.compare(beginTriplet);

                if (boo == 0)
                {
                    endFound = true;
                }
            }
        }
        else
        {
            found += *it;

            if (end.length() == 3)
            {
                bool print = false;
                for (size_t i = 0; i < endingTriplets.size(); i++)
                {
                    if (end.compare(endingTriplets[i]) == 0)
                    {
                        found = found.substr(0, found.length() - 3);
                        std::cout << found << '\n';
                        print = true;
                        break;
                    }
                }

                if (print)
                {
                    start.clear();
                    found.clear();
                    end.clear();
                    endFound = false;
                }
                else
                {
                    end.erase(0, 1);
                    end += *it;
                }
            }
            else
            {
                end += *it;
            }
        }
    }
    */

    std::cout << "Please enter a palindrome:\n";
    std::string input;
    std::cin >> input;

    if (isPalindrome(input))
    {
        std::cout << "Given input is a palindrome!";
    }
    else
    {
        std::cout << "Given input is not a palindrome!";
    }
}

bool isPalindrome(const std::string & s)
{
    for (size_t i = 0; i < s.length() / 2; i++)
    {
        if (tolower(s.at(i)) == tolower(s.at(s.length() - 1 - i)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}