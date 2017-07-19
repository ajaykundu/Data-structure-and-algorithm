#include <iostream>
using namespace std;

bool checkPowerOf2(int v)
{
	return v && !(v & v-1);
}

int main(int argc, char const *argv[])
{
	int a;
	cin>>a;
	cout<<checkPowerOf2(a);
	return 0;
}