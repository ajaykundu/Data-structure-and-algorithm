#include <iostream>
using namespace std;

int powerModulo(int n,int d)
{
     return (n&(d-1));

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int d;
	cout<<"Enter the 2^n divisor : ";
	cin>>d;
	cout<<powerModulo(n,d)<<endl;
	return 0;
}