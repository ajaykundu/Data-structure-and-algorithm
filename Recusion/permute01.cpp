#include <iostream>
using namespace std;

void permute01Util(int *arr,int n,int l=0)
{
    if(l==n)
    {
    	for(int i=0;i<n;i++)
    	{
    		cout<<arr[i]<<" ";
    	}
    	cout<<endl;
    	return;
    }
    arr[l]=0;
    permute01Util(arr,n,l+1);
    arr[l]=1;
    permute01Util(arr,n,l+1);
}

void permute01(int n)
{
	int arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=0;
	}
	permute01Util(arr,n);
}

int main(int argc, char const *argv[])
{
	int n;cin>>n;
	permute01(n);
	return 0;
}