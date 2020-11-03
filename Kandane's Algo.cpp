// Maximum Contiguous Sum of an array in O(N) using Kandane's Algo
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007
#define FOR(i,x) for(int i = 0; i < x; i++)
#define For(x,y) for(int i = x; i <= y; i++)
#define vint(x) vector<int>x
#define vl(x) vector<long>x
#define vll(x) vector<long long>x
#define pb push_back
#define oset tree <int, null_type , less , rb_tree_tag, tree_order_statistics_node_update>
const int mx = 1e6;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int arr[n];
	FOR(i,n)
	cin>>arr[i];
	int ans = 0, cs = 0;
	FOR(i,n)
	{
		cs = cs + arr[i];
		if(cs < arr[i])
		cs = arr[i];
		if(ans < cs)
		ans = cs;
	}
	cout<<ans;
}
