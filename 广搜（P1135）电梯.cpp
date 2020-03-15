#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <iomanip>
using namespace std;
const int Maxn = 210;
int xx[] = {1, -1};
int K[Maxn], ans;
bool flag,vis[Maxn];
int N, A, B;
struct Node
{
	int x, step;
};

int main()
{
	cin >> N >> A >> B;
	for (int i = 1; i <= N; i++)
		cin >> K[i];
		
	queue<Node> Q;
	Q.push((Node){A, 0});
	vis[A]=true;
	while (!Q.empty())
	{	
		if (Q.front().x == B)
		{
			cout<<Q.front().step+1;
			return 0;
		}
		for (int i = 0; i < 2; i++)
		{
			int layer = Q.front().x+xx[i]*K[Q.front().x];
			if (layer >= 1 && layer <= N&&!vis[layer])
			{	
				vis[layer]=true;
				Q.push((Node){layer, Q.front().step + 1});
			}
		}
		Q.pop();
	}
		cout <<-1;

	return 0;
}

