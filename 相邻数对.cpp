#include <bits/stdc++.h> 
using namespace std;

int main(){
	int n,num=0;
	int a[1001]={10086};
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		for(int j=1;j<i;j++){
			if(abs(a[j] - a[i]) == 1){
				num++;
			}
		}
	}
	
	cout<<num;
	
	return 0;
}

