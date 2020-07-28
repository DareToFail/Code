#include<iostream>
#include<bits/stdc++.h>
#include "cube.h"
using namespace std;
void somefunc(){
};
using mycube::cube;
cube *createpointer(cube *ob){
	ob->setlength(2);
	return ob;
}
int main(){
	cube *ob = new cube;
	cube *c = createpointer(ob);
	somefunc();
	double ans;
	//c.setlength(5.89);
	ans = c->getvolume();
	cout<<ans;
	delete ob;
	ob = nullptr;
	return 0;
}

