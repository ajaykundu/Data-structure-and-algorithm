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

int DpMethod(int v)
{
	//we will create a table for value ranging from 0 to 255.
   int dptablefor256[256];
     dptablefor256[0]=0;

   for(int i=0;i<256;i++)
   {
   	  dptablefor256[i]=(i & 1) + dptablefor256[i/2];
   }

   int nowCounter=0;
   nowCounter=dptablefor256[(v & 0xff)] + dptablefor256[(v>>8) && 0xff] + dptablefor256[(v>>16) && 0xff] + dptablefor256[(v>>24)];
   
     return nowCounter;
}

int main(int argc, char const *argv[])
{
	int enterNum;  //enter the number whose set bits you want to calculate.
	cin>>enterNum;

	cout<<"Number of set Bits by Naive Method : ";
      cout<<SetBitsNaive(enterNum)<<endl;

      cout<<"Number of set bits by Dp Method : ";
      cout<<DpMethod(enterNum)<<endl;

	return 0;
}