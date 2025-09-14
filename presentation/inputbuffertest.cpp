#include <iostream>
using namespace std;

int main()
{
    int num;
    char name[100];
    cout<<"Enter a Number: "<<endl;
    cin>>num;
    cin.ignore(10000,'\n'); // toggle this line to demonstrate the input buffer
    cout<<"Enter a Name: "<<endl;
    cin.getline(name,100);
    cout<<num<<endl;
    cout<<name;
    return 0;
}

