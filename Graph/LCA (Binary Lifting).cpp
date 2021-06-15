//	Code to find lowest common ancestor (LCA) between two nodes in a rooted tree
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
#define nl cout<<"\n"
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
#define INF 1000000000000000000
const int mx = 1e5;
/*ll numinv[mx+1];
void InverseofNumber(ll p)
{
    numinv[0] = numinv[1] = 1;
    for (ll i = 2; i <= mx; i++)
        numinv[i] = numinv[mod % i] * (mod - mod / i) % mod;
}
ll fac[mx+1] = {0}, infac[mx+1] = {0};
ll comb(ll n, ll r)
{
	if(r > n)
	return 0;
	return (fac[n]%mod * infac[r]%mod * infac[n-r]%mod)%mod;
}*/
ll power(ll a,ll b)
{
    if(b == 0)
    return 1;
    if(b&1)
    return (a%mod * power((a%mod * a%mod)%mod, (b-1)/2)%mod)%mod;
    return power((a%mod * a%mod)%mod, b/2)%mod;
}
ll fact(ll a, ll b)
{
    if(a == b)
    return 1;
    return (a%mod * fact(a-1,b)%mod)%mod;
}
bool sortthis(pair<ll,ll> &a,pair<ll,ll> &b)
{
    return (a.first > b.first);
}
bool prime(ll n)
{
	if(n == 2)
	return true;
	if(n%2 == 0 || n == 1)
	return false;
	for(ll i = 3; (i*i) <= n; i += 2)
	{
		if(n%i == 0)
		return false;
	}
	return true;
}
const int m = log2(mx);
int par[mx+1][m]; 		// par[i][j] stores 2^jth parent of node i
vector<int> v[mx+1];
int dfs(int cn, int n, int lvl[], int p)	// O(nlog2(n))
{
	lvl[cn] = lvl[p]+1;
	par[cn][0] = p;	// 2^0 = 1st parent of current node = p;
	// We are dividing 2^i = 2^(i-1)(parent of current node) + 2^(i-1)(parent of 2^(i-1)th parent of current node)
	for(int i = 1; i < log2(n); i++)
	par[cn][i] = par[par[cn][i-1]][i-1];  	  
	for(int i = 0; i < v[cn].size(); i++)
	{
		int y = v[cn][i];
		if(y != p)
		dfs(y,n,lvl,cn);
	}
}
int find_lca(int x, int y, int n, int lvl[])	// O(log2(n))
{
	if(lvl[x] < lvl[y])
	swap(x,y);				// taking deeper level node as x
	int dif = lvl[x]-lvl[y];
	for(int i = 0; i <= log2(dif); i++)	// making x to same level as y via binary lifting
	{
		if((1<<i)&dif)
		x = par[x][i];
	}
	if(x == y)	// This is the case when nodes x and y have linear path and thus one of them is the LCA
	return x;
	/* 
		We start at i = log2(n)-1 because since x and y are at equal distance from root therefore in worst case their max
		distance from root can be n/2 and n/2 which is equal to 2^(log2(n)-1)
	*/
	for(int i = log2(n)-1; i >= 0; i--) 
	{
		/* 
		   If node at 2^ith distance is same for both x & y then lca could be that or at lower level so we don't count it.
		   If node at 2^ith distance is not same then lca is above 2^ith distance so we move our nodes x and y up at 2^ith 
		   parent respectively. Since we made levels of x and y same therefore it will always remain same in this loop.
		   We lift both levels up simultaneous at same level. In the last they both will reach nodes whose 1st parent is the
		   LCA.
		*/
		if(par[x][i] != par[y][i]) // max possible jump of x and y such that the nodes they jump to are not same
		{
			x = par[x][i]; 
			y = par[y][i];
		}
	}
	return par[x][0];
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t;
	t=1;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		FOR(i,n-1)
		{
			int a,b;
			cin>>a>>b;
			v[a].pb(b);
			v[b].pb(a);
		}
		cout<<"Enter root: ";
		cout.flush();
		int r;
		cin>>r;
		memset(par,0,sizeof(par));
		int lvl[n+1] = {0};
		lvl[0] = -1;
		dfs(r,n,lvl,0);
		while(q--)
		{
			cout<<"Enter two nodes for lca:\n";
			cout.flush();
			int x,y;
			cin>>x>>y;
			cout<<"LCA of "<<x<<" and "<<y<<" is: "<<find_lca(x,y,n,lvl)<<"\n";
		}
	}
}
