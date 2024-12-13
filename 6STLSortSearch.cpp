/*
Write a c++ program using STL for sorting and searching user defined records such 
as item records(Item code, name, cost, quantity etc) using vector container.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
    private :
        int code;
        float cost, quantity;
        string name;
    
    public :
        void input() {
            cout<<"\nEnter Item Code : ";
            cin>>code;
            cout<<"Enter Item Name : ";
            cin.ignore();
            getline(cin,name);
            cout<<"Enter Item Cost : ";
            cin>>cost;
            cout<<"Enter Item Quantity : ";
            cin>>quantity;
        }

        void display() {
            cout<<"\nCode : "<<code;
            cout<<"\nName : "<<name;
            cout<<"\nCost : "<<cost;
            cout<<"\nQuantity : "<<quantity<<endl;
        }

        int getcode() {
            return code;
        }

        bool operator < ( Item &obj) { //overload comparison for sorting objects
            return code < obj.code;
        }
};

int main()
{
    vector<Item> v;
    Item obj;

    int size;
    cout<<"\nEnter Number of Items : ";
    cin>>size;
    for(int i = 0 ; i < size; i++) {
        cout<<"\nEnter Item "<<i+1<<" Details";
        obj.input();
        v.push_back(obj);
    }

    while(true) {
        int ch;
        cout<<"\n1. Display Items.";
        cout<<"\n2. Search Item.";
        cout<<"\n3. Sort Item.";
        cout<<"\n4. To Exit.";
        cout<<"\nSelect valid choice : ";
        cin>>ch;

        if(ch == 1) {
            for(int i = 0; i < size ; i++) {
                v[i].display();
            }
        }

        else if(ch == 2) {
            int x;
            cout<<"\nEnter item code to search : ";
            cin>>x;

            int flag = -1;
            for(int i = 0 ; i < v.size() ; i++){
                if(v[i].getcode() == x){
                    flag = i;
                    cout<<"\nFound-->"; 
                    v[i].display();
                    break;
                }
            }
            if(flag == -1) cout<<"\nItem Not found in record!!!"<<endl;  
        }

        else if(ch == 3) {
            sort(v.begin() , v.end());
            for(int i = 0; i < size ; i++) {
                v[i].display();
            }
        }

        else if(ch == 4) {
            cout<<"\nExiting the program ...!"<<endl;
            break;
        }
        else {
            cout<<"\nEntered Invalid option..!"<<endl;
        }
    }
   
return 0;
    
}