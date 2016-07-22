
/************************************************
** Tatyana Vlaskin
** Lab 4
** name: lab4.cpp
** Description:
**This program has a class named Vector2D that stores information about a two-dimensional
**vector. The class have functions to get and set the x and y components, where x and y are
**integers.
**The class has a function that overload the * operator so that it returns the dot product of two vectors.
**The dot product of two-dimensional vectors A and B is equal to (A x * B x ) + (A y * B y ).
**The class has also have a function that overloads the + operator so that it performs
**vector addition. Vector adition is calculated as:  C = A + B. C would be (A x + B x ) , (A y + B y ).
**Finally, main functions test the tests the * operation and the + operation.

**Input:
** User needs to input x and y coordinates for vector A and vector B. Only integers are accepted.
** In any another time is entered, the program will demonstrate unpredicatble behaivor, including infinite loop
*************************************************/

#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::cin;

class Vector2D{
    private:
        int x;
        int y;
    public:
        Vector2D();//default constructor
        Vector2D(int x, int y);//iniliatize to whateveer we want, will ne used in + operator overloading
        int getX()const;// we cannot mutate or change or mutate date in the class, that why we have const
        int getY()const;
        void setX(const int x);
        void setY(const int y);
        int operator*(const Vector2D& vector);
        Vector2D operator+(const Vector2D& vector);
        void display() {cout << "x = " << x << ", y = " << y << endl;}
};

/************************************************
** Constructor: Vector2D::Vector2D():x(0),y(0){}
** Description: default constructor, initiates elements to 0
*************************************************/
Vector2D::Vector2D():x(0),y(0){}

/************************************************
** Constructor: Vector2D::Vector2D(int x, int y): x(x), y(y){}
** Description: constructor, initiates elements to values indivated by the user
*************************************************/
Vector2D::Vector2D(int x, int y): x(x), y(y){}//iniliatize to whateveer we want, will ne used in + operator overloading

/************************************************
** Function: int Vector2D::getX() const{return x;}
** Description: gets value of X
*************************************************/

int Vector2D::getX() const{return x;}

/************************************************
** Function: int Vector2D::getY() const{return y;}
** Description: gets value of Y
*************************************************/

int Vector2D::getY() const{return y;}

/************************************************
** Function: void Vector2D::setX( const int xnew){ x=xnew;}
** Description: sets value of X
*************************************************/

void Vector2D::setX( const int xnew){ x=xnew;}

/************************************************
** Function: void Vector2D::setY( const int ynew){ y=ynew;}
** Description: sets value of y
*************************************************/

void Vector2D::setY( const int ynew){ y=ynew;}

/************************************************
** Function: int Vector2D::operator*(const Vector2D& vector)
** Description: overloads * operator to compute dot product between 2 vectors
** Integer is returned
*************************************************/

int Vector2D::operator*(const Vector2D& vector) {
  return (vector.x * x + vector.y * y);
}

/************************************************
** Function: Vector2D Vector2D::operator+(const Vector2D& vector){
** Description: overloads + operator to calculate vector addition
** Vector is returned
*************************************************/
 Vector2D Vector2D::operator+(const Vector2D& vector){
//Vector2D Vector2D::operator+(const Vector2D& vector){
    return Vector2D(x + vector.x, y + vector.y);
}

///MAIN METHOD
int main(){
    Vector2D A;
    int Xa, Ya;
    cout <<"Enter X coordinate of vector A: " ;
    cin >>Xa;// please enter ONLY INTEGERS
    A.setX(Xa);
    cout <<"Enter Y coordinate of vector A: " ;
    cin >>Ya;// please enter ONLY INTEGERS
    A.setY(Ya);
    cout << endl;
    Vector2D B;// please enter ONLY INTEGERS
    int Xb, Yb;
    cout <<"Enter X coordinate of vector B: " ;
    cin >>Xb;// please enter ONLY INTEGERS
    B.setX(Xb);
    cout <<"Enter Y coordinate of vector B: " ;
    cin >>Yb;// please enter ONLY INTEGERS
    B.setY(Yb);
    cout << endl<< "The dot product of vector A and B is: " << A.getX() << " * " << B.getX() <<" + " << A.getY() << " * " << B.getY()
    <<" = " << (A * B) << endl;
    cout << endl<< "The sum of vector A and vector B is: ";
    (A + B).display();
    return 0;
}
