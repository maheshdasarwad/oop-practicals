/*
Write a program in C++ to use map associative container. The keys will be the names of states 
and the values will be the populations of the states. 
When the program runs, the users is prompted to type the name of a state. 
The program the looks in the map, using the state name as an index and returns the population of the state.
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string , string> state;

    state["Uttarpradesh"] = "200M";
    state["Maharashtra"] = "123M";
    state["Bihar"] = "104M";
    state["Tamil Nadu"] = "72M";
    state["Rajasthan"] ="69M";
    state["Gujarat"] = "60M";
    state["Telangana"] = "35M";
    state["Punjab"] = "28M";
    
    while(true) {
        int ch;
        cout<<"\n1. Display All Data.";
        cout<<"\n2. To know Population of state.";
        cout<<"\n3. To Exit";
        cout<<"\nEnter a valid option : ";
        cin>>ch;

        if(ch == 1) {
            cout<<"\nStates Name and population(Millions)----> "<<endl;
            for(auto &pair : state) {
                cout<<pair.first<<" "<<pair.second<<endl;
            }
        }

        else if(ch == 2) {
            string key;
            cout<<"\nEnter state name : ";
            cin.ignore();
            getline(cin,key);
            if(state.count(key)) {
                cout<<"Population(Million) = "<<state[key]<<endl;
            }
            else cout<<"Record not found..!"<<endl;
        }

        else if(ch == 3) {
            cout<<"\nEixted. Thank you..!!"<<endl;
            break;
        }
        
        else {
            cout<<"\nInvalid Option !!"<<endl;
        }
    }
    
    return 0;
}