#include <stdio.h>
int power(long int x, long int y, long int p) 
{ 
    int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y last bit is odd, multiply x with result 
        if (y & 1) //bitwise and operator
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
} 
int main() {
	//code
	int t,result;
	scanf("%d",&t);
	long int a,b,c;
	for(int i=0;i<t;i++)
	{
	    scanf("%ld%ld%ld",&a,&b,&c);
	    result = power(a,b,c);
	    printf("%d\n",result);
	}
	
	return 0;
}
