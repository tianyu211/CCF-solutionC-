#include <bits/stdc++.h> 
using namespace std;

int main(){
	
	int n,i,j; 
	cin>>n;
	
	int height,max=0,area;
	int a[1001];
	
	for(i=1;i<=n;i++) 
		cin>>a[i];
	
	//�����ƽ� 
	for(i=1;i<=n;i++){
		height = a[i];
		for(j=i;j>=1;j--){
			if(a[j] < height)
				height=a[j];
			area = height*(i-j+1);
			if(max < area)
				max=area;
		}
	}
	/*
	//�����ƽ��������򶼿��� 
	for(int i=1; i<=n; i++) {  
        height = a[i];  
        for(int j=i; j<=n; j++) {  
            if(a[j] < height)  
                height = a[j];  
            area = (j - i + 1) * height;  
            if(area > max)  
                max = area;  
        }  
    }  */
	
	
	cout<<max;
	
	return 0;
}
