#include<iostream>
#include<fstream>
using namespace std;

string fileName;
void countVowels(string fileName);

int main()
{
    std::cout << "Give a file name (without the .txt extension):";
    std::cin >> fileName;

    countVowels(fileName + ".txt");
}

void countVowels(string fileName)
{
    ifstream fileInput(fileName);
    char character;
    int characterCount = 0;

    /*
        Beter uitwerking (Python)
        print(*map(mystr.lower().count, "aeiou"))
    */

    while (!fileInput.eof())
    {
        fileInput.get(character);
        if (isalpha(character))
        {
            switch (character)
            {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
            case 'i':
            case 'I':
                characterCount++;
                break;
            }
        }
    }
    fileInput.close();
    cout << "There are " << characterCount - 1 << " vowels in given file.";
}