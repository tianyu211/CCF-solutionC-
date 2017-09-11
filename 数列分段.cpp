#include <bits/stdc++.h> 
using namespace std;


int main(){
	
	int n,num=1;
	int a[1001];
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1 && a[i] != a[i-1]){
			num++;
		}
	} 
	
	cout<<num;
	return 0;
}
