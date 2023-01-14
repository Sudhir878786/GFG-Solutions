//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int>mp;
    int ans=-1;
    int i=0;
    int j=0;
    int n=s.size();
    while(i<n and j<n){
        mp[s[j]]++;
        if(mp.size()>k){
            while(mp.size()>k and !mp.empty()){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
        }
        if(mp.size()==k){
            ans=max(ans,j-i+1);
        }
        j++;
    }
    if(ans==-1){
        return -1;
    }
    return ans;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends