#include <iostream>
#include <string>
using namespace std;

bool checkindic(string str,string dic[],int sizedic){
         
        
	for(int i=0;i<sizedic;i++)
	{    
		if(str.compare(dic[i])==0)
			return true;
	}
	return false;
}

bool wordbreak(string str,int n,string dic[],int sizedic)
{
	bool dp[n+1];
	dp[0]=true;

	for(int i=1;i<n;i++)
	{
		int j=i-1;
		for(;j>=0;j--)
		{
			if(dp[j]=true)
			{
				if(checkindic(str.substr(j,i-j),dic,sizedic))
				{ 
					cout<<str.substr(j,i-j)<<endl;
					dp[i]=true;
					break;
				}
			}
		}
		if(j==-1)
		{
			dp[i]==false;
		}
	}
	for(int i=0;i<=n;i++)
	{
		cout<<dp[i]<<" ";
	}
   return dp[n];
}

int main(int argc, char const *argv[])
{
	string dictionary[]={"i","like","sum","sung","samsung","mobile","ice","cream","icecream","man","go","mango"};
     
     int sizeofDictionary=sizeof(dictionary)/sizeof(dictionary[0]);

     cout<<sizeofDictionary;
     
     string str="ilikesamsung";

    cout<<endl;
     cout<<wordbreak(str,str.length(),dictionary,sizeofDictionary);

	return 0;
}