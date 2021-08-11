/* This program uses Dijkstra Algorithm to find shortest distance to other nodes from a source node in an weighted 
   undirected graph */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 10000000000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define vint vector<int>
#define vl vector<long>
#define vll vector<long long>
#define um unordered_map
#define pb push_back
#define pll pair<ll,ll>
#define mone cout<<-1<<"\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define nl cout<<"\n"
#define all(x) x.begin(),x.end()
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
#define INF 1000000000000000000
int n;
const ll mx = 1e9;
int dfs(vector<pll> v[],vector<ll> &dis, ll s, bool vis[])
{
	priority_queue<pll,vector<pll>, greater<pll>> pq;
	pq.push({0,s});
	while(!pq.empty())
	{
		pll op = pq.top();
		pq.pop();
		ll x = op.second;
		if(vis[x])
		continue;
		vis[x] = true;		
		FOR(i,v[x].size())
		{
			ll y = v[x][i].first;
			if(dis[x]+v[x][i].second < dis[y])
			{
				dis[y] = dis[x]+v[x][i].second;
				pq.push({dis[y],y});
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	// No. of nodes and edges resp.
	cin>>n>>m;
	vector<pll> v[n+1];
	vector<ll> dis(n+1, mx);
	cout<<"Enter edges and its weight"<<endl;
	while(m--)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	ll s;  // Source node to find distances
	cin>>s;
	dis[1] = 0;
	bool vis[n+1] = {false};
	dfs(v,dis,1,vis);
	for(int i = 2; i <= n; i++)
	cout<<i<<" "<<dis[i]<<"\n";
}
