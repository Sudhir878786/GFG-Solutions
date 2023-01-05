//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    static bool cmp(string a,string b)
    {
        if(a.length()!=b.length()){
            return b.length()>a.length();
        }
        return a>b;
    }
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int>mp;
        string ans="";
        for(auto it:words){
            mp[it]++;
        }
        // for(auto it=mp.begin();it!=mp.end();it++){
        //     cout<<it->first<<"->"<<it->second<<endl;
        // }
        
        for(int i=words.size()-1;i>=0;i--){
            int s=words[i].size();
            string temp="";
            bool f=1;
            for(int j=0;j<s;j++){
                temp+=words[i][j];
                if(mp[temp]==0){
                    f=0;
                    break;
                }
                
            }if(f){
                return words[i];
            }
            
        }
        return  ans;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends