#include <iostream>
using namespace std;

int maxsum(int arr[],int n)
{
	int incl=arr[0];
	int excl=0;
	int new_excl;

	for(int i=1;i<n;i++)
	{
		new_excl=(incl>excl)?incl:excl;
        incl=excl+arr[i];
        excl=new_excl;
	}
	return incl>excl?incl:excl;
}

int main(int argc, char const *argv[])
{
	int arr[]={3,2,5,10,7};
	cout<<maxsum(arr,5);
	return 0;
}