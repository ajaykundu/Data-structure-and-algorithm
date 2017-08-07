#include <iostream>
using namespace std;

int countInstance(char *str,char needle)
{
	
	if(str[0]=='\0')
		return 0;
	 return ((str[0]==needle) + countInstance(str+1,needle));
	}

int main(int argc, char const *argv[])
{
	
	return 0;
}