/*
Write a c++ program that creates an output file, write infromation to it, closes the file, 
open it again as an input file and read the information from the file.
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name;
    float price;
    int pagecnt;

    //creating output file----->
    fstream ofobj;
    ofobj.open("E:\\Handling.txt",ios::out | ios::trunc);

    if(!ofobj) {
        cout<<"\nError in file opening in write mode";
        return -1;
    }

    cout<<"Book Details";
    cout<<"\nEnter Publication Name : ";
    getline(cin,name);
    cout<<"Enter Publication Price(Rupees) : ";
    cin>>price;
    cout<<"Enter Page Count : ";
    cin>>pagecnt;

    ofobj<<name<<endl;
    ofobj<<price<<endl;
    ofobj<<pagecnt<<endl;

    ofobj.close();

    //Opening as an input file
    fstream ifobj;
    ifobj.open("E:\\Handling.txt",ios::in);

    if(!ifobj) {
        cout<<"\nError in opening a file in read mode";
        return -1;
    }

    getline(ifobj,name);
    ifobj>>price;
    ifobj>>pagecnt;

    cout<<"\nTitle :: "<<name;
    cout<<"\nPrice :: "<<price;
    cout<<"\nPage Count :: "<<pagecnt<<endl;

    ifobj.close();
}