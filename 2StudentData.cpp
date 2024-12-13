/*
Develop a program in C++ to create a database of a student's infromation system containing the
following infromation :
    1) Name 2) Roll Number 3) Class Division 4) Date of Birth 5) Blood Group 
    6) Contact address 7) Telephone number. 8) Driving License no.
    Construct the database with suitable member functions. 
    Make use of ------>
    constructor -> default constructor, copy constructor, destructor.
    static member function, friend class, this pointer, inline code 
    dynamic memory allocation -> new and delete 
    exception handling.
*/

#include <iostream>
#include <string>
using namespace std;

class student;
class person {
    private :
        string name, bldgroup, address, tlno, drvno, dob;
    public :
        friend class student;
        person(string name) { //parameterized constructor
            this -> name = name; //this pointer
            name = "NA"; bldgroup = "NA"; address = "NA" ; tlno = "NA" ; drvno = "NA" ; dob = "NA";
        }
        person(person &z) { //copy constructor
            name = z.name ; dob = z.dob; bldgroup = z.bldgroup ; 
            address = z.address ; tlno = z.tlno ; drvno = z.drvno ;
        }
};

class student {
    private :
        int roll;
        char d;
        char *div = &d;
        static int count; //static variable

    public :
        student() { //default constructor
            roll = 0 ; 
            d = ' ';
            count++;
        }

        void accept(person &obj) {
            cout<<"Enter Name : ";
            cin.ignore();
            getline(cin , obj.name);
            cout<<"Enter Roll No. : ";
            cin>>roll;
            cout<<"Enter Division : ";
            cin>>d;

            cin.ignore();
            cout<<"Enter date of birth : ";
            getline(cin, obj.dob);

            cout<<"Enter Blood group : ";
            getline(cin , obj.bldgroup);
            cout<<"Enter Address : ";
            getline(cin , obj.address);
            cout<<"Enter Telephone Number : ";
            getline(cin ,obj.tlno);
            cout<<"Enter Driving Licence Number : ";
            getline(cin, obj.drvno);
        }

        inline void display( person &obj) { //inline function

            cout<<"\nName = "<<obj.name;
            cout<<"\nRoll No. = "<<roll;
            cout<<"\nDivision = "<<*div;

            cout<<"\nDate of Birth = "<<obj.dob;
            cout<<"\nBlood Group = "<<obj.bldgroup;
            cout<<"\nAddress = "<<obj.address;
            cout<<"\nTelephone Number = "<<obj.tlno;
            cout<<"\nDriving Licence Number = "<<obj.drvno;

            cout<<endl;
        }

        ~student() {   //destructor
            delete(div);
        }

        static int size() {
            return count;
        }
}; int student :: count ;

int main () {
    int a;
    cout<<"\nEnter number of students : ";
    cin>>a;
    student *s[a]; //pointer array of object
    person *p[a]; //pointer array of object

    while(true)
    {
        int ch;
        cout<<"\n   1.Enter a student details.";
        cout<<"\n   2.Display Studentdatabase.";
        cout<<"\n   3.To Exit.";
        cout<<"\nSelect Valid Option : ";
        cin>>ch;

        try{ //exceptional handling
            if(ch == 1) {
                for(int i = 0 ; i < a ; i++) {
                    cout<<"\nEnter details of student "<<i+1<<endl;
                    p[i] = new person(""); //dynamic allocation
                    s[i] = new student(); //dynamic allocation
                    s[i]->accept(*p[i]);
                }  
            }
            else if(ch == 2) {
                if(student::size() == 0 ) {
                    cout<<"\nEmpty data..!"<<endl;
                    break;
                }
                for(int i = 0 ; i < a ; i++) {
                    cout<<"\nDetails of student "<<i+1;
                    s[i]->display(*p[i]);
                }
                
            }
            else if(ch == 3) {
                cout<<"\nThank you..."<<endl;
                break;
            }
            else {
                throw(ch);
            }
        }catch(...) {
            cout<<"\nEntered Invalid choice -> "<<ch<<endl;
        }
    }
    for(int i = 0 ; i < a; i++) {
        delete s[i]; //dynamic delete
        delete p[i]; //dynamic delete
    }
    return 0;
}
