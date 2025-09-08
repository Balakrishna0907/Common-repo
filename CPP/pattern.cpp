#include <iostream>
#include <string>
using namespace std;

void triangle()
{
    int n=1;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"*";
        }
        n++;   
        cout<<"\n";
    }
    cout<<"\n";
}

void invtriangle()
{
    int n=1;
    for(int i=0;i<5;i++)
    {
        for(int j=5;j>=n;j--)
        {
            cout<<"*";
        }
        n++;   
        cout<<"\n";
    }
    cout<<"\n";
}

void pyramid()
{
    int row=5;
    int s=row;
    for(int i=1;i<=row;i++)
    {
     
        for(int j=1;j<=s;j++)
        {
            cout<<" ";
        }
        s--;
        for(int k=1;k<=(2*i)-1;k++)
        {
        cout<<"*";
        } 
        cout<<"\n";
    }
    cout<<"\n";
}

void checkboard()
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(i%2==0) cout<<"# ";
            else cout<<" #";

        }
        cout<<"\n";
    }
    cout<<"\n";
}
int main()
{
    cout<<"Triangle pattern: "<<endl; triangle();
    cout<<"Inverted triangle pattern: "<<endl; invtriangle();
    cout<<"Pyramidal pattern: "<<endl; pyramid();
    cout<<"Check Board pattern: "<<endl; checkboard();

    return 0;
}
