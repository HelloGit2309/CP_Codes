/* This program uses Dijkstra Algorithm to find shortest distance to other nodes from a source node in an weighted 
   undirected graph */
#include<bits/stdc++.h>
using namespace std;
int n;
const int mx = 1e6;
vector<int>dis;
int dfs(vector<pair<int,int>>v[], bool vis[], int s)
{
	queue<int> q;
	vis[s] = true;
	q.push(s);
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(int i = 0; i < v[p].size(); i++)
		{
			pair<int,int> z;
			z = v[p][i];
			int x = z.first;
			int y = z.second;
			dis[x] = min(dis[x],(y + dis[p]));
			if(vis[x] == false)
			q.push(x);
			vis[x] = true;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	// No. of nodes and edges resp.
	cin>>n>>m;
	vector<pair<int,int>> v[n+1];
	dis.resize(n+1);
	for(int i = 0; i <= n; i++)
	dis[i] = INT_MAX;
	cout<<"Enter edges and its weight"<<endl;
	while(m--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	int s;  // Source node to find distances
	cin>>s;
	dis[s] = 0;
	bool vis[n+1] = {false};
	dfs(v,vis,s);
	for(int i = 1; i <= n; i++)
	cout<<i<<" "<<dis[i]<<endl;
}
