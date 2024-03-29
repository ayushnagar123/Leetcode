// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long ropes[], long long n) {
        long long i = 0;
        long long cost = 0;
        priority_queue<long long, vector<long long>, greater<long long> > q;
        for(long long i=0;i<n;i++){
            q.push(ropes[i]);
        }
        while(q.size() >= 2){
            long long rope1 = q.top();
            q.pop();
            long long rope2 = q.top();
            q.pop();
            cost += rope1 + rope2;
            q.push(rope1+rope2);
            i++;
        }
        return cost;
        // Your code here
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends