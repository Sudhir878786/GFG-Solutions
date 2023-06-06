//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        set<pair<int,pair<int,int>>>st;
        st.insert({grid[0][0],{0,0}});
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX)),vis(n,vector<int>(m,0));
        while(!st.empty()){
            auto p = *st.begin();
            st.erase(st.begin());
            int weight=p.first;
            int  i=p.second.first;
            int j=p.second.second;
            vis[i][j]=1;
            if(j-1>=0 and vis[i][j-1]==0){
                if(dp[i][j-1]>weight+grid[i][j-1]){
                    dp[i][j-1]=weight+grid[i][j-1];
                    st.insert({dp[i][j-1],{i,j-1}});
                    vis[i][j-1]=true;
                }
            }
            if(j+1<m and vis[i][j+1]==0){
                if(dp[i][j+1]>weight+grid[i][j+1]){
                    dp[i][j+1]=weight+grid[i][j+1];
                    st.insert({dp[i][j+1],{i,j+1}});
                    vis[i][j+1]=true;
                }
            }
            if(i-1>=0 and vis[i-1][j]==0){
                if(dp[i-1][j]>weight+grid[i-1][j]){
                    dp[i-1][j]=weight+grid[i-1][j];
                    st.insert({dp[i-1][j],{i-1,j}});
                    vis[i-1][j]=true;
                }
            }
            if(i+1<n and vis[i+1][j]==0){
                if(dp[i+1][j]>weight+grid[i+1][j]){
                    dp[i+1][j]=weight+grid[i+1][j];
                    st.insert({dp[i+1][j],{i+1,j}});
                    vis[i+1][j]=true;
                }
            }
            
        
        }
        return dp[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends