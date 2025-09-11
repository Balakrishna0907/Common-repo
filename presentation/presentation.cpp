#include <iostream>
#include <fstream> //for file formatting
#include <limits> //for limiting the input buffer
using namespace std;

struct voter
{
    char name[50], voterid[20];
    int age;
    char gender;
}v[100];

int main()
{
    char op;
    int i=0;
    do
    {
        cout<<"Enter your Name: "<<endl;
        cin.ignore(10000,'\n'); //to clear input buffer
        cin.getline(v[i].name,50);
        cout<<"Enter your VoterID: "<<endl;
        cin.getline(v[i].voterid,20);
        cout<<"Enter your Age: "<<endl;
        cin>>v[i].age;
        cout<<"Enter your Gender (M/F/O): "<<endl;
        cin>>v[i].gender;
        if(v[i].age>=18) //age verification
        {
            ofstream file("VoterDetails-presentation",ios::app); //initialising a file & appending datas to it
            // appending datas to the file
            file<<"Name: "<<v[i].name<<endl;
            file<<"VoterID: "<<v[i].voterid<<endl;
            file<<"Age: "<<v[i].age<<endl;
            if(v[i].gender=='m'||v[i].gender=='M') file<<"Gender: Male"<<endl;
            else if(v[i].gender=='f'||v[i].gender=='F') file<<"Gender: Female"<<endl;
            else file<<"Gender: Others"<<endl;
            file<<"---------------"<<endl;
            cout<<"The details have been added to the \'VoterDetails-presentation\' file"<<endl;
            file.close(); //closing the file to ensure the data is saved securely
        }
        else
        {    
            cout<<"You are not eligible for voting!"<<endl;  
        }
        cout<<"Do you want to run the code again? (Y/N)"<<endl;
        cin>>op;
        i++;
    }while(op=='y'||op=='Y');
    return 0;
}
