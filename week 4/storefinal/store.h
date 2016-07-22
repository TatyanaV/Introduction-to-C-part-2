#ifndef STORE_H
#define STORE_H
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
struct item{
    string name; //Name of the item
    string location; //Location in store
    double rprice; //regular price
    double sprice; //Sale Price
};
class storeManager{
private:
    vector<item> storeItems; //Store items in the store
    vector<item>::iterator f; //Used to navigate within the vector list
    vector<item> shopingList; //Holds item in the shopping list
public:
    /**
     * @brief storeManager contructor
     */
    storeManager(){
        storeItems.clear();
    }
    /**
     * @brief createStore Empty store items
     */
    void createStore(){
        storeItems.clear();
    }

    /**
     * @brief addItem add A new item to the list
     * @param a item record to be stored into the vector
     */
    void addItem(item &a){
        storeItems.push_back(a);
        cout<<"Item added"<<endl;
    }

    /**
     * @brief deleteItem removes items from the list
     * @param index index of item to remove
     */
    void deleteItem(unsigned int index){
        f=storeItems.begin();
        if(f==storeItems.end()){
            cout<<"Store empty"<<endl;
            return;
        }
        if(index<storeItems.size()){
            storeItems.erase(f+index-1);
        }else{
            cout<<"Item not available"<<endl;
        }
    }
    /**
     * @brief displayList displays al the items in the list
     */
    void displayList(){
        f=storeItems.begin();
        int x=0;
        item r; //Retrieved item
        cout<<setw(6)<<"<S\\N"<<setw(6)<<"\tItem"<<setw(7)<<"\tLocation"<<setw(8)<<"\tRegular price"<<setw(8)<<"\tSale price"<<endl;
        while(f!=storeItems.end()){
            r=*f;
            x++;
            cout<<setw(7)<<x;
            cout<<setw(6)<<r.name;
            cout<<setw(7)<<r.location;
            cout<<setw(8)<<r.rprice;
            cout<<setw(8)<<r.sprice<<endl;
            f++;
        }
    }
    /**
     * @brief displayList display items in  a given location in store
     * @param location Name of location to list items for
     */
    void displayList(string location){
        f=storeItems.begin();
        item r; //Retrieved item
        int x=0;
        cout<<setw(7)<<"S\\N"<<setw(6)<<"\tItem"<<setw(7)<<"\tLocation"<<setw(8)<<"\tRegular price"<<setw(8)<<"\tSale price"<<endl;
        while(f!=storeItems.end()){
            r=*f;

            if(r.location==location){
                x++;
            cout<<setw(7)<<x;
            cout<<setw(7)<<r.name;
            cout<<setw(7)<<r.location;
            cout<<setw(7)<<r.rprice;
            cout<<setw(7)<<r.sprice<<endl;
            }
            f++;
        }
    }
    /**
     * @brief displayCat display the summary of shopping Cart
     */
    void displayCart(){
        f=shopingList.begin();
        if(f==shopingList.end()){
            cout<<setw(7)<<"Shopping CART empty"<<endl;
            return;
        }
        double totalProfit; //Profit from sales
        double sellingP=0; //Seleing price
        double buyingP=0; //Buying price
        item r; //Retrieved item
        int x=0; //counter
        cout<<setw(7)<<"S\\N"<<setw(6)<<"\tItem"<<setw(7)<<"\tLocation"<<setw(8)<<"\tRegular price"<<setw(8)<<"\tSale price"<<endl;
        while(f!=shopingList.end()){
            r=*f;
            x++;
            cout<<setw(7)<<x;
            cout<<setw(6)<<r.name;
            cout<<setw(7)<<r.location;
            buyingP+=r.rprice;
            sellingP+=r.sprice;
            cout<<setw(8)<<r.rprice;
            cout<<setw(8)<<r.sprice<<endl;
            f++;
        }
        totalProfit=sellingP-buyingP;
        cout<<setw(20)<<"===Summary==="<<endl;
        cout<<setw(25)<<"Total selling price: "<<set<< sellingP<<endl;
        cout<<setw(25)<<"Total buying price: "<<setprecision(2)<<buyingP<<endl;
        cout<<setw(25)<<"Total p-rofit: "<<setprecision(2)<<totalProfit<<endl;
    }
    /**
     * @brief addShoppingList add items to the shopping cart
     * @param index index of item in the store
     */
    void addShoppingList(unsigned int index){
        //check to see that purchased items are not purchased again
        f=storeItems.begin();
        if(index<(storeItems.size()- shopingList.size())){
            shopingList.push_back(*(f+index)); //Add purchased item
            storeItems.erase(f+index); //Remove already purchased items
        }else{
            cout<<"The item index does  not exist"<<endl;
        }
    }
    /**
 * @brief deleteCart Deletes all items from the cart
 */
void deleteCart(){
    shopingList.clear();
}
};
#endif // STORE_H
