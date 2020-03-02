#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int Maxn=35;
int n,a[Maxn],root[Maxn][Maxn];
ll dp[Maxn][Maxn];
void dgTree(int L,int R);
ll dfs(int L,int R);
int main(){
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		dp[i][i]=*(a+i);
		root[i][i]=i;
	}
	
	printf("%lld\n",dfs(1,n));	
	
	dgTree(1,n);
	
	return 0;
}
void dgTree(int L,int R){
	
	if(L>R)return ;
	printf("%d ",root[L][R]);
	dgTree(L,root[L][R]-1);
	dgTree(root[L][R]+1,R);
}
ll dfs(int L,int R){
	
	if(L>R)return 1;
	if(dp[L][R])return dp[L][R];
	ll maxn=0;
	
	for(int i=L;i<=R;i++)
	{
		ll t=dfs(L,i-1)*dfs(i+1,R)+a[i];
		if(t>maxn)
		{
			maxn=t;
			root[L][R]=i;
		}
	}
	return dp[L][R]=maxn;
	
}

