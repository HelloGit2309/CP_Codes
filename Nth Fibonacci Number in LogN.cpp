/* C++ Code to find Nth fibonacci number in O(log N) using Matrix Exponentiation Method */

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
vector<vector<long long>> mult(vector<vector<long long>> a, vector<vector<long long>> b)
{
    vector<vector<long long>> m(2,vector<long long> (2,0));
    for(int i = 0; i < 2; i ++)
    {
        for(int j = 0; j < 2; j++)
        {
            for(int k = 0; k < 2; k++)
            m[i][j] += (a[i][k]%mod * b[k][j]%mod)%mod;
        }
    }
    return m;
}
vector<vector<long long>> solve(vector<vector<long long>> a, long n)
{
    if(n == 0)
    {
        vector<vector<long long>> s = {{1,0},{0,1}};
        return s;
    }
    if(n%2 == 0)
    return solve(mult(a,a), n/2);
    else
    return mult(a,solve(mult(a,a),(n-1)/2));
}
int main()
{
	long n;
	cin>>n;
    vector<vector<long long>> x = {{1,1},{1,0}};
    vector<vector<long long>> ans = solve(x,n);
    cout<<ans[0][1]%mod;
}
