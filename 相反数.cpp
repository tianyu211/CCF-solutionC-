#include <bits/stdc++.h> 
using namespace std;

int main(){
	
	int n,num=0;
	int a[501];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		for(int j=1;j<i;j++){
			if(!(a[i] + a[j]))	num++;
		}
	}
	
	cout<<num;
	
	return 0;
}

