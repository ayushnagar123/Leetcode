// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& arr, int people) 
    {
        // code here 
        stack<int> s;
        for(int i=0;i<people;i++){
            s.push(i);
        }
        while(s.size()>1){
            int p1 = s.top();
            s.pop();
            int p2 = s.top();
            s.pop();
            if(arr[p1][p2]==1 && arr[p2][p1]==0){
                s.push(p2);
            }
            else if(arr[p1][p2]==0 && arr[p2][p1]==1){
                s.push(p1);
            }
        }
        if(s.empty()){
            return -1;
        }
        int expected = s.top();
        for(int i=0;i<people;i++){
            if(i!=expected && (arr[expected][i]!=0 || arr[i][expected]!=1)){
                return -1;
            }
        }
        return expected;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends