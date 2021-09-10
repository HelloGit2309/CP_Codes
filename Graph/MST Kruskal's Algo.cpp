/* Minimum Spanning Tree using Kruskal's Algorithm  */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(int i = x; i >= y; i--)
#define vint(x) vector<int>x
#define vl(x) vector<long>x
#define vll(x) vector<long long>x
#define um unordered_map
#define pb push_back
#define pll pair<ll,ll>
#define mone cout<<-1<<"\n"
#define yess cout<<"YES\n"
#define noo cout<<"NO\n"
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
#define INF 1000000000000000000
const ll mx = 1e5;
pair<ll,pll> edge[mx+1];
ll par[mx+1], size[mx+1], n,m;
vector<tuple<ll,ll,ll>>ans;
ll root(ll x)
{
    while(par[x] != x)
    {
    	par[x] = par[par[x]];  // making grandparent of x as parent .i.e., path compression
    	x = par[x];           // jumping to grandparent which is now parent
	}
    return x;
}
void union1(ll x, ll y)  // weighted union function
{
    ll p = root(x);
    ll q = root(y);
    if(size[p] < size[q])
    {
    	par[p] = par[q];
    	size[q] += size[p];
	}
	else
	{
		par[q] = par[p];
		size[p] += size[q];
	}
}
ll mst()
{
    ll x, y, cost, mc = 0;
    FOR(i,m)
    {
        x = edge[i].second.first;
        y = edge[i].second.second;
        cost = edge[i].first;
        if(root(x) != root(y))
        {
        	ans.pb(make_tuple(x,y,cost));
        	mc += cost;
            union1(x, y);
        }    
    }
    return mc;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	FOR(i,mx+1)
	{
		par[i] = i;
		size[i] = 1;
	}
	cin>>n>>m;
	FOR(i,m)
	{
		ll a,b,c;
		cin>>a>>b>>c;
		edge[i] = {c,{a,b}};
	}
	sort(edge,edge+m);
	ll mincost = mst();
	cout<<"Minimum Cost = "<<mincost<<"\n";
	cout<<"New Graph:\n";
	cout<<n<<" "<<ans.size()<<"\n";
	FOR(i,ans.size())
	{
		ll a,b,c;
		tie(a,b,c) = ans[i];
		cout<<a<<" "<<b<<" "<<c<<"\n";
	}
}
