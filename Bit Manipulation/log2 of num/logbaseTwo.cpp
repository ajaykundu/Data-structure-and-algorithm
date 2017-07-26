#include <iostream>
using namespace std;

int logbasetwo(int num)
{
	int r=0;  //value of num log base two.

	while(num=num>>1)
	{
		r++;
	}

	return r;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

	cout<<logbasetwo(n)<<endl;
	return 0;
}