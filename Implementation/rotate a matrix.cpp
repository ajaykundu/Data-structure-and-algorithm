#include <iostream>
using namespace std;


int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int n;
	    cin>>n;
	    int arr[n][n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    
	   for(int x=0;x<n/2;x++)
	   {
	       for(int y=x;y<n-1-x;y++)
	       {
	           int temp=arr[x][y];
	           arr[x][y]=arr[y][n-x-1];
	           arr[y][n-x-1]=arr[n-x-1][n-y-1];
	           arr[n-x-1][n-y-1]=arr[n-y-1][x];
	           arr[n-y-1][x]=temp;
	       }
	   }
	   
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<n;j++)
	       {
	           cout<<arr[i][j]<<" ";
	       }
	   }
	   cout<<endl;
	}
	return 0;
}