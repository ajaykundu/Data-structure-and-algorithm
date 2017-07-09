#include <iostream>
using namespace std;

int max(int a,int b)
{  
    if(a>b)
    return a;
    return b;
}

int knapsack(int *val,int *weight,int n,int w)
{
	int arr[w+1][n+1];

	for(int i=0;i<=w;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
			{
				arr[i][j]=0;
			}
			else if(weight[j-1]<=i)
			{
              arr[i][j]=max(arr[i][j-1],val[j-1]+arr[i- weight[j-1]][j-1]);
			}
			else {
				arr[i][j]=arr[i][j-1];
			}
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return arr[w][n];
}



int main(int argc, char const *argv[])
{
       int val[]={100,30,120,200};
       int wt[]	={2,1,3,5};

       int w=6;
       cout<<knapsack(val,wt,4,w);
	return 0;
}


