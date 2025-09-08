#include <iostream>
#include <fstream> //for file formatting
#include <string> //for string datatype
using namespace std;

int main()
{
    string name, voterid;
    int age;
    char op='y';

    ofstream file("Voter Details",ios::app); //initialising a file & appending datas to it
    do
    {
        cout<<"Enter your Name: "<<endl;
        cin.ignore(); //to clear input buffer
        getline(cin,name);
        cout<<"Enter your VoterID: "<<endl;
        getline(cin,voterid);
        cout<<"Enter your Age: "<<endl;
        cin>>age;
        if(age>=18) //age verification
        {
            // appending datas to the file
            file<<"Name: "<<name<<endl;
            file<<"VoterID: "<<voterid<<endl;
            file<<"Age: "<<age<<endl;
            file<<"---------------"<<endl;
            cout<<"The details have been added to the \'Voter Details\' file"<<endl;
            file.close(); //closing the file to ensure the data is saved securely
        }
        else
        {    
            cout<<"You are not eligible for voting!"<<endl;  
        }
        cout<<"Do you want to run the code again? (Y/N)"<<endl;
        cin>>op;
    }while(op=='y'||op=='Y');
    return 0;
}
