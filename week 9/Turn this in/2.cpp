//tatyana vlaskin
//lab 9
//problem 2
//2.cpp


#include <iostream>
#include<limits>
using namespace std;
void integerCheck(double &integer);

//https://www.youtube.com/watch?v=o5wJkJJpKtM
//http://www.whatsupnew.com/circular-queue-using-linked-list/
//https://www.youtube.com/watch?v=_1ybxs60-Sc
//https://www.youtube.com/watch?v=CSVRA4_xOkw
//http://www.baumann.info/public/cpp_lernaufgabe_linked_list.pdf

struct Node{
    int num;
    Node*link;//node pointer
};

int main(){
    Node *head = NULL; //pointer to the head node
    Node *current;//pointer to the current node
    double suitors;
    cout <<"Enter number of suitors: " ;
    cin>>suitors;
    integerCheck(suitors);
    cout <<"There are " << suitors << " suitors, who are willing to marry the princess!" <<endl;
    if (suitors ==1){
        cout <<"The suitor, who will marry the princess is suitor #: " <<suitors <<endl;
    }

    else{
        //create the circular linked list, starting with #1
        head = new Node; // creating a new node and head is pointing at the newly created node
        head->num=1;//filling up the data member of the node with 1- 1st suitor
        head->link=head;//pointer of the head is poiting to the same node as head is pointing to
        current=head; // tell current pointer to point to the same node as head pointer is pointing to

        for(int i = 2; i<=suitors; i++){
            Node *newNode = new Node;//creating a new pointer and a new node for each suitor
            newNode->num=i;//assing number in each node corresponding to the appropriate suitor
            newNode->link=head; //pointer of the new node is pointing to the same node as head pointer pointing to
            current->link=newNode;// current pointer is pointing to the same node as newly created node is pointing to
            current=newNode; // tells current pointer to point to the same node as the newNode pointer is pointing to
        }
        current = head; // tells the current pointer to point to the same node as head is pointing to
        do{
            //skip to 3rd sutor
            current = current ->link;
            Node * previous = current; //create a pointer that points to the current node
            current = current->link; // advances the current pointer
            Node * next = current->link;//create a pointer that points to the next node
            previous->link = next;//tells teh previous pointer to point to the same node as next is pointing to

            cout<< "Eliminating the suitor number: " <<current->num <<endl;
            delete current;
            current = next;// tells current to point to the same node as next is pointint to
        }while (current !=current->link);
            cout <<"The last suitor, who will marry the princess is suitor #: " <<current->num <<endl;
            delete current;
        }
        return 0;
}

//http://www.parashift.com/c++-faq/istream-and-ignore.html
void integerCheck(double &integer){
    while(cin.fail() ||!cin.good()|| integer!= static_cast<int>(integer) || integer <=0){
        cout << "Error, invalid entry. " << endl
        << "Pease make a different entry: ";
        cin.clear();
        cin.ignore(80,'\n');
        cin.sync ();
        cin >> integer;
    }
}

