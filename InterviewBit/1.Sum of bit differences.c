#include <stdio.h>
int dec2bin(int q)
{
    int r ,count=0;
    while(q!=0)
    {
        r=q%2;
        q=q/2;
        if(r==1)
            count++;
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
	            temp = dec2bin(temp);
	        }
	        sum = sum + temp;
	    }
	    printf("%d\n",sum);
	}
	return 0;
}
