#include <iostream>
#include <algorithm>
using namespace std;

struct job
{
	int starttime;
	int finishtime;
	int profit;
	void setvalues(int a,int b,int c)
	{
		starttime=a;
		finishtime=b;
		profit=c;
	}
};

bool jobcomparator(job a,job b)
{
	return (a.finishtime < b.finishtime);
}

int max(int a ,int b)
{
	return a>b?a:b;
}

int findMaxprofit(job arr[],int n)
{
	sort(arr,arr+n,jobcomparator);
    
    int dp[n];
    dp[0]=arr[0].profit;

    for(int i=1;i<n;i++)
    {
    	int inclProf=arr[i].profit;
    	int l=i-1;
    	for(l;l>=0;l--)
    	{
               if(arr[l].finishtime <= arr[i].starttime)
               {
               	break;
               }
    	}

    	if(l!=-1)
    	{
    		inclProf+=dp[l];
    	}
    	dp[i]=max(dp[i-1],inclProf);

    }

    return dp[n-1];
}



int main(int argc, char const *argv[])
{
    job arr[4];
    arr[0].setvalues(1,2,50);
    arr[1].setvalues(3,5,20);
    arr[2].setvalues(6,19,100);
    arr[3].setvalues(2,100,200);

    cout<<findMaxprofit(arr,4);
	return 0;
}