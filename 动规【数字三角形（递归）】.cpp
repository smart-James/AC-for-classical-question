#include<bits/stdc++.h>
//�����Եݹ���� 
using namespace std;

int D[101][101];//���飺������� 
int maxsum[101][101];//���飺��Ž�� 
int n;
int Maxsum(int i,int j);
int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++){
			cin>>D[i][j];
			maxsum[i][j]=-1;
		}
		
	/*	���������ռ��Ż���ĵ��� 
		int *maxsum;
		maxsum=D[n];
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++){
			maxsum[j]=max(maxsum[j],maxsum[j+1])+D[i][j];
		}
		*/ 
	cout<<Maxsum(1,1)<<endl;		
	
	return 0;
}
int MAX(int i,int j){
	
	if(i>j)return i;
	else return j;
	
}
int Maxsum(int i,int j){
	 
	if(i==n)return D[i][j];
	if(maxsum[i][j]!=-1)return maxsum[i][j];
	else {
		//�Ӻ���ǰ�ƣ����� 
		int x=Maxsum(i+1,j);//ֻ�����·�������б�·� 
		int y=Maxsum(i+1,j+1);
		
		maxsum[i][j]=MAX(x,y)+D[i][j];
		return maxsum[i][j];
	}
	
	
}

