#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int DP[maxn][1010];//也可以开两个一维数组；  一个是种类，一个是重量 
int ti[maxn],ci[maxn];
int main(){

	int t,m;
	cin>>t>>m;
	for(int i=1;i<=m;i++)
		cin>>ti[i]>>ci[i];
		
	for(int i=1;i<=m;i++){
		
		for(int v=t;v>0;v--)
		{
		
			if(ti[i]<=v)
				DP[i][v]=max(DP[i-1][v],DP[i-1][v-ti[i]]+ci[i]);
				
			else DP[i][v]=DP[i-1][v];
		} 
	}	
			
	printf("%d",DP[m][t]);

	return 0;
}

