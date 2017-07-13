#include <iostream>
using namespace std;

int min(int a,int b)
{
	return a>b?b:a;
}

int editDistance(char s1[],char s2[],int n1,int n2)
{
	int dp[n1+1][n2+1];

	for(int i=0;i<=n1;i++)
	{
		dp[0][i]=i;
	}
	for(int i=0;i<=n2;i++)
	{
		dp[i][0]=i;
	}

	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else{
				dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));

				dp[i][j]++;
			}
		}
	}
    return dp[n1][n2];
}

int main(int argc, char const *argv[])
{
    char s1[]={'s','u','n','d','a','y'};
    char s2[]={'s','a','t','u','r','d','a','y'};
    cout<<editDistance(s1,s2,6,8);	
	return 0;
}