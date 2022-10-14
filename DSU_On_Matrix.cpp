// Problem Statement

/*

You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. 
Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. 
The array has k operator and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from
sea to island. Return how many island are there in the matrix after each operator.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.

Problem Link: https://practice.geeksforgeeks.org/problems/number-of-islands/1

*/



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(ll i = 0; i < x; i++)
#define For(i,x,y) for(ll i = x; i <= y; i++)
#define rep(i,x,y) for(ll i = x; i >= y; i--)
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<"\n";
#define errAA(A) for(auto i:A){errA(i)};
#define err1(a) cout<<#a<<" "<<a<<"\n"
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<"\n"
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<"\n"
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<"\n"
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
const ll mx = 1e6;

bool valid(int i, int j, int n, int m)
{
	if (i < 0 || j < 0 || i >= n || j >= m)
		return false;
	return true;
}
pair<int, int> root(pair<int, int> x, vector<vector<pair<int, int>>> &par)
{
	while (x != par[x.first][x.second])
	{
		// Path Compression
		par[x.first][x.second] = par[par[x.first][x.second].first][par[x.first][x.second].second];
		x = par[x.first][x.second];
	}
	return x;
}
void join(pair<int, int> a, pair<int, int> b, vector<vector<pair<int, int>>> &par, vector<vector<int>> &w)
{
	pair<int, int> p = root(a, par);
	pair<int, int> q = root(b, par);
	if (p == q)
		return;
	// Weight Balanced
	if (w[p.first][p.second] >= w[q.first][q.second])
	{
		par[q.first][q.second] = p;
		w[p.first][p.second] += w[q.first][q.second];
	}
	else
	{
		par[p.first][p.second] = q;
		w[q.first][q.second] += w[p.first][p.second];
	}
}
vector<int> numOfIslands(int n, int m, vector<vector<int>> &op) {
	// code here
	vector<int> ans;
	int c = 0;
	vector<vector<pair<int, int>>> par(n, vector<pair<int, int>> (m));
	vector<vector<int>> w(n, vector<int> (m)), val(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			par[i][j] = {i, j}, w[i][j] = 1;
	}
	for (int i = 0; i < op.size(); i++)
	{
		vector<int> x = {1, -1, 0, 0}, y = {0, 0, 1, -1};
		int f = 0;
		if (val[op[i][0]][op[i][1]])
		{
			ans.push_back(c);
			continue;
		}
		for (int j = 0; j < 4; j++)
		{
			int p = x[j] + op[i][0], q = y[j] + op[i][1];
			if (valid(p, q, n, m) && val[p][q])
			{
				if (root({p, q}, par) != root({op[i][0], op[i][1]}, par))
					++f;
				join({p, q}, {op[i][0], op[i][1]}, par, w);
			}
		}
		val[op[i][0]][op[i][1]] = 1;
		if (f == 0)
			++c;
		else
			c -= f - 1;
		ans.push_back(c);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	clock_t tStart = clock();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll T = 1;
	// cin >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		int k;
		cin >> k;
		vector<vector<int>> operators(k, vector<int>(2));
		FOR(i, k)
		cin >> operators[i][0] >> operators[i][1];
		vector<int> ans = numOfIslands(n, m, operators);
		FOR(i, k)
		cout << ans[i] << " ";
		cout << "\n";
	}
#ifndef ONLINE_JUDGE
	printf("\nRun Time -> %.10fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
#endif
}
