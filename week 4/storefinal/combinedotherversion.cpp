#include<iostream>
#include<string>
using namespace std;

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

	string getName()
	{
		return name;
	}

	string getLocation()
	{
		return location;
	}

	double getRegularPrice()
	{
		return regularPrice;
	}

	double getSalePrice()
	{
		return salePrice;
	}

	int getQuantity()
	{
		return quantity;
	}

	void setName(string name)
	{
		this->name = name;
	}

	void setLocation(string location)
	{
		this->location = location;
	}

	void setRegularPrice(double regularPrice)
	{
		this->regularPrice = regularPrice;
	}

	void setSalePrice(double salePrice)
	{
		this->salePrice = salePrice;
	}

	void setQuantity(int quantity)
	{
		this->quantity = quantity;
	}
};

using namespace std;

void loadProduct(vector<Item>&);
void addProduct(vector<Item>&, vector<Item>&);
void deleteProduct(vector<Item>&);
void displayList(vector<Item>&);
void checkout(vector<Item>&);

int main()
{
	vector <Item> itemList;
	vector <Item> groceryList;
	int choice;

	loadProduct(itemList);
		for(vector<Item>::iterator it = itemList.begin(); it != itemList.end(); ++it)
	{
		cout << "Product Name: " << it->getName() << endl;
		cout << "Product Location: " << it->getLocation() << endl;
		cout << "Product Regular Price: " << it->getRegularPrice() << endl;
		cout << "Product Sale Price: " << it->getSalePrice() << endl;
		cout << "Product Quantity: " << it->getQuantity() << endl;
		cout << "---------------------------------" << endl;
	}

	while(1)
	{
		cout << "--Please select option --" << endl;
		cout << "1. Add Item to list" << endl;
		cout << "2. Delete Item from list" << endl;
		cout << "3. Display the list" << endl;
		cout << "4. Checkout" << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			addProduct(itemList, groceryList);
			break;

		case 2:
			deleteProduct(groceryList);
			break;

		case 3:
			displayList(groceryList);
			break;

		case 4:
			checkout(groceryList);
			break;

		default:
			cout << "Invalid Option selected" << endl;
			break;
		}

		if(choice == 4)
			break;
	}
	return 0;
}

void loadProduct(vector<Item>& itemList)
{
	itemList.push_back(Item("Pepsi", "Cold Drinks", 5.99, 4.99, 25));
	itemList.push_back(Item("Brown Bread", "Bread", 3.99, 3.49, 25));
	itemList.push_back(Item("Blueberry", "Fruit", 5, 5, 25));

	for(vector<Item>::iterator it = itemList.begin(); it != itemList.end(); ++it)
	{
		cout << "Product Name: " << it->getName() << endl;
		cout << "Product Location: " << it->getLocation() << endl;
		cout << "Product Regular Price: " << it->getRegularPrice() << endl;
		cout << "Product Sale Price: " << it->getSalePrice() << endl;
		cout << "Product Quantity: " << it->getQuantity() << endl;
		cout << "---------------------------------" << endl;
	}
}

void addProduct(vector<Item>& itemList, vector<Item>& groceryList)
{
	string pName;
	int pQuantity;

	cout << "Enter product name" << endl;
	cin >> pName;

	for(vector<Item>::iterator it = itemList.begin(); it != itemList.end(); ++it)
	{
		if (pName.compare(it->getName()) == 0)
		{
			cout << "Enter Quantity" << endl;
			cin >> pQuantity;
			if(pQuantity < 0 || pQuantity > it->getQuantity())
			{
				cout << "Invalid quantity or the quantity exceeds the stock" << endl;
			}
			groceryList.push_back(Item(it->getName(), it->getLocation(), it->getRegularPrice(), it->getSalePrice(), pQuantity));
			it->setQuantity(it->getQuantity() - pQuantity);
			return;
		}
	}
	cout << "Item does not exist" << endl;
}

void deleteProduct(vector<Item>& groceryList)
{
	string pItem;

	cout << "Enter Item to delete " << endl;
	cin >> pItem;

	for(vector<Item>::iterator it = groceryList.begin(); it != groceryList.end(); ++it)
	{
		if(it->getName().compare(pItem) == 0)
			groceryList.erase(it);
	}
}

void displayList(vector<Item>& groceryList)
{
	cout << "Items in the list are: " << endl;
	cout << "---------------------------------" << endl;

	for(vector<Item>::iterator it = groceryList.begin(); it != groceryList.end(); ++it)
	{
		cout << "Product Name: " << it->getName() << endl;
		cout << "Product Location: " << it->getLocation() << endl;
		cout << "Product Regular Price: " << it->getRegularPrice() << endl;
		cout << "Product Sale Price: " << it->getSalePrice() << endl;
		cout << "Product Quantity: " << it->getQuantity() << endl;
	}

	cout << "---------------------------------" << endl;
}

void checkout(vector<Item>& groceryList)
{
	double totalRegularPrice = 0, totalSalePrice = 0;

	cout << "Items for checkout are are: " << endl;
	cout << "---------------------------------" << endl;

	for(vector<Item>::iterator it = groceryList.begin(); it != groceryList.end(); ++it)
	{
		cout << "Product Name: " << it->getName() << endl;
		cout << "Product Location: " << it->getLocation() << endl;
		cout << "Product Quantity: " << it->getQuantity() << endl;
		totalRegularPrice += (it->getRegularPrice() * it->getQuantity());
		totalSalePrice += (it->getSalePrice() * it->getQuantity());
	}

	cout << "---------------------------------" << endl;

	cout << "Total Amount is: $" << totalSalePrice << endl;
	cout << "Total savings is: $" << (totalRegularPrice - totalSalePrice) << endl;
}

