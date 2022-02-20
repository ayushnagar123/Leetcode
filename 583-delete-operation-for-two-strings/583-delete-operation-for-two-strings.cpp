class Solution {
public:
    int LCSTopDown(string x, string y, int n, int m){
        vector<int> row(y.size()+1, 0);
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
    
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int lcs = LCSTopDown(word1, word2, n, m);
        int deletion = n - lcs;
        int insertion = m - lcs;
        return insertion + deletion;
    }
};