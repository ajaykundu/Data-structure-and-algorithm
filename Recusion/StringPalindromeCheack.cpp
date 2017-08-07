#include <iostream>
using namespace std;

int PalidromeCheck(char* str,int len)
{
     if(len<2)
     {
     	return 1;
     }
     if(str[0]!=str[len-1])
     	return 0;
	return PalidromeCheck(str+1,len-2);
}

int main(int argc, char const *argv[])
{
	char str[]="aa";
	cout<<PalidromeCheck(str,2);
	return 0;
}