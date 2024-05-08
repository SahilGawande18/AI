#include<iostream> 
#define N 4
using namespace std;
//int solution=0;
void print(int board[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j])
            {
                cout<<" Q ";
            }
            else
            cout<<" - ";
        }
        cout<<endl;
    }
   // cout<<"Solution:"<<++solution<<endl;
}


bool issafe(int board[N][N],int row,int col)
{
    
    for(int i=0;i<col;i++)
    {
        if(board[row][i])
        {
            return false;
        }
    }

    int i,j;
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j])
        return false;
    }

    for(i=row,j=col;i<N && j>=0;i++,j--)
    {
        if(board[i][j])
        return false;
    }

    return true;
}

bool SolveNQUtil(int board[N][N],int col)
{
    if(col>=N)
    {
        print(board);
        return true;
    }
           // bool res=false;

    for(int i=0;i<N;i++)
    {   
        if(issafe(board,i,col))
        {
            board[i][col]=1;

            if(SolveNQUtil(board,col+1))
            return true;
            //res=SolveNQUtil(board,col+1) || res;
           board[i][col]=0;//
        }
    }
    return false;
    //return res;

}

bool Solve()
{
    int board[N][N]={0};

    if(SolveNQUtil(board,0)==false)
    {
        cout<<"NOt found";
    }

    print(board);
    return true;
}


int main()
{
    Solve();
}