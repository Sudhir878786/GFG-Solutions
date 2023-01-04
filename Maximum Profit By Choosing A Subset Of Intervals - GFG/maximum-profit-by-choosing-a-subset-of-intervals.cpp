//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:

    int maximum_profit(int n, vector<vector<int>> &in) {
        // Write your code here.
       
        int m=in[0].size();
        int ans=0;
        sort(in.begin(),in.end());
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            dp[i]=in[i][2];   // storing cost in a vcector
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(in[j][1]<=in[i][0] and in[j][0]<in[i][0]){
                    dp[i]=max(dp[i],in[i][2]+dp[j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends