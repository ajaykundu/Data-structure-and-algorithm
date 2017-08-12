#include<iostream>
#include<utility>
#include<math.h>
using namespace std;

int diffmax(int arr[],int n)
{
    int lastindex=n-1;
    int diff=arr[n-1]-arr[n-2];
    
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>arr[lastindex])
        {
            lastindex=i;
        }
        else if(diff<(arr[lastindex]-arr[i]))
        {
            diff=arr[lastindex]-arr[i];
        }
    }
    return diff;
}

int main()
 {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<diffmax(arr,n)<<endl;
	}
	return 0;
}