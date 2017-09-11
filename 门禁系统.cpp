#include <bits/stdc++.h> 
using namespace std;


int main(){
	
	int n,i;
	int a;
	int num[1001]={0};
	
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a;
		num[a]++;
		cout<<num[a]<<' ';
	}
	
	return 0;
}

