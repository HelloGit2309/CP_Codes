/* Given an array of N numbers. This code prints length of the longest increasing subsequence of the array. */
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
	long long dp[n] = {0};
	for(int i = 0; i < n; i++)
	dp[i] = 1;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[j] < arr[i])
			dp[i] = max(dp[i], 1+dp[j]);
		}
	}
	cout<<*max_element(dp,dp+n);
}
