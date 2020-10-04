/*   Code to check cycle in a undirected graph 

Unlike directed graph in an undirected graph if a node is marked visited then we need not unmark it as unvisited.
If a node occurs in our dfs traversal such that it is already marked as visited AND also it is NOT a parent of its the current node then
we say that the graph has a cycle.

                   1
                  / \
                 2   3
                    / \
                   4--5
*/

#include<bits/stdc++.h>
using namespace std;
bool isCycle(vector<int>v[], bool vis[],int node, int par)
{
    if(vis[node] == false)
    {
        vis[node] = true;
        for(int i = 0; i < v[node].size(); i++)
        {
            int y = v[node][i];
            if( vis[y] == true && y != par) // if node y is already visited and y is not a parent of current node
            return true;
            else
            if(isCycle(v,vis,y,node)) // else dfs traversal in node y
            return true;
        }
    }
    return false;  // after complete dfs traversal of node if there is no cycle then it returns false
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
        v[b].push_back(a);
    }
    bool vis[n+1] = {false};
    int flag = 0;
    for(int i = 1; i <= n ; i++)   // loop to check cycles in all the connected components of the graph
    {
        if(vis[i] == false)
        {
            if(isCycle(v,vis,i,0))
            flag = 1;
            if(flag == 1)
            break;
        }
    }
    if(flag)
    cout<< "Yes"<<endl;  // YES if there is a cycle
    else
    cout<< "No" <<endl; // NO if there is no cycle
}
