#include <iostream>
using namespace std;

bool SubsetSum(int set[],int n,int sum)
{
	int dp[sum+1][n+1];
       
       //if the sum is zero the the anser is alway true.
	for(int i=0;i<=n;i++)
	{
		dp[0][i]=true;
	}
	//if the only value in set is 0 than all the value for sum > 0 are false;
	for(int i=1;i<=sum;i++)
   {
   	dp[i][0]=false;
   }

     for(int i=1;i<=sum;i++)
     {
     	for(int j=1;j<=n;j++)
     	{
            dp[i][j]=dp[i][j-1];
            if(i>=set[j-1])
            {
            	dp[i][j]=(dp[i][j] || dp[i-set[j-1]][j-1]);
            }
     		
     	}
     }

    
     return dp[sum][n];
}

int main(int argc, char const *argv[])
{
	int set[]={3,34,4,12,5,2};
	int sum=200;

	cout<<SubsetSum(set,6,sum);
	return 0;
}