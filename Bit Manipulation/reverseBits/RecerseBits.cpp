#include <iostream>
using namespace std;

unsigned int reverseBits(unsigned int num)
{
    unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0, i, temp;
 
    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
  
    return reverse_num;
}
 
unsigned int neiveApproach(unsigned int num)
{
	int v=num;
	int r=v;
	int s=sizeof(v)*8 -1;

	for(v=v>>1;v;v>>=1)
	{
		r<<=1;
		r|=v&1;
		s--;
	}
	r<<=s;
	return r;

}


/* Driver function to test above function */
int main()
{
    unsigned int x = 1; 
    cout<<reverseBits(x)<<endl;

    cout<<"neive Approach :" <<neiveApproach(x);
}