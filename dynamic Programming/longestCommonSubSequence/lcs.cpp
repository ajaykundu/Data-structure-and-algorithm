#include <iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}


int lcs(char *s1,char *s2,int n1,int n2)
{
	int dp[n1+1][n2+1];

	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}
			else if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else {
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	return dp[n1][n2];
}

int main(int argc, char const *argv[])
{   
	 int n1,n2;
	 cin>>n1>>n2;
	 char s1[n1];
	 char s2[n2];
	 cin>>s1>>s2;
	 cout<<lcs(s1,s2,n1,n2);
	
	return 0;
}