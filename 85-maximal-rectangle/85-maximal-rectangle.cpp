class Solution {
public:
    int maxAreaHistogram(vector<int>& arr) {
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

        while(!s.empty()){
            s.pop();
        }

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
    
    int maximalRectangle(vector<vector<char>>& arr) {
        int row = arr.size();
        int col = arr[0].size();
        vector<vector<int>> mat;
        int max = 0;

        for(int i = 0;i<row;i++){
            vector<int> row(col, 0);
            mat.push_back(row);
        }
        for(int i = 0; i <row;i++){
            for(int j = 0;j<col;j++){
                if(arr[i][j] != '0' && i>0){
                    mat[i][j] = 1+mat[i-1][j];
                }
                else{
                    mat[i][j] = arr[i][j] - '0';
                }
            }
            int area = maxAreaHistogram(mat[i]);
            if(area > max){
                max = area;
            }
        }
        return max;
    }
};