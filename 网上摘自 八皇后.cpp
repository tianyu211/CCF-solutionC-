#include<stdio.h>
#include<windows.h>
#define N 8 
int count = 0;
int chess[N][N] = {0};
int sum[100]={0};

//�ж�
int check(int i, int j)
{	
	if(i == 0)
		return 0;
  
	int k = 0;
	for(k = 0; k<i ; k++)
	{
		if(chess[k][j] == 1)
			return 1;
	}
	for( int s = 0,k = j+1; k<N ;k++)
	{	
		if(chess[i-s-1][k] == 1)
			return 1;
		s++;
	}
	for(k = 0; k<j ;k++)
	{
		if(chess[i-k-1][j-k-1] == 1)
			return 1;	
	}
	for(k = 0; k<N ; k++)
	{
		if(chess[k][j]==1)
			return 1;
	}
	return 0;
}
//�ж��Ƿ�ȫ������ 
int check_all()
{
	int i = 0;
	int j = 0;
	int flag = 0;
	for(i = 0; i<N ;i++)
	{	
		flag = 0;
		for(j = 0; j<N ; j++)
		{
			if(chess[i][j]==1)
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			return 1;//�д� 
	}
	return 0;
}
//���
int check_line(int line)
{	
	if(line==0)
		return 0;
	int k = 0;
	int s = 0;
	int flag = 1;
	for(s = 0; s<line-1 ; s++)
	{	
		flag = 1;
		for(k = 0; k<N ;k++)
		{
			if(chess[s][k]==1)
				flag = 0;
		}
		if(flag==1)
			return 1;
	}
	return 0;
}
//�ݹ�
void queen(int i,int j)
{		
	if(check_line(i)==1)//�������лʺ󣬷��� 
		return ;
	if((i==(N-1)))//����ʱ�����һ�� 
	{		
		if(check(i,j)==0)//�����һ�еĻʺ���Է��£���ʾ���Գɹ����ã�	
		{
			sum[count] = chess[i][j];
			count++;
			chess[i][j] = 1;
		}
	}		
	if(check(i,j)==0)//�����ԷŻʺ�ʱ 
	{	
		chess[i][j] = 1; 
		queen(i+1,0); 
	}
 	if(j==N) 
		return ;
		
	chess[i][j] = 0;
	queen(i,j+1);
}
int main()
{	
	int p=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<=N;j++){
			//cin>>a[i][j];
			chess[i][j] = p;
			p++;
		}
	}
	queen(0,0);
	for(int i=0;i<100;i++){
		printf("%d\n",sum[i]);
	}
	return 0;
}
