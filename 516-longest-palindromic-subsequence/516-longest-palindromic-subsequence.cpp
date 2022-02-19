class Solution {
public:
    int LCSTopDown(string x, string y, int n, int m){
        vector<int> row(y.size()+1, -1);
        vector<vector<int>> dp(x.size()+1,row);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(x[i-1] == y[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }

    
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string y = s;
        reverse(y.begin(), y.end());
        return LCSTopDown(s, y, n, n);
    }
};