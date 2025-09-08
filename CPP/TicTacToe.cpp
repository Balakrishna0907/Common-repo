#include <iostream>
using namespace std;

char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char playermarker;
int player;

void drawboard()
{
    cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<"--+---+--"<<endl;
    cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<"--+---+--"<<endl;
    cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}

void changeplayer()
{
    if(playermarker=='X') playermarker='O';
    else playermarker='X';
    if(player==1) player=2;
    else player=1;
}

bool placemark(int slot)
{
    int row=(slot-1)/3;
    int col=(slot-1)%3;
    if(board[row][col]!='X'&&board[row][col]!='O')
    {
        board[row][col]=playermarker;
        return true;
    }
    else 
        return false;
}

int checkwin()
{
    //for row and col
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) 
        return player;
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]) 
        return player;
    }
    //for diagonals
    for(int i=0;i<3;i++)
    {
        if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
        {
            return player;
        }
        if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])
        {
            return player;
        }
    } 
    return 0;   
}    

void game()
{
    cout<<"The game starts: "<<endl;
    char mark;
    int slot;
    char winner;
    cout<<"The first player choose? (\'X\' or \'O\')"<<endl;
    cin>>mark;
    playermarker=mark;
    player=1;
    //displaying board and taking slots
    for(int i=0;i<9;i++)
    {
    drawboard();
    cout<<"Player "<<player<<" choose your slot:"<<endl;
    cin>>slot;
    if(slot<1||slot>9)
    {
        cout<<"Invalid choice, Try again!"<<endl;
        i--;
        continue;
    }
    if(!placemark(slot))
    {
        cout<<"The slot is already occupied, Try again!"<<endl;
        i--;
        continue;
    }
    winner=checkwin();
    if(winner==1)
    {
        cout<<"Player 1 won!"<<endl;
        break;
    }
    if(winner==2)
    {
        cout<<"Player 2 won!"<<endl;
        break;
    }
    changeplayer();
    }
    drawboard();
    cout<<"Game ended!"<<endl;
}
int main()
{
    game();
}