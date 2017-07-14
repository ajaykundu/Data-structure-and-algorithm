#include <iostream>
#include <string>
#include <map>
#include <cstring>
using namespace std;

bool wordBreak(string str,std::map<string,int>& map)
{
	int size=str.size();
	bool dp[size+1];
	
	memset(dp,0,sizeof(dp));
	dp[0]=true;
	for(int i=1;i<=size;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			
			  if(dp[i]==false && dp[j]==true && map[str.substr(j,i-j)])
			  { 
			  	dp[i]=true;
			  	
			  }
		}
	}
	
	return dp[size];
}

int main(int argc, char const *argv[])
{
	string dictionary[]={"i","like","sum","sung","samsung","mobile","ice","cream","icecream","man","go","mango"};
     int sizeofDictionary=sizeof(dictionary)/sizeof(dictionary[0]);
     string str="icesungsum";
    
    std::map<string,int> map;

    for(int i=0;i<sizeofDictionary;i++)
    {
    	map[dictionary[i]]=1;
    }
    
    cout<<wordBreak(str,map);

	return 0;
}