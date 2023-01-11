//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        unordered_map<long long,int>mp;  // creaate an map strong the count of the elements  
        long long ans=0; 
        for(int i=0;i<N;i++){
            mp[arr[i]]++;
            while(mp[arr[i]]>1){   // if count of elemnet is >1 inc the operation and add +1 to the current elemet 
                ans++;
                arr[i]+=1;
                mp[arr[i]]++;   // and push then in map again  
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends