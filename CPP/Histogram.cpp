#include <iostream>
#include <string.h>
using namespace std;

void histo(int n, char symbol)
{
    cout<<"Histogram: "<<endl;
    cout<<n<<" | ";
    for(int i=0;i<n;i++)
    {
        cout<<symbol;
    }
}
int main()
{
   int number;
   char symbol='#';
   cout<<"Enter the number for the histogram: "<<endl;
   cin>>number;
   cout<<"Enter a symbol: "<<endl;
   cin>>symbol;
   histo(number,symbol);
   return 0;
}