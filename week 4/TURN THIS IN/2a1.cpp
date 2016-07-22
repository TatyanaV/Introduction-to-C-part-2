
/************************************************
** Assignment #2
** Tatyana Vlaskin
** name: 2a.cpp
*************************************************/

#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

//using namespace std;

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

/************************************************
** Function: void newLine()
** Description:Function taken from the book. Reads
all charactes untill it see new life
*************************************************/
void newLine();
/************************************************
** Function: int integerCheck (string INPUT
** Description:Function checks that valid integer was
entered. ONLY INTEGERS ARE ACCEPTED
*************************************************/
int integerCheck (string INPUT, int min, int max);
/************************************************
** Function: void validEntry(double &entry);
** Description:Function checks that valid number was
entered. BOTH INTEGERS AND FLOATS ARE ACCEPTED
*************************************************/
void validEntry(double &entry);

/************************************************
** Class: Item
** *************************************************/
class Item{
private:
	string name, location;
	double regularPrice, salePrice;
	int quantity;

public:
	Item(string name, string location, double regularPrice, double salePrice, int quantity)
	{
		this->name= name;
		this->location = location;
		this->regularPrice = regularPrice;
		this->salePrice = salePrice;
		this->quantity = quantity;
	}

/************************************************
** Function: string getName(){return name;}
** Description: gets product name
*************************************************/
string getName(){return name;}

/************************************************
** Function: string getLocation(){return location;}
** Description: gets location of the product
*************************************************/
string getLocation(){return location;}

/************************************************
** Function: double getRegularPrice(){return regularPrice;}
** Description: gets regular price of the product
*************************************************/
double getRegularPrice(){return regularPrice;}

/************************************************
** Function: 	double getSalePrice(){return salePrice;}
** Description: gets sales price of the product
*************************************************/
double getSalePrice(){return salePrice;}

/************************************************
** Function: 	int getQuantity(){return quantity;}
** Description: gets quantity of the product
*************************************************/
int getQuantity(){return quantity;}

/************************************************
** Function: 	void setName(string name){this->name = name;}
** Description: sets name of the product
*************************************************/
void setName(string name){this->name = name;}

/************************************************
** Function: 	void setLocation(string location){this->location = location;}
** Description: sets location of the prodcut
*************************************************/
void setLocation(string location){this->location = location;}

/************************************************
** Function: 	void setRegularPrice(double regularPrice){this->regularPrice = regularPrice;}
** sets regular price of the product
*************************************************/
void setRegularPrice(double regularPrice){this->regularPrice = regularPrice;}

/************************************************
** Function: void setSalePrice(double salePrice){this->salePrice = salePrice;}
** Description: sets sales price of the product
*************************************************/
void setSalePrice(double salePrice){this->salePrice = salePrice;}

/************************************************
** Function: 	void setQuantity(int quantity){this->quantity = quantity;}
** Description: sets quantity of the product
*************************************************/
void setQuantity(int quantity){this->quantity = quantity;}
};
/************************************************
** Function: void addProduct(vector<Item>&);
** Description: function to add the products
*************************************************/
void addProduct(vector<Item>&);

/************************************************
** Function: void deleteProduct(vector<Item>&);
** Description: function to delete the products
*************************************************/
void deleteProduct(vector<Item>&);

/************************************************
** Function: void displayList(vector<Item>&);
** Description: function to display the products
*************************************************/
void displayList(vector<Item>&);

/************************************************
** Function: void checkout(vector<Item>&);
** Description: function to checkout once
** the user is done. It will display the products
** by location, show the price of the transaction and
** total savings
*************************************************/
void checkout(vector<Item>&);

/************************************************
** Function: bool myfunction (Item i, Item j);
** Description: function will sort elements in the vector.
** sorting will be done alphabeticcally
*************************************************/
bool myfunction (Item item1, Item item2);


/************************************************
** Function: bool isValidLocation(const string& input)
** Description: function checks if the user entered
** valid location. List of the locations will
** be provided
*************************************************/
bool isValidLocation(const string& input);

/************************************************
** Function:  void displayListCategory(vector<Item>& groceryList){
** Description: function to display the products by the location that the user
** specifies
*************************************************/
void displayListCategory(vector<Item>&);

