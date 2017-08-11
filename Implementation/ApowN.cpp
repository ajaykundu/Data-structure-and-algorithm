#include <iostream>
using namespace std;

double poewerfun(int A,int n)
{
	if(A==0)
		return 0;
	if(n==0)
		return 1;
	cout<<"hello"<<endl;
	double temp=poewerfun(A,n/2);

	if(n%2==0)
	{
		return temp*temp;
	}
	else {
		if(n>0)
		{
			return A*temp*temp;
		}
		else {
			return (temp*temp)/A;
		}
	}
}

int main(int argc, char const *argv[])
{
	cout<<poewerfun(2,1000)<<endl;
	cout<<poewerfun(2,-4);
	return 0;
}