#include<fstream>
#include<iostream>
#include<string>
using namespace std;

void sortOutputFile(ifstream& input1, ifstream& input2, ofstream& output);

int main(){
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
    while(inFile1.fail())
    {
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
    while(inFile2.fail())
    {
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
    while(outFile.fail())
    {
        outFile.clear();
        cout<<"Incorrect filename, please enter again: ";
        getline(cin,outFileName);
        outFile.open(outFileName.c_str());
    }

    //call the sortOutputFile that takes 2 input files
    // with the list of sorted numbers
    //and returns 3rd file with all the numbers in the 2 input files
    //sorted from the smallerst to the largest.
    sortOutputFile(inFile1,inFile2,outFile);
    cout<< "End of the program" <<endl;
    cout<< "Ouput file is saved in the same directore as the input files." <<endl;
    //close all the files
    inFile1.close();
    inFile2.close();
    outFile.close();
    return 0;

}

// the following function accepts 2 input sorted files
//and outputs 3rd SORTED file

void sortOutputFile(ifstream& in1, ifstream& in2, ofstream& out){
    //variables
    float number1;
    float number2;
    //inputs 1st number from the 1st file and 2end file
    in1 >> number1;
    in2 >> number2;
    //verification that end of the file was not reached
    while(!in1.eof()&& !in2.eof()){
        if (number1 <= number2){// number in the 1st file is smaller
            out << number1<<endl;//output the number in the output file
            in1>>number1;// go to the next number in the 1st file
        }
        else{// number is the 2nd file is smaller
            out <<number2<<endl; //output the number in the output file
            in2>>number2; //go to the next number in the 2nd file
        }
    }

    //display the reamining numbers in the 1st file if the number is smaller
    //than the # in the second file
    //and displaying last value in the 2nd file
    if (number1 <= number2){
        while (!in1.eof()){
            out <<number1<< endl;
            in1 >> number1;
            out<<number2<<endl;
        }
    }
    //display the reaminining integer in the 2st file if the number is smaller
    //than the # in the 1st file
     //and displaying last value in the 1st file
    else{
        while(!in2.eof()){
            out<<number2<<endl;
            in2>>number2;
            out<<number1<<endl;
        }
    }



}



