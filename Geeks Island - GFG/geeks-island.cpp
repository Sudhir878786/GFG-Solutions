//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    void dfs(vector<vector<int>> &mat,vector<vector<bool>>&vis,int n,int m, int i, int j)
    {
        vis[i][j]=true;
        if(i-1>=0 and vis[i-1][j]!=true and mat[i-1][j]>=mat[i][j]){
            dfs(mat,vis,n,m,i-1,j);
        }
        if(i+1<n and vis[i+1][j]!=true and mat[i+1][j]>=mat[i][j]){
            dfs(mat,vis,n,m,i+1,j);
        }
        if(j-1>=0 and vis[i][j-1]!=true and mat[i][j-1]>=mat[i][j]){
            dfs(mat,vis,n,m,i,j-1);
        }
        if(j+1<m and vis[i][j+1]!=true and mat[i][j+1]>=mat[i][j]){
            dfs(mat,vis,n,m,i,j+1);
        }
        
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
    // hame 2 bar dfs lagana h 2 ocean k liye 
    int n=mat.size();
    int m=mat[0].size();
    vector<vector<bool>>pac(n+1,vector<bool>(m+1,false));
    vector<vector<bool>>atl(n+1,vector<bool>(m+1,false));
    vector<vector<int>>ans;
    for(int i=0;i<n;i++){
        dfs(mat,pac,n,m,i,0);
        dfs(mat,atl,n,m,i,m-1);
    }
    for(int j=0;j<m;j++){
        dfs(mat,pac,n,m,0,j);
        dfs(mat,atl,n,m,n-1,j);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pac[i][j] and atl[i][j]){
                ans.push_back({i,j});
            }
        }
    }
    return ans.size();
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends