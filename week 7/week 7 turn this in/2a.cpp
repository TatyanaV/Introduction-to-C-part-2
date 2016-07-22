//lab 7
//problem 2
// tatyana vlaskin
// need to input 2 files with sorted numbers. 2 files 2a.txt and 2b.txt are submitted as well
//

#include<iostream>
#include<fstream>
#include<string>
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;
using std::endl;


//function to sort the numbers from the two inout files
//and output them in the 3rd file
void sortOutputFile(ifstream& in1,ifstream& in2, ofstream& out) ;

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

//function to sort the numbers from the two inout files
//and output them in the 3rd file
void sortOutputFile(ifstream& in1,ifstream& in2,ofstream& out){
    float array[4000]={0}; // creating an array and initalizing it to 0
    int index;
    //http://hardforum.com/showthread.php?t=839440
    //take numebers from files 1 and 2 and put them in the array
    while(!in1.eof()){
        in1>>array[index++];
    }
    while(!in2.eof()){
        in2>>array[index++];
    }
    int lastElementToOutput = index-1;
    //sort the array  of fumbers
    for (int indexLower = 0; indexLower < lastElementToOutput -1; indexLower++){
        for (int indexHigher = indexLower+1; indexHigher <lastElementToOutput; indexHigher ++){
            if (array[indexLower] > array[indexHigher]){// if number at the lower index # is smaller, swap values
                 float temp = array[indexLower];
                 array[indexLower]= array[indexHigher];
                 array[indexHigher] = temp;
            }
        }
    }
    //output sorted array in the output file
    for(int i=0;i<lastElementToOutput;i++)
    out<< array[i] << "\n";

}
