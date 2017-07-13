#include <iostream>
#include <cstring>
using namespace std; 

bool rateInMazeUtil(int **maze,int n,int row,int col)
{  
	if(row==n-1 && col==n-1)
	{
		maze[row][col]=2;
		return true;
	}

   if(row<0 || row>=n || col>=n || col<0 || maze[row][col]!=1)
   	return false;

	maze[row][col]=2;

	if(rateInMazeUtil(maze,n,row+1,col))
		return true;
    if(rateInMazeUtil(maze,n,row-1,col))
		return true;
	if(rateInMazeUtil(maze,n,row,col-1))
		return true;
	if(rateInMazeUtil(maze,n,row,col+1))
		return true;
	maze[row][col]=1;
	return false;
}

void printmaze(int ** maze,int n)
{
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		cout<<maze[i][j]<<" ";
    	}
    	cout<<endl;
    }
}

bool rateInMaze(int **maze,int n)
{
	if(rateInMazeUtil(maze,n,0,0))
	{ 
       printmaze(maze,n);
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n=5;
    
    int** maze=new int*[n];
    for(int i=0;i<n;i++)
    {
    	maze[i]=new int[n];
    	memset(maze[i],0,n*sizeof(int));
    }

    maze[0][0] = 1;

maze[1][0] = 1;

maze[2][0] = 1;

maze[3][0] = 1;

maze[4][0] = 1;

maze[1][1] = 1;

maze[0][2] = 1;

maze[1][2] = 1;

maze[0][3] = 1;

maze[2][3] = 1;

maze[3][3] = 1;

maze[4][3] = 1;

maze[0][4] = 1;

maze[1][4] = 1;

maze[2][4] = 1;

maze[4][4] = 1;

   printmaze(maze,n);
   cout<<endl;
 cout<<rateInMaze(maze,n);
	return 0;
}