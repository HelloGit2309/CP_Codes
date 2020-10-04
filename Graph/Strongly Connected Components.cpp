/* Strongly Connected Components using Kosaraju's Algorithm */

#include<bits/stdc++.h>
using namespace std;
vector<int>p;
int dfs(vector<int>v[],int n,bool vis[])
{
	if(vis[n] == false)
	{
		vis[n] = true;
		for(int i = 0; i < v[n].size(); i++)
		{
			int y = v[n][i];
			if(vis[y] == false)
			{
				dfs(v,y,vis);
			}
		}
	}
	p.push_back(n);
}
void dfs1(vector<int>v[],int n, bool vis[])
{
	stack<int>s;
	s.push(n);
	while(!s.empty())
	{
		int p = s.top();
		s.pop();
		for(int i = 0; i < v[p].size(); i++)
		{
			int y = v[p][i];
			if(vis[y] == false)
			{
				vis[y] = true;
				s.push(y);
			}
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<int>v[n+1],g[n+1];
	while(m--)
	{
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		g[b].push_back(a);
	}
	bool vi[n+1] = {false};
	for(int i = 1; i <= n; i++)
	{
		if(vi[i] == false)
		dfs(v,i,vi);
	}
	reverse(p.begin(),p.end());
	bool vis[n+1] = {false};
	int count = 0;
	for(int i = 0 ; i < p.size(); i++)
	{
		int y = p[i];
		if(vis[y] == false)
		{
			++count;
			dfs1(g,y,vis);
		}
	}
	cout<<count;
}
