#include <iostream>
#include <string>

// Return true if the card number is valid
bool isValid(const std::string& cardNumber);

// Get the result from Step 2
int sumOfDoubleEvenPlace(const std::string& cardNumber);

// Return this number if it is a single digit, otherwise,
// return the sum of the two digits
int getDigit(int number);

// Return sum of odd-place digits in the card number
int sumOfOddPlace(const std::string& cardNumber);

// Return true if substr is the prefix for cardNumber
bool startsWith(const std::string& cardNumber, const std::string& substr);

int main()
{
    /*
    std::cout << "Creditcardnumber:";
    std::string input;
    std::cin >> input;
    */

    std::string invalidNumber = "4388576018402626";
    std::string validNumber = "4388576018410707";

    if (isValid(invalidNumber))
    {
        std::cout << "Invalid number is valid\n";
    }
    else
    {
        std::cout << "Invalid number is invalid\n";
    }

    if (isValid(validNumber))
    {
        std::cout << "Valid number is valid\n";
    }
    else
    {
        std::cout << "Valid number is invalid\n";
    }
}

// Return true if the card number is valid
bool isValid(const std::string& cardNumber)
{
    //If not starts <- Etienne
    if (startsWith(cardNumber, "4") || startsWith(cardNumber, "5") || startsWith(cardNumber, "37") || startsWith(cardNumber, "6"))
    {
        int sum = sumOfDoubleEvenPlace(cardNumber) + sumOfOddPlace(cardNumber);

        if (sum % 10 == 0)
        {
            return true;
        }
    }
    return false;
}

// Get the result from Step 2
int sumOfDoubleEvenPlace(const std::string& cardNumber)
{
    int sum = 0;

    for (int i = 0; i < cardNumber.length(); i += 2)
    {
        char character = cardNumber[i];
        int number = (int)character - '0'; // Removed Ascii offset
        number *= 2;
        sum += getDigit(number);
    }
    return sum;
}

// Return this number if it is a single digit, otherwise,
// return the sum of the two digits
int getDigit(int number)
{
    if (number < 10)
    {
        return (number % 10) + 1;
    }
    return number;
}

// Return sum of odd-place digits in the card number
int sumOfOddPlace(const std::string& cardNumber)
{
    int sum = 0;

    for (size_t i = 1; i < cardNumber.length(); i += 2)
    {
        char character = cardNumber[i];
        int number = (int)character - '0'; //Removed Ascii offset
        sum += getDigit(number);
    }
    return sum;
}

// Return true if substr is the prefix for cardNumber
bool startsWith(const std::string& cardNumber, const std::string& substr)
{
    for (size_t i = 0; i < substr.length(); i++)
    {
        if (cardNumber[i] == substr[i])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}