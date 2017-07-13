#include <iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int highLowEffortTask(int lt[],int ht[],int n)
{
	int pre_pre=0;
	int pre=lt[0]>ht[0]?lt[0]:ht[0];
	int curr;

	for(int i=1;i<n;i++)
	{
		// curr=ht[i]+pre_pre;
        
  //       if(curr<pre+lt[i])
  //       {
  //       	pre_pre=pre;
  //       	pre=pre+lt[i];
  //       }else
  //       {
  //       	pre_pre=pre;
  //       	pre=curr;
  //       }

        curr=max(ht[i]+pre_pre,lt[i]+pre);
        pre_pre=pre;
        pre=curr;
	}

	return pre_pre>pre?pre_pre:pre;
}

int main(int argc, char const *argv[])
{
    int lt[]={1,5,4,5,3};
    int ht[]={3,6,8,7,6};

    cout<<highLowEffortTask(lt,ht,5);	
	return 0;
}