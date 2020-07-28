#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void length(string &s){
    int n = s.size(),j=0;
    for(int i=0;i<n;i++){
        int count =1;
        while(i<n-1 && s[i]==s[i+1]){
            count++;
            i++;
        }
        if(count ==1){
            s[j]=s[i];
    
            j++;
            s.insert(j,1,'1');
            j++;
            i++;
            n = n+1;

        }

        else{ 
            s[j]=s[i];
            int one_extra_step =0,l,r;
            while(count>0){
              int temp = count%10;
              if(temp==0){
                  l = j+1;
                  one_extra_step = 1;
                  
              }
            s += temp+'0';
            swap(s[++j],s[n]);
            s.erase(s.begin()+n);
            count /= 10;
        }
        if(one_extra_step==1){
            for(l,r=j;l<r;l++,r--){
                swap(s[l],s[r]);
            }
        }
        j++;
        }
    }
    
    s.erase(j);
}
int main() {
	string s;
	cout<<"Enter the string :- ";
	cin>>s;
	length(s);
	cout<<"After runlength encoding :- "<<s;
	return 0;
}
