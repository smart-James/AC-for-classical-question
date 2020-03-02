#include<iostream>
#include<queue>
using namespace std;
const int maxn=35;
int xx[]={1,0,-1,0};
int yy[]={0,1,0,-1};
int mp[maxn][maxn];
bool vis[maxn][maxn];
int n;
int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	
	queue< int >x;
	queue< int >y;
	
	x.push(0);y.push(0);
	vis[0][0]=1;
	
	while(!x.empty()){
		

		for(int i=0;i<4;i++){
			int dx=x.front()+xx[i];
			int dy=y.front()+yy[i];
			if(!mp[dx][dy]&&!vis[dx][dy]&&dx>=0&&dy>=0&&dx<=n+1&&dy<=n+1)
			{
				vis[dx][dy]=1;
				x.push(dx);
				y.push(dy);
			}
		}
		x.pop();
		y.pop();
	}
		for(int i=1;i<=n;i++){
		
			for(int j=1;j<=n;j++)
			if(!vis[i][j]&&mp[i][j]!=1)
				cout<<'2'<<' ';
				else 
				cout<<mp[i][j]<<' ';
			cout<<endl;
		}
	return 0;
}
