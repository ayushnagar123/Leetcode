class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ans;
        int i = 0, j = 0;
        int n = arr.size();
        deque<int> q;
        ans.push_back(-9999);

        while(j < n) {
            while(!q.empty() && q.back() < arr[j]) {
                q.pop_back();
            }
            q.push_back(arr[j]);
            if(j < k) {
                ans[0] = q.front();
            }
            else {
                if(q.front() == arr[i]) {
                    q.pop_front();
                }
                ans.push_back(q.front());
                i++;
            }
            j++;
        }
        return ans;
    }
};