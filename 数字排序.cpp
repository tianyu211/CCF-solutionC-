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
	
	//�������ݴ��� a[][]������  ��һά�����֣��ڶ�ά�Ǵ��� 
	for(i=0;i<n;i++){
		for(j=1;j<=1000;j++){
			//�����Ǵ�С����� 
			if(num[i] == j){
				a[j][0] = j;
				a[j][1] ++ ;
			}
		}
	}
	
	for(i=1;i<=1000;i++){
		//�鿴�ĸ����Ĵ������
		for(j=i;j<=1000;j++){
			//��������ͬ 
			if(a[j][1] > a[i][1]){
				//�Ѵ����ɴ�С���� 
				swap(a[i],a[j]);
			}
			//���������ͬ 
			while(a[i][1] == a[j][1]) {
				if(a[i][0] > a[j][0]){
					swap(a[i],a[j]);
				} 
				break;
			}
		}
	}
	
	//������� 
	for(i=1;i<=n && a[i][0]!=0;i++){
		cout<<a[i][0]<<' '<<a[i][1]<<endl;
	}
	
	return 0;
}
