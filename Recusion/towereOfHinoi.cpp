#include <iostream>
#include<stdio.h>
using namespace std;

void toh(int n,char s,char d,char h)
{
	if(n==0)
		return;
	toh(n-1,s,h,d);
    cout<<n<<" "<<s<<" "<<d<<endl;
	toh(n-1,h,d,s);
}

int main(int argc, char const *argv[])
{
	int n;cin>>n;

	toh(n,'A','B','C');
	return 0;
}