class Solution {
public:
    string shortestCommonSupersequence(string x, string y) {
        int n = x.size();
        int m = y.size();
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
        string ans="";
        int i = n, j = m;
        while(i > 0 and j>0){
            if(x[i-1]==y[j-1]){
                ans = x[i-1] + ans;
                i--;
                j--;
            } else if(dp[i-1][j] > dp[i][j-1]){
                ans = x[i-1] + ans;
                i--;
            } else {
                ans = y[j-1] + ans;
                j--;
            }
        }
        while(i>0){
            ans = x[i-1] + ans;
             i--;
        }
        while(j>0) {
            ans = y[j-1] + ans;
            j--;
        }
        return ans;
    }
};