/*
Implement a class Complex which represents the Complex Number data types. Implement the following 
1) Constructor(Including a default constructor which creates the complex number 0+0i)
2) Overload operator+ to add two complex numbers.
3) Overload operator* to multiply two complex numbers.
4) Overload oprators << and >> to print and read complex numbers.
*/

#include<iostream>
using namespace std;

class Complex {
    private :
        float real , imag;
    public :
        Complex() {
            real = imag = 0;
        }

        Complex operator +(Complex &obj) {
            Complex temp;
            temp.real = real + obj.real;
            temp.imag = imag + obj.imag;

            return temp;
        }

        Complex operator *(Complex &obj) {
            Complex temp;
            temp.real = real*obj.real - imag*obj.imag;
            temp.imag = real*obj.imag + imag*obj.real;

            return temp; 
        }

        Complex operator /(Complex &z) {
            Complex temp;
            temp.real = ((real * z.real) + (imag * z.imag)) / ((z.real * z.real) + (z.imag * z.imag));
            temp.imag = (-(real * z.imag) + (imag * z.real)) /((z.real * z.real) + (z.imag * z.imag));
            return temp;
        }

        friend istream &operator >>(istream &in, Complex &obj);
        friend ostream &operator <<(ostream &out, Complex &obj);
};

istream &operator >>(istream &in, Complex &obj) {
    cout<<"Enter real part : ";
    in>>obj.real;
    cout<<"Enter imaginary part : ";
    in>>obj.imag;
    cout<<endl;
}

ostream &operator <<(ostream &out, Complex &obj) {
    out<<"\nComplex Number = "<<obj.real<<" + i("<<obj.imag<<")"<<endl;
}

int main() {
    Complex num1 , num2, num3;

    cout<<"\nComplex Number 1 ---> "<<endl;
    cin>>num1;
    cout<<"\nComplex Number 2 ---> "<<endl;
    cin>>num2;

    while(true)
    {
        int ch;
        cout<<"\n1. Addition.";
        cout<<"\n2. Multiplication.";
        cout<<"\n3. Division.";
        cout<<"\n4. Exit";
        cout<<"\nEnter valid option : ";
        cin>>ch;

        if(ch == 1) {
            cout<<"\nAddition -->";
            num3 = num1 + num2;
            cout<<num3;
        }
        else if(ch == 2) {
            cout<<"\nMultiplication -->";
            num3 = num1 * num2;
            cout<<num3;
        }
        else if(ch == 3) {
            cout<<"\nDivision --->";
            num3 = num1 / num2;
            cout<<num3;
        }
        else if(ch == 4) {
            cout<<"\nExited. Thank you...!"<<endl;
            break;
        }
        else {
            cout<<"\nEntered Invalid Option!!"<<endl;
        }

    }

    return 0;
}
