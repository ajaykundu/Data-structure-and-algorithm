#include <iostream>
using namespace std;

int checkcharSer(char* str,char *set)
{
    if(set[0]=='\0')
    {
    	return 1;
    }

    if(str[0]=='\0')
    {
    	return 0;
    }

	if(str[0]==set[0])
	{
		return checkcharSer(str+1,set+1);
	}
	else {
		return checkcharSer(str+1,set);
	}
}

int main(int argc, char const *argv[])
{
	char str[]="helloworld";
	char set[]="owodf";

	cout<<checkcharSer(str,set);
	return 0;
}