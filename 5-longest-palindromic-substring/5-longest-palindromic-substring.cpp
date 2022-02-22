class Solution {
public:
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
    
    vector<vector<int>> dp;
    string ans="";
    void lcs(string x, string y){
        int max = 0;
        int n = x.size();
        for(int i=1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    if(ans.size() < dp[i][j] and isPalindrome(x.substr(i - dp[i][j], dp[i][j]))) {
                        ans = x.substr(i - dp[i][j], dp[i][j]);
                    }
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
    }
    
    string longestPalindrome(string s) {
       string y = s;
        reverse(y.begin(), y.end());
        vector<int> row(s.size()+1, 0);
        dp = vector<vector<int>> (s.size()+1, row);
        lcs(s, y);
        return ans;
    }
};