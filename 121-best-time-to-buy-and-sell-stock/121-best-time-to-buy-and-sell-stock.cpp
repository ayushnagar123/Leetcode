class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int ans = 0;
        int profit = 0;
        while(r < prices.size()) {
            if(prices[l] > prices[r]){
                l++;
                r = l+1;
            }
            else {
                profit = prices[r] - prices[l];
                if(profit > ans){
                    ans = profit;
                }
                r++;
            }
        }
        return ans;
    }
};