#include <bits/stdc++.h>
using namespace std;
int main(){
	long int num,sum=0;
	cin>>num;
	
	while(num >= 10){
		sum += num%10;
		num = num/10;
	}
	sum += num;
	cout<<sum;
	return 0;
}
