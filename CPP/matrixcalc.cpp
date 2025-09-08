#include <iostream>
using namespace std;

#define MAX 10
void getmatrix(int mat[MAX][MAX],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<"\nEnter the value for index "<<i+1<<" "<<j+1<<endl;
            cin>>mat[i][j];
        }
    }
}

void displaymatrix(int mat[MAX][MAX],int row,int col)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void addmat(int A[MAX][MAX],int B[MAX][MAX],int row,int col)
{
    int result[MAX][MAX];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            result[i][j]=A[i][j]+B[i][j];
        }
    }
    cout<<"The resultant matrix is: "<<endl;
    displaymatrix(result,row,col);
}

void submat(int A[MAX][MAX],int B[MAX][MAX],int row,int col)
{
    int result[MAX][MAX];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            result[i][j]=A[i][j]-B[i][j];
        }
    }
    cout<<"The resultant matrix is: "<<endl;
    displaymatrix(result,row,col);
}

void mulmat(int A[MAX][MAX],int B[MAX][MAX],int r1,int c1,int r2,int c2)
{
    int result[MAX][MAX];
    if(c1!=r2)
    {
        cout<<"Multiplication of given matrices not possible! coloumn of first matrix should be equal to the row of second matrix!"<<endl;
        return;
    }
    else
    {
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            result[i][j]=0;
            for(int k=0;k<c1;k++)
            {
                result[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    }
    cout<<"The resultant matrix is: "<<endl;
    displaymatrix(result,r1,c2);
}

void transposemat(int A[MAX][MAX],int row,int col)
{
    int result[MAX][MAX];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            result[j][i]=A[i][j];
        }
    }
    cout<<"The resultant matrix is: "<<endl;
    displaymatrix(result,row,col);
}

int main()
{
    int op;
    do{
        cout<<"\n<===== MATRIX CALCULATOR =====>";
        cout<<"\n1. Matrix Addition.\n2. Matrix Subraction.\n3. Matrix Multiplication.\n4. Matrix Transpose.\n5. Exit. ";
        cout<<"\nEnter your choice: ";
        cin>>op;
        if(op==1||op==2)
        {
            int r,c;
            int A[MAX][MAX],B[MAX][MAX];
            cout<<"\nEnter rows and coloumn for matrices: ";
            cin>>r>>c;
            cout<<"\nEnter the elements for first matrix: ";
            getmatrix(A,r,c);
            cout<<"\nEnter the elements for second matrix: ";
            getmatrix(B,r,c);
            if(op==1) addmat(A,B,r,c);
            else submat(A,B,r,c);
        }
        else if(op==3)
        {
            int A[MAX][MAX],B[MAX][MAX];
            int r1,c1,r2,c2;
            cout<<"\nEnter row and coloumn for first matrix: ";
            cin>>r1>>c1;
            cout<<"\nEnter elements for first matrix: ";
            getmatrix(A,r1,c1);
            cout<<"\nEnter row and coloumn for second matrix: ";
            cin>>r2>>c2;
            cout<<"\nEnter elements for second matrix: ";
            getmatrix(B,r2,c2);

            mulmat(A,B,r1,c1,r2,c2);
        }
        else if(op==4)
        {
            int A[MAX][MAX];
            int r,c;
            cout<<"\nEnter row and coloumn for the matrix: ";
            cin>>r>>c;
            cout<<"\nEnter elements for the matrix: ";
            getmatrix(A,r,c);

            transposemat(A,r,c);
        }
    }while(op!=5);
    return 0;
}