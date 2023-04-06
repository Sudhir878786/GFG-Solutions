//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    int addMinChar(string str){    
        //code here
         string rev_str = str;
    reverse(rev_str.begin(), rev_str.end()); // reverse the string
    
    string temp_str = str + "#" + rev_str; // concatenate the two strings with a separator
    
    int n = temp_str.length();
    int lps[n];
    lps[0] = 0;
    int len = 0, i = 1;
    
    // build the LPS array
    while (i < n) {
        if (temp_str[i] == temp_str[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0)
                len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    int min_chars = str.length() - lps[n-1]; 
    return min_chars;
        
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends