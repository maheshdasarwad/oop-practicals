/*
Write a function template for selection sort that inputs, sorts and outputs an integer
array and a float array.
*/

#include <iostream>
using namespace std;

template<typename T1>
class Sort {
    private:
        int size;
        T1* arr;
        
    public:
        void input() {
            cout<<"\nEnter size of array : ";
            cin>>size;

            arr = new T1[size];
            cout<<"Enter elements --> "<<endl;
            for (int i = 0; i < size; i++) {
                cin>>arr[i];
            }
            selectionsort();
            display();
        }

        void selectionsort() {
            for(int i = 0; i < size - 1; i++) {
                int minIdx = i;
                for(int j = i + 1; j < size; j++) {
                    if(arr[j] < arr[minIdx]) {
                        minIdx = j;
                    }
                }
                if(minIdx != i) {
                    T1 temp = arr[minIdx];
                    arr[minIdx] = arr[i];
                    arr[i] = temp;
                }
            }
        }

        void display() {
            cout<<"\nSorted Array --->"<<endl;
            for(int i = 0; i < size; i++) {
                cout<<arr[i]<<"  ";
            }
            cout<<endl;
        }
};

int main() {
    cout<<"\nNow Sorting for integer --> ";
    Sort<int> s1;
    s1.input();

    cout<<"\nNow sorting for float --> ";
    Sort<float> s2;
    s2.input();

    return 0;
}
