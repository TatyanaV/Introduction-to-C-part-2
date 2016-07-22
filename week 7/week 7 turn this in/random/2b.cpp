//lab 7
//problem 2
// tatyana vlaskin
// need to input 2 files with sorted numbers. 2 files 2a.txt and 2b.txt are submitted as well
//name 2b.cpp
// THIS IS A SECOND VERSION OF MY PROGRAM
// IT DOES NOT

#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::endl;


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
  //  cout<< "End of the program";
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
	bool theend = false;
	bool eof1used = false;
	bool eof2used = false;
	while(!theend)
	{
	    //if the # in file 1 is larger than # in file 2
	    //end is not reached in both files
		if(number1 <= number2 && !in1.eof() && !in2.eof()){
			out << number1 << endl;
			in1 >> number1;
		}
        //if the # in file 2 is larger than # in file 1
	    //end is not reached in both files
		else if(number1 > number2 && !in1.eof() && !in2.eof()){
			out << number2 << endl;
			in2 >> number2;
		}

        //if we reached the end of file of 1, but not file 2
		else if(in1.eof() && !in2.eof()){
			if(number1 <= number2 && !eof1used){
				out << number1 << endl;
				eof1used = true;
				out << number2 << endl;
				in2 >> number2;
				if(in2.eof())
					out << number2 << endl;
			}
			else{
				out << number2 << endl;
				in2 >> number2;
				if(in2.eof())
                out << in2 << endl;
			}
		}
    //if we reached the end of file of 2, but not file 1
		else if(in2.eof() && !in1.eof()){
			if(number2 <= number1 && !eof2used)	{
				out << number2 << endl;
				eof2used = true;
				out << number1 << endl;
				in1 >> number1;
				if(in1.eof())
                    out << number1 << endl;
			}
			else{
				out  << number1 << endl;
				in1 >> number1;
				if(in1.eof())
					out << number1 << endl;
			}
		}

		else
			theend = true;
	}
}













