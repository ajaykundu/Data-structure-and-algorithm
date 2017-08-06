#include <iostream>
using namespace std; 

void reverseStr(char str[],int len)
{
	if(len<2)
		return;

	char temp=str[0];
	str[0]=str[len-1];
	str[len-1]=temp;
	reverseStr(str+1,len-2);
}

int main(int argc, char const *argv[])
{
	char str[]="abcdef";
	cout<<str<<endl;
	reverseStr(str,6);
	cout<<str<<endl;
	return 0;
}