#include<iostream>
#include<fstream>

using namespace std;

void Function(ifstream& instream1,ifstream& instream2, ofstream& outstream) ;

int main()

{

    ifstream inFile1;
    ifstream inFile2;
    ofstream outFile;
    string inFileName1;
    string inFileName2;
    string outFileName;
    //promps the user to enter the name of the 1st input file
    cout << "Please enter the name of the 1st file: ";
    getline(cin,inFileName1);
    inFile1.open(inFileName1.c_str());
    //if there was a problem opening the file, the user is asked to reenter the name
    while(inFile1.fail()){
        inFile1.clear();
        cout<<"Incorrect filename, please enter again: ";
        getline(cin,inFileName1);
        inFile1.open(inFileName1.c_str());
    }

    //promps the user to enter the name of the 2nd inut file
    cout << "Please enter the name of the 2nd file: ";
    getline(cin,inFileName2);
    inFile2.open(inFileName2.c_str());
    //if there was a problem opening the file, the user is asked to reenter the name
    while(inFile2.fail()) {
        inFile2.clear();
        cout<<"Incorrect filename, please enter again: ";
        getline(cin,inFileName2);
        inFile1.open(inFileName2.c_str());
    }

    //prompst the user to enter the name of the output file
    //the name of the output file cannot be the
    //same as the names of the input files
    cout << "Please enter the name of the output file \n";
    cout << "The name of the output file HAS to be DIFFERENT from \n"
        << "names of the input files: ";
    do{
    getline(cin,outFileName);
    } while(outFileName==inFileName1 || outFileName==inFileName2);
    outFile.open(outFileName.c_str());
    ////if there was a problem opening the file, the user is asked to reenter the name
    while(outFile.fail()){
        outFile.clear();
        cout<<"Incorrect filename, please enter again: ";
        getline(cin,outFileName);
        outFile.open(outFileName.c_str());
    }

Function(inFile1,inFile2,outFile);

    inFile1.close();
    inFile2.close();
    outFile.close();

}

void Function(ifstream& instream1,ifstream& instream2,ofstream& outstream)

{

int size,array[40],i=0;

while(!instream1.eof())

{

instream1>>array[i];

i++;

}

while(!instream2.eof())

{

instream2>>array[i];

i++;

}

size=i;

bool swap;

int temp;

do

{

swap = false;

for (int count = 0; count < (size - 1); count++)

{

if (array[count] > array[count + 1])

{

temp = array[count];

array[count] = array[count + 1];

array[count + 1] = temp;

swap = true;

}

}

} while (swap);

for(int i=0;i<size;i++)

outstream<<array[i];

}
