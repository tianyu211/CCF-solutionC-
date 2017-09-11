#include <bits/stdc++.h> 
using namespace std;
int a[1001];
int flag[1001]={0};
int num=0;
int i,j,n;

bool find(int x){
	if(flag[x])	
		return false;
	flag[x]	= 1;
	int big=0,sml=0;
	for(j=1;j<=n;j++){
		if(a[j] > x)
			big++;
		if(a[j] < x)
			sml++;
	}
	if(big == sml && big!=0){
		num++;
		return true;
	}	
	return false;
}


int main(){
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	
	for(i=1;i<=n;i++){
		if(find(a[i])){
			cout<<a[i]<<' ';
		}
	}
	if(num == 0)
		cout<<-1;
	
	return 0;
}
