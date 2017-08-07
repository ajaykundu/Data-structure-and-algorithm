#include <iostream>
using namespace std;

void swap(char &a,char &b)
{
	char temp=a;
	a=b;
	b=temp;
}

void print(char *str)
{
	for(int i=0;str[i]!='\0';i++)
	{
		cout<<str[i];
	}
	cout<<endl;
}

void permutestr(char *str,int n,int l=0)
{
	if(l==n)
	{  print(str);
		return;
	}
	
   for(int i=l;i<n;i++)
   {
   	  swap(str[i],str[l]);
   	   permutestr(str,n,l+1);
       swap(str[i],str[l]);
   } 
}

int main(int argc, char const *argv[])
{
	char str[]="abcd";
	permutestr(str,4);
	return 0;
}