#include <iostream>

int asciiOffset = 97;
void count(const char s[], int counts[]);

int main(){
    while (true){
        int counts[26];

        for (int i = 0; i < sizeof(counts) / sizeof(counts[0]); i++){
            counts[i] = 0;
        }

        std::cout << "Geef een zin:\n";
        char input[100];
        std::cin.getline(input, sizeof(input));

        const char* str = &input[0];
        count(str, counts);
    }
}

void count(const char s[], int counts[]){
    char str[100];

    for (int i = 0; i < strlen(s); i++){
        str[i] = tolower(s[i]);
    }

    //Get index of letter and add 1 to the array;
    for (int i = 0; i < strlen(str); i++){
        //putchar(tolower(s[i]));
        char letter = str[i];
        int asciiValue = ((int)letter) - asciiOffset;
        counts[asciiValue] += 1;
    }

    for (int i = 0; i < 26; i++){
        if (counts[i] != 0){
            std::cout << (char)(asciiOffset + i) << ": " << counts[i] << " times\n";
        }
    }
}