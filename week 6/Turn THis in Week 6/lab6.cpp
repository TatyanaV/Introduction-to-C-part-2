//tatyana vlaskin
//lab 6
//name: lab6.cpp
 #include<iostream>
 #include <cstdlib>
 #include<ctime>

using std::cin;
using std::cout;
using std::endl;

class Dice
{
    public:
        Dice();
        Dice( int numSides);
        Dice(int numSides1, int numSides2);
        virtual int rollDice() const;
        //void Message();
        int rollDiceBiased() const;
        void setNumSides1(int numSides1new){numSides1=numSides1new;}
        void setNumSides2(int numSides2new){numSides2=numSides2new;}
        int getNumSides1(){return numSides1;}
        int getNumSides2(){return numSides2;}

    protected:
        int numSides;
        int numSides1;
        int numSides2;
};
    Dice::Dice()
    {
        numSides = 6;
        numSides1 =0;
        numSides2 =0;
        srand(time(NULL)); // Seeds random number generator
    }
    Dice::Dice(int numSides)
    {
        this->numSides = numSides;
        srand(time(NULL)); // Seeds random number generator
    }
        Dice::Dice(int numSides1, int numSides2)
    {
        this->numSides1 = numSides1;
        this->numSides2 = numSides2;
        srand(time(NULL)); // Seeds random number generator
    }
    int Dice::rollDice() const
    {
        return (rand() % numSides) + 1;
    }
    // Take two dice objects, roll them, and return the sum
    int rollTwoDice(const Dice& die1, const Dice& die2)
    {
        int roll1 = die1.rollDice();
        int roll2 = die2.rollDice();
        cout << roll1 << " + " << roll2 << " = ";
        return roll1 + roll2;
        //return die1.rollDice() + die2.rollDice();
    }

    int Dice::rollDiceBiased() const{
            //((max - min) + 1) + min;
            return (rand() % ((numSides2 - numSides1)+1) +numSides1);
    }

        // Take two dice objects, roll them, and return the sum
    int rollTwoDiceBiased(Dice& die1, Dice& die2)
    {

        int roll1 = die1.rollDiceBiased();
        int roll2 = die2.rollDiceBiased();
        cout << roll1 << " + " << roll2 << " = ";
        return roll1 + roll2;
    }
//Next create your own class, LoadedDice , that is derived from Dice . Add a default constructor
//and a constructor that takes the number of sides as input. Override the rollDice function in
//LoadedDice so that with a 50% chance the function returns the largest number possible (i.e.,
//numSides ), otherwise it returns what Dice’s rollDice function returns.
class LoadedDice: public Dice{
    public:
        //Constructor
        LoadedDice();
        LoadedDice(int numSides);//takes the number of sides as input.
        virtual int rollDice() const;
    private:
        int numSides;
};

LoadedDice::LoadedDice(int numSides){
    this->numSides = numSides;
    srand(time(NULL));
}
//override the rollDice function in the LoadedDice
//so that with a 50% chance the function
//returns the largers number possible
//otherwise it returns
//Dice's rollDice function return.

int LoadedDice::rollDice() const {
    if ((rand()%100 +1) >50){
        return (rand()%numSides) +1;
    }
    else{
        return numSides;
    }
}

//main function that creats 2 Dice objects with
//number of sides of your choice

int main(){
     //create 2 Dice objects with a number of sides of my choosing
    //size 8 amd size 30
    Dice die1(8), die2(30);
    // Take two dice objects, roll them, and return the sum
    //Invoke the rollTwoDice function in a loop that iterates ten
    //times and verify that the functions are working as expected.
    cout<< "Parent dice: " <<endl;
    //roll both dice 10 times
    for (int i = 0; i <10; i++){
        cout << " roll " << i+1 << ": ";
        cout << rollTwoDice(die1,die2) <<" ";
        cout<<endl;
    }
    cout <<endl;

    //creat 2 loaded dice
    LoadedDice loadedDie1(8), loadedDie2(30);
    cout<<"Loaded Child dice: " <<endl;
    //roll both dice 10 times
    //so that with a 50% chance the function returns the largest number possible (i.e.,
    //numSides ), otherwise it returns what Dice’s rollDice function returns.
    for (int i =0; i<10; i++){
        cout <<" roll " << i+1 << ": ";
        cout<<rollTwoDice(loadedDie1,loadedDie2)<<" ";
         cout <<endl;
    }
    cout <<endl;
    cout<<"Biased dice: " <<endl;
    //Dice Die1(8), Die2(30);
    int number1, number2;
   // Dice Die1(number1, number2), Die2(number1, number2);
    cout << "Please specify low bias for dice roll: " ;
    cin >> number1;
//    Die1.setNumSides1(number1);
    /// it seems that my get/set function do not work as expected
    //cout<< Die1.getNumSides1() <<endl; ///THIS IS HERE FOR DEBUGGIN,  PROBLEM IS HERE, I GET SOME RANDOME VALUE FOR NumberSides1.
   // Die2.setNumSides1(number1);
   // cout<< Die1.getNumSides2() <<endl;
    cout <<"Please specify high bias for dice roll: " ;
    do{
    cin>>number2;
    }while (number1>=number2);
//    Die1.setNumSides2(number2);
   //Die2.setNumSides2(number2);
    ////////////////////////////////////////////////////////////////////
    Dice Die1(number1, number2), Die2(number1, number2);
   // cout<< Die1.getNumSides1() <<endl;
    //cout<<Die1.getNumSides2() <<endl;


    for (int i =0; i<10; i++){
        cout <<" roll " << i+1 << ": ";
        cout<<rollTwoDiceBiased( Die1, Die2)<<" ";
        cout <<endl;
    }


    //pause the system for a while
  // system ("PAUSE");
    return 0;
}
