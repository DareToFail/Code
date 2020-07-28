#include <stdio.h>
#include<math.h>
int hamming_distance(int q)
{
    int count=0;
	while(q)
	{
		count = count + (q&1); // bitwise and operator(counting no. of 1)
		q = q>>1; //right shift i.e.dividing by 2(result is quotient)
	}
    return count;
}
int main() {
	//code
	int t,n,sum,temp;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    sum = 0;
	    scanf("%d",&n);
	    int a[n];
	    for(int j=0;j<n;j++)
	        scanf("%d",&a[j]);
	    for(int j=0;j<n;j++)
	    for(int k=0;k<n;k++)
	    {
	        temp=0;
	        if(j!=k)
	        {
	            temp = a[j]^a[k];
	            temp = hamming_distance(temp);
	        }
	        sum = sum + temp;
	    }
	    printf("%d\n",sum);
	}
	return 0;
}
