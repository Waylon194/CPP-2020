#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream  fileStream("Exercise3_5.txt");
    char character;
    int count = 0;
    while(fileStream)
    {
        fileStream.get(character);
        if((character > 63 && character < 91) || (character > 96 && character < 123))
            count++;
    }
    cout << "Characters in Exercise3_5.txt: " << count;
}