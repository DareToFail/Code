#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n , s;
		scanf("%d%d",&n,&s);
		int a[n];
		for(int j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		int start =0 ,end =0,sum=0,success=0;
		sum = sum + a[end];
		for(;end<n;){
			if(sum==s){
				printf("%d %d\n",start+1,end+1);
				success = 1;
				break;
			}
			else if(sum<s){
				sum = sum + a[++end];
			}
			else{
				sum = sum - a[start++];
			}
		}
		if(sum>s){
			for(;start!=end;){
				sum = sum - a[start++];
				if(sum==s){
					printf("%d %d\n",start+1,end+1);
					success = 1;
					break;
				}
				else if(sum<s){
					break;
				}
			}
		}
		if(success==0){
			printf("-1\n");
		}
	}

    return 0;
}
