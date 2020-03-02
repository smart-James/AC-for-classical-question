#include<bits/stdc++.h>
using namespace std;
const int Maxn=110;
int n;
char a[Maxn][Maxn];
bool vis[Maxn][Maxn];
int xx[8]={1,0,-1,0,1,1,-1,-1};//八个方向 
int yy[8]={0,1,0,-1,1,-1,-1,1};
string yz="yizhong";
void dfs(int x,int y);
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
			
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]=='y')
			{
				dfs(i,j);	
			}	
		}	
	}
					
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(!vis[i][j])
				cout<<'*';
			else 
				cout<<a[i][j];
		cout<<endl;	
	}
	return 0;
}
void dfs(int x,int y){
	
	for(int i=0;i<8;i++)
	{	
		int flag=1;
		for(int j=0;j<7;j++)
		{	
			int dx=x+j*xx[i];//i代表地几个方向，j代表在i方向上搜索了几步； 
			int dy=y+j*yy[i];	
			if(!(dx>=1&&dx<=n&&dy>=1&&dy<=n)||yz[j]!=a[dx][dy]){ 
				flag=0;
				break;
				} 
		}
		if(flag)
		{
			for(int j=0;j<7;j++)
			{
				int dx=x+j*xx[i];
				int dy=y+j*yy[i];
				vis[dx][dy]=1;	
			}		
		}
	}
	
}

