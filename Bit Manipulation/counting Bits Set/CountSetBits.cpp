#include <iostream>
using namespace std;

int SetBitsNaive(int num)
{
	int counter=0; // counter for number of set bits.

	for(;num>0;num>>=1)
	{
		counter+= num & 1;
		
	}
	return counter;
}

int main(int argc, char const *argv[])
{
	int enterNum;  //enter the number whose set bits you want to calculate.
	cin>>enterNum;

	cout<<"Number of set Bits by Naive Method :";
      cout<<SetBitsNaive(enterNum);

	return 0;
}