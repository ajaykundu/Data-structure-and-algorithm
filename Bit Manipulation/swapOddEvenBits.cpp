#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int input;
	cout<<"Enter Input Number: ";
	cin>>input;

	int maskEven=0xAAAAAAAA;
	int maskOdd=0x55555555;
	int rightS=(input & maskEven)>>1;
	int leftS=(input & maskOdd)<<1;

	int resultout=(rightS | leftS);
	cout<<"Output : ";
	cout<<resultout;
	return 0;
}