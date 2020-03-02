#include<bits/stdc++.h>
using namespace std;
int n,ans;
int use[25],Max;
string a[25];
void dfs(string x,int s);
int main(){
	char t;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	cin>>t;
	for(int i=1;i<=n;i++)
	{
		if(a[i][0]==t)
		{
			use[i]++;
			dfs(a[i],a[i].length());
			use[i]--;
		}
	}	
	cout<<Max;
	return 0;
}
int max(int a,int b){
	if(a>b)return a;
	return b;	
}
int min(int a,int b){
	if(a<b)return a;
	return b;	
}
void dfs(string x,int s){
	
	Max=max(s,Max);
	
	for(int i=1;i<=n;i++)
	{
		int p=1,flag=0;
		int la=x.length(),lb=a[i].length();
		while(p<min(la,lb))
		{
			// a.substr(x,y) 是a数组的一个子数列 x是起始位置，
			//y是终点位置（如果不写y，则默认到a数组末结束） 
			if(use[i]<2&&x.substr(la-p) == a[i].substr(0,p))
			{	
				use[i]++;
				dfs(a[i],s+lb-p);
				use[i]--;
				break;
			}
			p++;
		}
	}
}


