#include <stdio.h>

int main() {
	//code
	int t,n,s,success=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
	    scanf("%d%d",&n,&s);
	    int a[n],sum=0;
	    for(int j=0;j<n;j++)
	        scanf("%d",&a[j]);
	    for(int j=0;j<n;j++)
	       { 
	           for(int k=j;k<n;k++)
	             {
	                if(sum<s && success==0)
	                {
	                 sum = sum + a[k];
	                 if(sum==s)
	                    {
	                     printf("%d %d\n",j+1,k+1);
	                     success=1;
	                     sum =0;
	                     break;
	                     }
	                }
	                else 
	                break;
	               
	            }
	            sum =0;
	        if(success==1)
	        {
	            success=0;
	            break;
	        }
	       if(j==n-1 &&success==0)
	            printf("-1\n");
	        }

	}
}
