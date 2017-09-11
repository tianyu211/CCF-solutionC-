#include <bits/stdc++.h> 
using namespace std;

int main(){
	
	int n,s;
	int num[10001]={0};
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>s;
		num[s]++;
	}
	
	int max=0;	//代表出现的次数 
	int sum;
	for(int i=10000;i>=1;i--){
//		max = num[i] >= max ? num[i] : max;
		if(num[i] >= max){
			max = num[i];
			sum=i;
		}
	}	
	
	cout<<sum;
	
	return 0;
}	


