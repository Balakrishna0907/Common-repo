#include <iostream>
using namespace std;

void primedet(int n)
{
    if(n==1)
    {
        cout<<"1 is not considered as prime nor composite"<<endl;
    }
    else
    {
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
            {
                cout<<n<<" is not a prime number!"<<endl;
                break;
            }
            else
            {
                cout<<n<<" is a prime number!"<<endl;
                break;
            }
        }
    }
}

int main()
{
    int num;
    cout<<"Enter a number: "<<endl;
    cin>>num;
    primedet(num);
    return 0;
}