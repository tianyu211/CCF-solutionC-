#include <bits/stdc++.h>
using namespace std;
int t,a,tax;

int main(){
	
	cin>>tax;
	
	
	for(int i=1;i<=1000000;i++) {
		a=i-3500;
		if(i <= 3500){
			t = i;
		}else if(a<=1500){
			t = i - a*0.03;
		}else if(a>1500 && a<=4500){
			t = i - 1500*0.03 - (a-1500)*0.1;
		}else if(a>4500 && a<=9000){
			t = i - 1500*0.03 - 3000*0.1 - (a-4500)*0.2;
		}else if(a>9000 && a<=35000){
			t = i - 1500*0.03 - 3000*0.1 - 4500*0.2 - (a-9000)*0.25;
		}else if(a>35000 && a<=55000){
			t = i - 1500*0.03 - 3000*0.1 - 4500*0.2 - 26000*0.25 - (a-35000)*0.3;
		}else if(a>55000 && a<=80000){
			t = i - 1500*0.03 - 3000*0.1 - 4500*0.2 - 26000*0.25 - 20000*0.3 - (a-55000)*0.35;
		}else{
			t = i - 1500*0.03 - 3000*0.1 - 4500*0.2 - 26000*0.25 - 20000*0.3 - 25000*0.35 - (a-80000)*0.45;
		}
		
		if(t == tax){
			cout<<i<<endl;
			return 0;
		} 
	}
	
	return 0;
}
