#include <bits/stdc++.h>
using namespace std;
int t[20][11];
int n[5][5];
int col,tc,tr;
int i,j,temp,dy=0;

/*
	�������
	���������ж� 
	�����ĳ���ط���ֵΪ2
	�Ͳ����ϣ����� 
*/

void init(){
	//����ͼ 
	for(i=1;i<=15;i++){
		for(j=1;j<=10;j++){
			cin>>t[i][j];
		}
	}
	//���ͼ 
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++){
			cin>>n[i][j];
		}
	}
	//��ʼ���� 
	cin>>col;
}

bool judge(int x,int y){
	//������� 
	//���ǻ�Ҫ���ǰ��ͼ���һ��ȫ��0
	int zero=0; 
	while(y>0){
		for(j=1;j<=4;j++){
			tc = col+j-1;	//����ͼ������ 
			temp = t[x][tc] + n[y][j];
			if(temp > 1){
				return false;
			}
		}
		judge(--x,--y);
	}
	return true;
} 

void useless(){
	int useless=0;
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++){
			if(n[i][j] == 0){
				useless++;
				if(useless == 4){
					dy=dy+1;
					useless=0;
				}
			}else{
				return;
			}
		}
	}
}

void change(int x){
	useless();
	//x�ǿ��õķ���ͼ����
	for(i=1;i<=4;i++) {
		tr = x-i+1+dy;	//��ʵ���� 
		for(j=1;j<=4;j++){
			tc = col+j-1;	//����ͼ������ 
			t[tr][tc] = t[tr][tc] + n[5-i][j];
		}
	}
	//��� 
	for(i=i;i<=15;i++){
		for(j=1;j<=10;j++){
			cout<<t[i][j]<<' ';
		}
		cout<<endl;
	}
}

int main(){
	
	freopen("./input/els.txt","r",stdin);//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	init();
	for(i=15;i>=1;i--) { 
		if(judge(i,4)){
			change(i);
			return 0;
		}
	}
}

