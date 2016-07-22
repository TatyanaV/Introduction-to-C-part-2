//tatyana vlaskin
//lab 9
//problem 1
//1.cpp
//FOR SOME REASON IT DOES NOT WORK ON THE FLIP
//IT WORKS FINE ON MY COMPUTER, WHERE I USE CODE::BLOCKS
#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Car{
public:
	int arrivalTime;
	Car (int arrivalT = 0) : arrivalTime (arrivalT) {} // default constructor
	// ordering all the cars in the lane by arrival time
	bool operator < (const Car& car) const {
        return arrivalTime < car.arrivalTime;
    }
};

class TrafficLight{
public:
	TrafficLight (): status (true) {}
	// checks if the light is green
	bool isGreen( ){
		if (status)
		return true;
    }
    //checks if the light is red
	bool isRed( ) {
		if(!status)
		return true;
    }
	//going to the next car
    void addCar (const Car &car1) {
        car = car1;
        status = !status;
        if (status){
            cout<< "the light turned green" <<endl;
        }
        else {
            cout << "the light turned red" << endl;
        }
    }
	// function to toggle the light
    void toggleLight(){
            status= !status;
    }
private:
	bool status;
	Car car;
};

int main (){

    srand (time(NULL));
    double numberOfMinutes = 0;// simulations minutes
    double totalWait1 = 0;//wait time in lane 1
    double totalWait2 = 0;//wait time in lane 2
    int numberOfCars1 = 0; // cars in lane 1
    int numberOfCars2 = 0; // cars in lane 2

    TrafficLight light1;
    TrafficLight light2;
    queue<Car> lane1;
    queue<Car> lane2;

    cout<<"Enter the simulation time: "<<flush;
    cin>>numberOfMinutes;
    cout<<endl;

        //randomly genearte which light is red and which light is green
        //initial condition
            if(rand()%3+1 <1){
                cout<< "light 1 will be red and light 2 will be green" <<endl;
                light1.isRed();
                light2.isGreen();
            }
            else if (rand()%3+1 <2){
                cout<< "light 2 will be red and light 1 will be green" <<endl;
                light2.isRed();
                light1.isGreen();
            }
            else{
                cout<< "Both lights will be red" <<endl;
                light2.isRed();
                light1.isRed();
            }


    for (int time = 0; time < numberOfMinutes; time++) {
        // As the cars arrive they are randomly palced into one of the queues
        if (rand()%2 < 1 ){// rand()%2 means random number between 0 and 1, 	thus each lane has 50% chance of getting a car
            cout << endl <<"One car was added to the lane 1. " << endl;
            lane1.push (Car (time)); // we generate number of cars. We add 		elements to the back of the queue
        }
        else{
            cout << endl<<"One car was added to the lane 2. " << endl;
            lane2.push (Car (time));
        }

        //this part checks the red red function and toggle any of the lights
        if (light1.isRed()&&light2.isRed()){
            cout <<"Both lights are red" <<endl;
            if(rand()%2 <1){
                light1.toggleLight();
                cout<< "Light 1 turned green" <<endl;
            }
            else{
                light2.toggleLight();
                cout<< "Light 2 turned green" <<endl;
            }
        }

            cout << "size of the 1st lane: "<< lane1.size() <<endl;
            cout << "Size of the 2nd lane: " << lane2.size()<<endl;


            if (light1.isGreen () && light2.isRed () && lane1.empty ()) {
                cout <<endl<<"Light 1 is green and light 2 is red" <<endl;
                cout<<"Lane 1 is EMPTY"<<endl;
                light1.toggleLight();// change the light of light 1
                light2.toggleLight();//change the light of light 2
            }

            if (light1.isGreen () && light2.isRed () && !lane1.empty ()) {
                cout <<endl<<"Light 1 is green and light 2 is red" <<endl;
                Car &frontCar1 = lane1.front ();//returns a mutable reference to the front member in the queue
                numberOfCars1++;// goes to the next car
                cout <<"Car from lane 1 enteres the freeway" <<endl;
                totalWait1 += time - frontCar1.arrivalTime; //calculates total wait time of the ca
                cout << "Next car (if there is one) is moved to the front of the lane 1. " <<endl;
                light1.addCar (frontCar1); // goes to the next car in the queue
                lane1.pop (); // removes the car from the beggining of the lane
                cout << "size of the 1st lane: "<< lane1.size() <<endl;
                cout << "Size of the 2nd lane: " << lane2.size()<<endl;
                light1.toggleLight();// change the light of light 1
                light2.toggleLight();//change the light of light 2
            }

            if (light2.isGreen () && light1.isRed () && lane2.empty ()) {
               cout <<endl<<"Light 2 is green and light 1 is red" <<endl;
               cout<<"Lane 2 is EMPTY"<<endl;
                light2.toggleLight();//change the light of light 2
                light1.toggleLight();//change the light of light 1
            }

            if (light2.isGreen ()&& light1.isRed () && !lane2.empty ()) {
                cout <<endl<<"Light 2 is green and light 1 is red" <<endl;
                Car &frontCar2 = lane2.front ();//returns a mutable reference to the front member in the queue
                numberOfCars2++;// goes to the next car
                cout << "Car from lane 2 enteres the freeway" <<endl;
                totalWait2 += time - frontCar2.arrivalTime; //calculates total wait time of the car
                cout << "Next car (if there is one) is moved to the front of the lane 2. " <<endl;
                light2.addCar (frontCar2); // goes to the next car in the queue
                lane2.pop (); // removes the car from the beggining of the lane
                cout << "size of the 1st lane: "<< lane1.size() <<endl;
                cout << "Size of the 2nd lane: " << lane2.size()<<endl;
                light2.toggleLight();//change the light of light 2
                light1.toggleLight();//change the light of light 1
        }

    }
    cout<< "total # of cars that went through 1st light: " <<numberOfCars1<<endl;
    cout <<"wait tim:" << totalWait1<<endl;
    cout << "average wait of the 1st light: " << (totalWait1 / static_cast<int>(numberOfCars1)) << std::endl;
    cout<< "total # of cars that went through 2nd light: " <<numberOfCars2<<endl;
    cout << "average wait of the 2nd light: " << (totalWait2 / static_cast<int>(numberOfCars2)) << std::endl;
}
