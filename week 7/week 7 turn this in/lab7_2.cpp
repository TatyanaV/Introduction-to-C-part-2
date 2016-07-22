#include<fstream>
#include<iostream>
#include<string>
using namespace std;

void sortTwoFiles(ifstream& in1, ifstream& in2, ofstream& out);

int main(){
    ifstream inFile1;
    ifstream inFile2;
    ofstream outFile;
    string inFileName1;
    string inFileName2;
    string outFileName;
    //promps the user to enter the name of the 2nd inut file
    cout << "Please enter the name of the 1st file: ";
    getline(cin,inFileName1);
    inFile1.open(inFileName1.c_str());
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
    while(inFile2.fail())
    {
        inFile2.clear();
        cout<<"Incorrect filename, please enter again: ";
        getline(cin,inFileName2);
        inFile1.open(inFileName2.c_str());
    }

    //prompst the user to enter the name of the output file
    cout << "Please enter the name of the output file \n";
    cout << "The name of the output file HAS to be DIFFERENT from \n"
        << "names of the input files: ";
    do{
    getline(cin,outFileName);
    } while(outFileName==inFileName1 || outFileName==inFileName2);
    outFile.open(outFileName.c_str());

    while(outFile.fail())
    {
        outFile.clear();
        cout<<"Incorrect filename, please enter again: ";
        getline(cin,outFileName);
        outFile.open(outFileName.c_str());
    }

    //call the sort function to sort the input files
    sortTwoFiles(inFile1,inFile2,outFile);
    cout<< "End of the program" <<endl;
    cout<< "Ouput file is saved in the same directore of the input files." <<endl;
    //close all the files
    inFile1.close();
    inFile2.close();
    outFile.close();
  //  cout<< "End of the program";
    return 0;

}

// the following function accepts 2 input sorted files
//and outputs 3rd SORTED file

void sortTwoFiles(ifstream& in1, ifstream& in2, ofstream& out){
    //variables
    int integer1;
    int integer2;
    //get the starting integer from each inout file
    in1 >> integer1;
    in2>> integer2;
    //varify whether any of the files is eaches its ened
    while(!in1.eof()&& !in2.eof()){
        //verify whethe the integer in the 1st file is less than
        //or equil to the integer in the second file
        if (integer1 <= integer2){
            //if the integer in the 1st file is less than ir equil to the
            //integer in the 2nd file, then sore the integer
            //of the first input file into the output file and read its next integer
            out << integer1<<endl;
            in1>>integer1;
        }
        else{
            //if integer of the 2nd file if > than the integer of the 1t file
            //then display the integer of the 2nd input file into the output file and read
            //its next integer
            out <<integer2<<endl;
            in2>>integer2;
        }
    }
    //store the integers reamianing in either
    //the 1st or 2nd input files into the output
    //file
    //display the reamining integesr in the 2nd file
    if (integer1 <= integer2){
        while (!in2.eof()){
            out <<integer2<< endl;
            in2 >> integer2;
        }
    }
    //display the reaminining integer in the 1st file
    else{
        while(!in1.eof()){
            out<<integer1<<endl;
            in1>>integer1;
        }
    }
}
