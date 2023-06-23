//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int func(int n,int d,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(n==0){
            if(d==0 and arr[0]==0){
                return 2;
            }
            if(d==0 || arr[0]==d){
                return 1;
            }
            return 0;
        }
        if(dp[n][d]!=-1){
            return dp[n][d];
        }
        int nott=func(n-1,d,arr,dp);
        int take=0;
        if(arr[n]<=d){
            take=func(n-1,d-arr[n],arr,dp);
        }
        return dp[n][d]=(take+nott)%1000000007;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int tot=accumulate(arr.begin(),arr.end(),0);
        if(tot-d<0)return 0;
        if((tot-d)%2==1)return 0;
           int s1=(tot-d)/2;
        vector<vector<int>>dp(n+1,vector<int>(s1+1,-1));
     
        return func(n-1,s1,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends