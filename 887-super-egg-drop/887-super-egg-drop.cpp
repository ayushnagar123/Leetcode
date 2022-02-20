class Solution {
public:
    vector<vector<int>> ed_dp = vector<vector<int>>(101, vector<int>(10001, -1));
    int superEggDrop(int e, int f) {
        if(ed_dp[e][f]!=-1){return ed_dp[e][f];}
        if(e == 0 || f==0){return ed_dp[e][f] = 0;}
        if(f == 1){return ed_dp[e][f] = f;}
        if(e == 1){return ed_dp[e][f] = f;}
        int mn = INT_MAX;
        int l = 1, h = f;
        while(l<=h){
            int mid = l + (h - l)/2;
            int broke = superEggDrop(e-1, mid - 1);
            int not_broke = superEggDrop(e, f - mid);
            int temp = max(broke, not_broke);
            mn = min(mn, temp+1);
            if(broke> not_broke){
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ed_dp[e][f] = mn;
        return ed_dp[e][f];
    }
};