#include <iostream>
#include <vector>
using namespace std;

bool subsetUtil(int set[],int n,int sum,vector<int> &v)
{     
       int dp[sum+1][n+1];
       for(int i=0;i<=n;i++)
       {
       	   dp[0][i]=1;
       }
       for(int i=1;i<=sum;i++)
       {
       	dp[i][0]=0;
       }

       for(int i=1;i<=sum;i++)
       {
       	    for(int j=1;j<=n;j++)
       	    {
       	    	dp[i][j]=dp[i][j-1];
       	    	if(set[j-1]<=i)
       	    	{
       	    		dp[i][j]=dp[i][j] || dp[i-set[j-1]][j-1];
       	    	}
       	    }
       }
     //collecting output from the given set.
       int p=sum,q=n;
     
      while(p>0)
      {
      	   while(dp[p][q]==dp[p][q-1] && q>0)
      	   {  
               q--;
      	   }
      	   if(q!=0)
      	   {  
               v.push_back(set[q-1]);
      	   }
      	   p=p-set[q-1];
      	   q--;
      }
       return dp[sum][n];
}

bool subset(int set[],int n,int sum)
{
	std::vector<int> v;
	if(subsetUtil(set,n,sum,v))
	{  
		std::vector<int>::iterator itr;
		for(itr=v.begin();itr!=v.end();itr++)
		{
			cout<<*itr<<" ";
		}
		cout<<endl;
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{ 
	 int set[] = {3, 34, 4, 13, 5, 2};
	 int sum=100;
	 cout<<subset(set,6,sum);
	return 0;
}