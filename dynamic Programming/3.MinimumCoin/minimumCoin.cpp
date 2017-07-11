#include <iostream>
#include <limits.h>
using namespace std; 

int min(int a,int b)
{
	return a>b?b:a;
}

int MinimumCoin(int coins[],int n,int v)
{
	int table[v+1];
	table[0]=0;
	for (int i = 0; i <=v; ++i)
	{
		table[i]=INT_MAX;
	}

	for (int i = 1; i <=v; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(coins[j]<=i)
			{
				int sub=table[i-coins[j]];
				if(sub!=INT_MAX && sub+1 < table[i])
				{
					table[i]=sub+1;
				}
			}
		}
	}

    for(int i=0;i<=v;i++)
    {
    	cout<<table[i]<<" ";
    }
    cout<<endl;
    return table[v];
}

int main(int argc, char const *argv[])
{
	int coins[]={7,6,5,1};
     int v=11;
     cout<<MinimumCoin(coins,4,v);

	return 0;
}