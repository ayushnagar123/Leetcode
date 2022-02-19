class Solution {
public:
    vector<vector<bool>> dp;
    
    string ans;
    
    bool isPalindrome(string s){
        int i=0, j = s.size() - 1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    int longestCommonSubstring(string x, string y, int n, int m){
        vector<int> row(y.size()+1, -1);
        vector<vector<int>> dp(x.size()+1,row);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        int max = 0;
        int end_index = 0;
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(x[i-1] == y[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(max < dp[i][j]){
                        max = dp[i][j];
                    }
                    if(ans.size() < dp[i][j] and isPalindrome(x.substr(i-dp[i][j], dp[i][j]))) {
                        ans = x.substr(i-dp[i][j], dp[i][j]);
                    }
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return max;
    }
    
    
    string longestPalindrome(string s) {
        string p = s;
        reverse(p.begin(), p.end());
        cout<<longestCommonSubstring(s, p ,s.size(), p.size());
        return ans;
    }
};