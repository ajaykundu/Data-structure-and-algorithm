#include <iostream>
#include <vector>
using namespace std;

bool issafe(vector<vector<int> > board,int n,int row,int col)
{
	if(col==0)
		return true;

	for(int j=col,i=row;j>=0;j--)
	{
		if(board[i][j]==1)
		{
			return false;
		}
	}

	for(int j=col,i=row;i>=0 && j>=0;j--,i--)
	{
		if(board[i][j]==1)
		{
			return false;
		}
	}

	for(int j=col,i=row;j>=0 && i<n;i++,j--)
	{
		if(board[i][j]==1)
			return false;
	}

	return true;
}

bool NqueensUtil(vector<vector<int> > &board,int n,int col)
{
     if(col>=n)
     {
     	return true;
     }
     
	for(int i=0;i<n;i++)
	{
		if(issafe(board,n,i,col)){
		board[i][col]=1;
		if(NqueensUtil(board,n,col+1))
		{
			return true;
		}
		board[i][col]=0;
	}
	}

	return false;
}

bool Nqueens(int n)
{
	vector<vector<int> > board(n,vector<int>(n));

	if(NqueensUtil(board,n,0))
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	cout<<Nqueens(n);
	return 0;
}