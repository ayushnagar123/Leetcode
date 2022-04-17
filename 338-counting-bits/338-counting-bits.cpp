class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while(n > 0){
            n &= n-1;
            count++;
        }
        return count;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        
        for(int i=1;i<=n;i++){
            ans[i] = countSetBits(i);
        }
        return ans;
    }
};