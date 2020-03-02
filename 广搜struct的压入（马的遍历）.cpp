#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;
const int maxn=410;
int n,m,mx,my;
int a[maxn][maxn];
const int xx[10]={0,2,-2,2,-2,-1,1,-1,1};
const int yy[10]={0,1,1,-1,-1,2,2,-2,-2};
struct Node{
	int x,y,depth;
};
int main(){
	cin>>n>>m>>mx>>my;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=-1;
	//	也可以	memset( mp, -1, sizeof(mp) );
	//	需要加头文件  #include<cstring>
	queue<	Node > Q;			
	Node t;						//	也可以写成 
	t.x=my;t.y=my;t.depth=0;	//	Q.push((Node){mx,my,0});
	Q.push(t);
	a[mx][my]=0;
	
	while(!Q.empty()){
		for(int i=1;i<=8;i++)
		{
			int dx=Q.front().x+xx[i];
			int dy=Q.front().y+yy[i];
			if(a[dx][dy]==-1&&dx>=1&&dy>=1&&dx<=n&&dy<=m)
			{	
				Q.push((Node){dx,dy,Q.front().depth+1});
				a[dx][dy]=Q.front().depth+1;
			}			
		}
		Q.pop();
	} 
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cout<<left<<setw(5)<<a[i][j];
			//	setw() 头文件： #include<iomanip>
		cout<<endl;
	}

	return 0;
}
