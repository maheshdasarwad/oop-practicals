/*
Imagine a publishing company which does marketing for book and audiocassette versions.
Create a class publication that stores the 
-> title (a string) and 
-> price (type float) of a publication.
From this class 
-> derive two classes : 1) book which adds a page count (type int) and 
                        2) tape which adds a playing time in minute (type float).
Write a program that instantiates the book and tape classes allows user to enter data 
and displays the data members.
If an exception is caught replace all the data member values with zero values.
Accepting things from user is 
for book
1) title 2) price 3) page count 
for tape 
1) title 2) price 3) playing time
*/

#include <iostream>
#include <string>
using namespace std;

class publication {
    protected :
        string title;
        float price;

    public :
        void reset() {
            title ="";
            price = 0.0;
        }

        publication(string t, float p) {
            title = t;
            price = p;
        }
};

class book : public publication {
    private :
        int pagecnt;
    
    public :

        book(string s , float f , int i) : publication(s , f) {
            try {
                pagecnt = i;
                if(pagecnt <= 0) throw(pagecnt);
            } catch(...) {
                cout<<"\nInvalid Page count!!!."<<endl;
                reset();
                pagecnt = 00 ;
            }
        }
        
        void displayBook() {
            cout<<"\nBOOK PUBLICATION----------->";
            cout<<"\nTitle :: "<<title;
            cout<<"\nPrice :: "<<price;
            cout<<"\nPage Count :: "<<pagecnt;
            cout<<endl;
        }

};

class tape : public publication {
    private :
        float mins;
    public :
        tape(string s , float f , float i):publication(s , f) {
            try {
                mins = i;
                if(mins <= 0) throw (mins);
            } catch(...) {
                cout<<"\nInvalid Playing Time!!!."<<endl;
                reset();
                mins = 0.0;
            }
        }

        void displayTape() {
            cout<<"\nTAPE PUBLICATION------>";
            cout<<"\nTitle :: "<<title;
            cout<<"\nPrice :: "<<price;
            cout<<"\nPlay Time :: "<<mins;
            cout<<endl;
        }
};


int main() {
    int page;
    float min , price ;
    string title;

    book bb("NA", 0.0 , 1);
    tape tt("NA", 0.0 , 1.1);
      
    while(true) {
        int ch;
        cout<<"\n   1.Add Book publication details.";
        cout<<"\n   2.Add Tape publication details.";
        cout<<"\n   3.Display Book publication details.";
        cout<<"\n   4.Display Tape publication details.";
        cout<<"\n   5.Exit.";
        cout<<"\nEnter valid option : ";
        cin>>ch;
        cout<<endl;

        if(ch == 1) {
            cout<<"Book Details";
            cout<<"\nEnter Publication Name : ";
            cin.ignore();
            getline(cin,title);
            cout<<"Enter Publication Price(Rupees) : ";
            cin>>price;
            cout<<"Enter Page Count : ";
            cin>>page; 

            bb = book(title , price ,page );
        }
        else if(ch == 2) {
            cout<<"Tape Details";
            cout<<"\nEnter Publication Name : ";
            cin.ignore();
            getline(cin,title);
            cout<<"Enter Publication Price(Rupees) : ";
            cin>>price;
            cout<<"Enter Playing time(min) : ";
            cin>>min;

            tt = tape(title , price , min) ;
        }  
        else if( ch == 3) {
            bb.displayBook();
        }
        else if(ch == 4) {
            tt.displayTape();
        }

        else if (ch == 5) {
            cout<<"\nExited Successfully..."<<endl;
            break;
        }
        else cout<<"\nEnter valid option.!!"<<endl;
    }
  
return 0;
}

