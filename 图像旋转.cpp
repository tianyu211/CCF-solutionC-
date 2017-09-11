#include <bits/stdc++.h> 
using namespace std;
int a[1001][1001]={0};

int main(){
	int i,j;
	int n,m;
	//freopen("input/txxz.txt","r",stdin);	//!!!!!!!!!!!!!!!!!!!!
	cin>>n>>m;

	for(i=1;i<=n;i++){
		for(j=m;j>=1;j--){
			cin>>a[j][i];	//竖着保存，横着输出 
		}
	}
	
	for(i=1;i<=m;i++){	//行变成列 
		for(j=1;j<=n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
