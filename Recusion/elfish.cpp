#include <iostream>
using namespace std;

//we use binary representation here so that i can use it in e=4 l=2 and f=1.

int elfish(char *str,int needlemask=0)
{
	
    if(needlemask==7)
    {
    	return 1;
    }
    
    if(str[0]=='\0')
		return 0;
    if(str[0]=='e')
    {
    	needlemask=needlemask|4;
    }
    else if(str[0]=='l')
    {
    	needlemask=needlemask|2;
    }
    else if(str[0]=='f')
    {
    	needlemask=needlemask|1;
    }
    
  return elfish(str+1,needlemask);
}

int main(int argc, char const *argv[])
{
	char str[]="hellof";
	int test=0;
	cout<<elfish(str);
	return 0;
}