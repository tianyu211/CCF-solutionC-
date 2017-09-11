#include <bits/stdc++.h>
using namespace std;

struct node{
	char name[200]={0};
	int age;
};


int main(){
	node node1;
//	node1.name = 'haha';//直接赋值出错 ,无法向char类型赋值string 
	strcpy(node1.name,"hahah");
	node1.age = 12;
	
//	cout<<node1.name<<endl<<node1.age<<endl;
//	cout<<sizeof(node1)<<endl;
}
