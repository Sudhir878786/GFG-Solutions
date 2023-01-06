//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
  bool isprime(int num) {
  if (num < 1000 || num > 9999) return false;  // check for four digits
  if (num % 10 == 0) return false;  // check for leading zeros
  for (int i = 2; i <= sqrt(num); i++) {  // check for primality
    if (num % i == 0) return false;
  }
  return true;
}
    int shortestPath(int Num1,int Num2)
    {   
        // Complete this function using prime vector
        int ans=0;
       bool vis[10000];
       int dis[10000];
        memset(dis,-1,sizeof(dis));
        memset(vis,false,sizeof(vis));
        queue<int>q;
        q.push(Num1);
        vis[Num1]=true;
        dis[Num1]=0;
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            if(temp==Num2){
                return dis[temp];
            }
            for(int i=0;i<4;i++){
                for(int j=0;j<=9;j++){
                    int next=temp;
                    next-=(next/(int)pow(10,i))%10*(int)pow(10,i);
                    next+=j*(int)pow(10,i);
                    if(!vis[next] and isprime(next)){
                        q.push(next);
                        vis[next]=true;
                        dis[next]=dis[temp]+1;
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    Solution obj;
    while(t--)
    {
        int Num1,Num2;
        cin>>Num1>>Num2;
        int answer=obj.shortestPath(Num1,Num2);
        cout<<answer<<endl;
    }
}
// } Driver Code Ends