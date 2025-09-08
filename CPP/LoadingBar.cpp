#include <iostream>
#include <thread> //for this_thread fucntion
#include <chrono> //for chrono (time) functions
using namespace std;


int main()
{
    cout<<"-----LOADING BAR-----"<<endl;
    cout<<"Loading started!"<<endl;
    for(int i=0;i<=20;i++)
    {
       cout<<"Loading...."<<i*5<<"%"<<endl;
       this_thread::sleep_for(chrono::milliseconds(500));
    }
    cout<<"Loading completed!"<<endl;
}