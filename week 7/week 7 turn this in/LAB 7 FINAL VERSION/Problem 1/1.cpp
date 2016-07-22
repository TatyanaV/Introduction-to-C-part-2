//lab 7
//tatyana vlakin
//problem 1
//name 1.cpp
//input: you need to input file 1.txt that is submitted as well

#include<fstream>
#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::endl;
//using namespace std;

int main()
{
    ifstream inFile; //Declares a file stream object
    string fileName;
    cout << "Please enter the file name ";
    getline(cin,fileName);
    inFile.open(fileName.c_str());
    while(inFile.fail())
    {
        inFile.clear();
        cout<<"Incorrect filename, please enter again: ";
        getline(cin,fileName);
        inFile.open(fileName.c_str());
    }
    char character;
    int countWord = 0;
    int countCharacter = 0;
    int countPunctuation =0;
    while(!inFile.eof())
    {
        inFile.get(character);
        //counting characters , every character will be counted
        //WHITE SPACE is NOT concidered to be a character
        if (character !=' ' ){
            countCharacter++;
            if(character == '\n'){// need to substract each new line from the count
                countCharacter--;
            }
        }
        // counting words
        // if the character is a letter and there is a whitespace
        //or new line after the character, it will be counted as a word
        char character2;
        character2 =inFile.peek();
        if((isalpha(character) && character2 == ' ') || (isalpha(character) && character2 == '\n')){
            countWord++;
        }

        //counting ! . , ?
        //please note that only above mentioned charactes will be counted
        //if there is any other charactes present they will be ignored
        if(character == '!' || character == '.' || character == ',' || character == '?'){
            countPunctuation++;
        }
    }
    cout << "Number of characters in the file is " << countCharacter << endl;
    cout << "Number of special charactes (! . , ?) in the file is " << countPunctuation <<endl;
    cout << "Number of words in the file is " << countWord;
    inFile.close();

    cin.get();
    return 0;
}
