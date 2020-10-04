/* Code to check cycle in a directed graph */

#include<bits/stdc++.h>
using namespace std;
bool isCycle(vector<int>v[], bool vis[],int node)  // dfs search technique to check if a particular node comes again in a path forming a cycle
{
    if(vis[node] == false)
    {
        vis[node] = true;
        for(int i = 0; i < v[node].size(); i++)
        {
            int y = v[node][i];
            if( vis[y] == true)
            return true;
            else
            if(isCycle(v,vis,y))
            return true;
        }
    }
    vis[node] = false;
    return false;
}

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int>v[n+1];
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    bool vis[n+1] = {false};
    int flag = 0;
    for(int i = 1; i <= n ; i++)   // loop to check cycles in all the connected components of the graph
    {
        if(vis[i] == false)
        {
            if(isCycle(v,vis,i))
            flag = 1;
            if(flag == 1)
            break;
        }
    }
    if(flag)
    cout<< "Yes"<<endl;
    else
    cout<< "No" <<endl;
}
