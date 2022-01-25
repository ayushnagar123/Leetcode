class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<pair<int, int>> s;
        for(int i = 0;i<n;i++){
            while(!s.empty()){
                if(s.top().first < arr[i]){
                    left[i] = s.top().second;
                    break;
                }
                else {
                    s.pop();
                }
            }
            s.push(make_pair(arr[i], i));
        }

        s = stack<pair<int, int>>();
        for(int i = n-1;i>=0;i--){
            while(!s.empty()){
                if(s.top().first < arr[i]){
                    right[i] = s.top().second;
                    break;
                }
                else {
                    s.pop();
                }
            }
            s.push(make_pair(arr[i], i));
        }
        vector<int> area(arr.size(), -1);
        int ans = INT_MIN;
        for(int i = 0;i<arr.size();i++){
            area[i] = max(arr[i], (right[i] - left[i] -1)*arr[i]);
            if(area[i] > ans){
                ans = area[i];
            }
        }
        return ans;
    }
};