/************************************************
MAIN FUNCTION
*************************************************/
int main()
{

	vector <Item> groceryList;
	int choice;
	string entered;
	while(1){
	    cout << "WELCOME TO THE SHOLLING LIST PROGRAM!" << endl;
		cout << "--Please select option --" << endl;
		cout << "1. Add Item to list" << endl;
		cout << "2. Delete Item from list" << endl;
		cout << "3. Display the list" << endl;
		cout << "4. Display the list by location" << endl;
		cout << "5. Checkout" << endl;
        getline(cin,entered);
        choice = integerCheck(entered, 1, 5);
		cin.sync();
		switch (choice)
		{
		case 1:
			addProduct(groceryList);
			break;

		case 2:
			deleteProduct(groceryList);
			break;

		case 3:
            sort(groceryList.begin(),groceryList.end(),myfunction);// sort vector by location, alphabetically
			displayList(groceryList);
			break;
        case 4:
            displayListCategory(groceryList);
            break;
		case 5:
            sort(groceryList.begin(),groceryList.end(),myfunction);// sort vector by location, alphabetically
			checkout(groceryList);
			break;
		default:
			cout << "Invalid Option selected" << endl;
			break;
		}

		if(choice == 5)
			break;
	}
	return 0;
}

/************************************************
** Function: bool isValidLocation(const string& input)
** Description: function checks if the user entered
** valid location. List of the locations will
** be provided
*************************************************/

bool isValidLocation(const string& input) {

 string locationSore[14]={"MEAT","DAIRY","CONDIMENTS","SWEETS",
                        "PRODUCE","GRAINS","HEALTH","BEVERAGES","HYGIENE",
                        "FROZEN","BAREKY","BABY", "HOUSEHOLD",
                        " MISALENEOUS"};
      for(int i = 0; i < 14; ++i) {
          if(input == locationSore[i]) {
              return true;
          }
      }
      return false;
 }
/************************************************
** Function: void addProduct(vector<Item>&);
** Description: function to add the products
*************************************************/

void addProduct(vector<Item>& groceryList)
{
    string locationSore[14]={"MEAT","DAIRY","CONDIMENTS","SWEETS",
                        "PRODUCE","GRAINS","HEALTH","BEVERAGES","HYGIENE",
                        "FROZEN","BAREKY","BABY", "HOUSEHOLD",
                        "MISALENEOUS"};
	string name, location;
	double regularPrice, salePrice;
	int quantity;

	cout << "Enter Product name" << endl;
	getline(cin ,name);
	cout << "Enter Location of product" << endl;
	cout << "You can choose one of the following locations: " << endl;
	cout << "Only CAPITAL letters are accepted!!!" <<endl;
		for(int i = 0; i <14 ; i++){
	    cout<< 	locationSore[i];
	    cout << endl;
	   }
	    //http://stackoverflow.com/questions/7131858/stdtransform-and-toupper-no-matching-function
    do{
       getline(cin ,location);
      }while (!isValidLocation(location));
   	cout << "Enter regular Price" << endl;
	cin >> regularPrice;
	validEntry(regularPrice);
	cout << "Enter Sale Price" << endl;
	cin >> salePrice;
	validEntry(salePrice);
	cout << "Enter Quantity" << endl;
    newLine();
	string entered;
	//cin >> quantity;
    getline(cin,entered);
    quantity = integerCheck(entered, 1, 10);// user will not be allowed to buy more than 10 items of the same product
//	validEntry(quantity);

	groceryList.push_back(Item(name, location, regularPrice, salePrice, quantity));
}
/************************************************
** Function: void deleteProduct(vector<Item>&);
** Description: function to delete the products
*************************************************/
void deleteProduct(vector<Item>& groceryList)
{
	string pItem;

	cout << "Items in the list for deletion are" << endl;

	for(vector<Item>::iterator it = groceryList.begin(); it != groceryList.end(); ++it)
	{
		cout << it->getName() << endl;
	}

	cout << "Enter Item to delete " << endl;
	getline(cin, pItem);

	for(vector<Item>::iterator it = groceryList.begin(); it != groceryList.end(); ++it)
	{
		if(it->getName().compare(pItem) == 0)
        {
            groceryList.erase(it);
            cout << "Item deleted successfully" << endl;
            return;
        }
	}
	cout << "Invalid item entered" << endl;
}
/************************************************
** Function: void displayList(vector<Item>&);
** Description: function to display the products
*************************************************/
void displayList(vector<Item>& groceryList)
{
	cout << "Items in the list are: " << endl;
	cout << "---------------------------------" << endl;

	for(vector<Item>::iterator it = groceryList.begin(); it != groceryList.end(); ++it)
	{
		cout << "Product Location: " << it->getLocation() << endl;
		cout << "Product Name: " << it->getName() << endl;
		cout << "Product Quantity: " << it->getQuantity() << endl;
	}

	cout << "---------------------------------" << endl;
}
/************************************************
** Function:  void displayListCategory(vector<Item>& groceryList){
** Description: function to display the products by the location that the user
** specifies
*************************************************/
 void displayListCategory(vector<Item>& groceryList){
     string locationselection;
     int i;
       string locationSore[14]={"MEAT","DAIRY","CONDIMENTS","SWEETS",
                        "PRODUCE","GRAINS","HEALTH","BEVERAGES","HYGIENE",
                        "FROZEN","BAREKY","BABY", "HOUSEHOLD",
                        "MISALENEOUS"};
        cout << "Please enter a location that you want to see"<<endl;
        cout << "You can choose one of the following locations: " << endl;
        cout << "Only CAPITAL letters are accepted!!!" <<endl;
		for(i = 0; i <14 ; i++){
	    cout<< 	locationSore[i];
	    cout << endl;}
	    //http://stackoverflow.com/questions/7131858/stdtransform-and-toupper-no-matching-function
        do{
        getline(cin ,locationselection);
        }while (!isValidLocation(locationselection));
        cout << "Items in the LOCATION: " <<locationselection << endl;
        cout << "---------------------------------" << endl;
        // if (locationselection == it->getLocation()) {

        for(vector<Item>::iterator it = groceryList.begin(); it != groceryList.end(); ++it)
        {
             if (locationselection == it->getLocation()) {
		cout << "Product Location: " << it->getLocation() << endl;
		cout << "Product Name: " << it->getName() << endl;
		cout << "Product Quantity: " << it->getQuantity() << endl;
        }

        cout << "---------------------------------" << endl;}}

