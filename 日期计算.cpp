#include <bits/stdc++.h> 
using namespace std;


int main(){
	
	int y,d;
	int r=0;
	int mon[2][13] = {{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};
	cin>>y>>d;
	
	//ÅÐ¶ÏÊÇ·ñÈòÄê
	if((y%4 == 0 && y%100 != 0) || y%400 ==0)  r=1;

	int m=1;
	while(d > mon[r][m]){
		d -= mon[r][m];
		m++;
	}
	cout<<m<<endl<<d;
	
	return 0;
}

