#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int max,temp;
	int i,j,n,a[1001];
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		while(i>1){
			j=i-1;
			
			temp = abs(a[i]-a[j]);
			max = temp>max ? temp:max;
			break;
		}
	}
	
	cout<<max;
	return 0;
}