/************************************************
** Function: void checkout(vector<Item>&);
** Description: function to checkout once
** the user is done. It will display the products
** by location, show the price of the transaction and
** total savings
*************************************************/
void checkout(vector<Item>& groceryList)
{
	double totalRegularPrice = 0, totalSalePrice = 0;

	cout << "Items for checkout are are: " << endl;
	cout << "---------------------------------" << endl;

	for(vector<Item>::iterator it = groceryList.begin(); it != groceryList.end(); ++it)
	{
		cout << "Product Location: " << it->getLocation() << endl;
		cout << "Product Name: " << it->getName() << endl;
		cout << "Product Quantity: " << it->getQuantity() << endl;
		cout << "Regular Price: " << it->getRegularPrice()<<endl;
		cout << "Sales Price: " << it->getSalePrice()<< endl;
		totalRegularPrice += (it->getRegularPrice() * it->getQuantity());
		totalSalePrice += (it->getSalePrice() * it->getQuantity());
	}

	cout << "---------------------------------" << endl;

	cout << "Total Amount is: $" << totalSalePrice << endl;
	cout << "Total savings is: $" << (totalRegularPrice - totalSalePrice) << endl;
}

bool myfunction (Item i, Item j) { return (i.getLocation() < j.getLocation() );}


/************************************************
** Function: int integerCheck (string INPUT
** Description:Function checks that valid integer was
entered
*************************************************/
// I GOT THIS FUNCTION FROM Terry Lauer last quarter IN CS161
//MY ERROR CHECK FUNCTION HAD ONE PROBELM
//WHEN I TRIED TO ENTER 1 ;jkkhjggf (number, splace and some randome characters)
//IT WAS ACCEPTING IT AS A VALID ENTRY
int integerCheck (string INPUT, int min, int max){
	int isanint = 'n'; // is it an integer loop condition
	int x; // used in the loop
	int isok ; // used to test for integer
	int NUM; // the integer to be returned
// test to yes if it is an int
				isanint = 'n';
				while (isanint == 'n')
					{
						isok = 1;
						for (x=0; x < INPUT.length(); x=x+1)
							{
// check for digits
								if (((INPUT.at(x) >= '0' && INPUT.at(x) <= '9')))
									{
										isok = 1;
									}
								else
								 	{
// flag as bad and set exit
								 		isok = 0;
								 		x = INPUT.length();
								 	}
							}

/// if it did not pass the test for integer
				if ( isok == 0)
					{	cout << endl<<"That was NOT an integer or integer was <1." << endl;
						cout << "Please enter an integer between: " <<min << " - " << max <<" inclusive: " ;
						getline(cin,INPUT);
						cout << endl;
					}
				else
					{
						NUM = atoi(INPUT.c_str());
						isanint = 'y';
						isok = 1;
					}
			}
 	return NUM;
}
/************************************************
** Function: void newLine()
** Description:Function taken from the book. Reads
all charactes untill it see new life
*************************************************/
void newLine()
{
   char symbol;
   do
   {
      cin.get(symbol);
   } while (symbol != '\n');
}

/************************************************
** Function: void validEntry(double &entry);
** Description:Function checks that valid number was
entered. BOTH INTEGERS AND FLOATS ARE ACCEPTED
*************************************************/
void validEntry(double &entry){
      while(!cin.good()){
        cout << "Error, invalid entry.  " << endl
           << "Price needs to be a number." <<endl
             << "Pease make a different entry: ";
        cin.clear();
        cin.sync ();
        cin >> entry;
    }
}
