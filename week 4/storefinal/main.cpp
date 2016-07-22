#include <iostream>
#include "store.h"
#include <iomanip>
#include <cstdlib>
#include <exception>
using namespace std;

int main()
{
    cout<<"\t====Welcome to store======"<<endl;
    int choice; //Users menu choosen
    unsigned int index;
    string category;
    storeManager *sm=new storeManager();
    item it; //Hold item to be stored;
while(true){
        cout<<setw(6)<<setprecision(5)<<"\t==========MENU==============="<<endl;
        cout<<setw(14)<<"\t\t 1. Create list (make store empty)"<<endl;
        cout<<setw(14)<<"\t\t 2. Add item to store"<<endl;
        cout<<setw(14)<<"\t\t 3. Remove items from store"<<endl;
        cout<<setw(14)<<"\t\t 4. Display items (store)"<<endl;
         cout<<setw(14)<<"\t\t 5. Display by category"<<endl;
        cout<<setw(14)<<"\t\t 6. Add item to the cart"<<endl;
        cout<<setw(14)<<"\t\t 7. Display shopping cart"<<endl;
        cout<<setw(14)<<"\t\t 8. Delete items cart"<<endl;
         cout<<setw(14)<<"\t\t 9. Quit"<<endl;
         PR:
         cout<<"choice $>>";
         try{
         cin>>choice;
         }catch(...){cout<<"\t\tInvalid entry"<<endl;
         goto PR;
         }
         switch(choice){
            case 1:
             sm->createStore();
             break;
         case 2:
             cout<<"Enter item name"<<endl;
             cin>>it.name;
             cout<<"Enter location in store"<<endl;
             cin>>it.location;
             cout<<"Regular price"<<endl;
             cin>>it.rprice;
             cout<<"Seling price"<<endl;
             cin>>it.sprice;
             sm->addItem(it);
             break;
         case 3:
                sm->displayList();
                cout<<"Enter item index to remove"<<endl;
                cin>>index;
                sm->deleteItem(index);
             break;
         case 4:
             sm->displayList(); //List of all items
             break;
         case 5:
            cout<<"Enter category"<<endl;
            cin>>category;
            sm->displayList(category);
             break;
         case 6:
             //Adds an item to the shoping cart
             sm->displayList();
             cout<<"Enter item Index"<<endl;
            cin>>index;
            sm->addShoppingList(index);
             break;
         case 7:
             //display cart data
             sm->displayCart();
             break;
         case 8:
             sm->deleteCart();
             break;
         case 9:
             exit(0);
             break;
         default:
             cout<<"Invalid choice"<<endl;
         }
}
cout<<"Bye"<<endl;
    return 0;
}

