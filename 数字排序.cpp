#include <bits/stdc++.h> 
using namespace std;
int num[1001];
int a[1001][2]={0};

void swap(int a[2],int b[2]){
	int temp;
	for(int i=0;i<=1;i++){
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}


int main(){
	
	freopen("./input/szpx.txt","r",stdin) ;
	
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>num[i];
	
	//整理数据存入 a[][]数组中  第一维是数字，第二维是次数 
	for(i=0;i<n;i++){
		for(j=1;j<=1000;j++){
			//数字是从小到大的 
			if(num[i] == j){
				a[j][0] = j;
				a[j][1] ++ ;
			}
		}
	}
	
	for(i=1;i<=1000;i++){
		//查看哪个数的次数最多
		for(j=i;j<=1000;j++){
			//次数不相同 
			if(a[j][1] > a[i][1]){
				//把次数由大到小排序 
				swap(a[i],a[j]);
			}
			//如果次数相同 
			while(a[i][1] == a[j][1]) {
				if(a[i][0] > a[j][0]){
					swap(a[i],a[j]);
				} 
				break;
			}
		}
	}
	
	//输出出来 
	for(i=1;i<=n && a[i][0]!=0;i++){
		cout<<a[i][0]<<' '<<a[i][1]<<endl;
	}
	
	return 0;
}
