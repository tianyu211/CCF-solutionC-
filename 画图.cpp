#include <bits/stdc++.h> 
using namespace std;

int main(){
	
	int a[101][101]={0};
	int n,num=0;
	int x1,y1,x2,y2;
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x1>>y1>>x2>>y2;
		for(int j=x1;j<x2;j++){
			for(int k=y1;k<y2;k++){
				if(!a[j][k]){
					a[j][k]=1;
					num++;
				}
			}
		}
	}
	
	cout<<num;
	return 0;
}

