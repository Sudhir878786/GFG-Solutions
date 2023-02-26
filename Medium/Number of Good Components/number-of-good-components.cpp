//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int ver=0;
  int edges=0;
  int ans=0;
  void dfs(int cur,vector<bool>&vis,vector<vector<int>>&adj)
  {
      vis[cur]=true;
      edges+=adj[cur].size();
      for(auto it:adj[cur]){
          if(!vis[it]){
              ver++;
              dfs(it,vis,adj);
              
          }
      }
  }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<bool>vis(V+1,false);
        for(int i=1;i<=V;i++){
            if(!vis[i]){
                edges=0;
                ver=1;
                dfs(i,vis,adj);
                if(ver*((ver-1))/2==edges/2){
                    ans++;
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends