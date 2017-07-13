#include <iostream>
#include <vector>
using namespace std;

bool knighttourUtil(int n,vector<vector<int> > &board,int row,int col,int step)
{    
     if(step==(n*n +1))
     	return true;
     if(row<0 || row>=n || col<0 || col>=n || board[row][col]!=0)
     	return false;

       board[row][col]=step;
	if(knighttourUtil(n,board,row+2,col+1,step+1)==true)
		return true;
	if(knighttourUtil(n,board,row+2,col-1,step+1)==true)
		return true;
	if(knighttourUtil(n,board,row-2,col+1,step+1)==true)
		return true;
	if(knighttourUtil(n,board,row-2,col-1,step+1)==true)
		return true;
	if(knighttourUtil(n,board,row+1,col+2,step+1)==true)
		return true;
	if(knighttourUtil(n,board,row-1,col+2,step+1)==true)
		return true;
	if(knighttourUtil(n,board,row+1,col-2,step+1)==true)
		return true;
	if(knighttourUtil(n,board,row-1,col-2,step+1)==true)
		return true;
	
	
    board[row][col]=0;
    return false;
}

bool knighttour(int n){
       
       vector<vector<int> > board(n,vector<int>(n));

       if(knighttourUtil(n,board,0,0,1))
       {   
       	   for(int i=0;i<n;i++)
       	   {
       	   	for(int j=0;j<n;j++)
       	   	{
       	   		cout<<board[i][j]<<"  ";
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
   
	cout<<knighttour(n);
	return 0;
}