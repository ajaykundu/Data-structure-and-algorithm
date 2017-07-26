#include <iostream>
using namespace std;

int CountTrailingZeroes(int num)
{
	int c=0;

	if(num)
	{
		num=(num^(num-1))>>1;
		for(c=0;num;c++)
		{
			num>>=1;
		}
	}
	else
	{
		c=8*sizeof(num);
	}
	return c;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	cout<<CountTrailingZeroes(n)<<endl;
	return 0;
}