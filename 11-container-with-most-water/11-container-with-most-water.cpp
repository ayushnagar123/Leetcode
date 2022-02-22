class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max = 0;
        while(i<j){
            int currArea = min(height[j], height[i]) * (j-i);
            if(max < currArea){
                max = currArea;
            }
            if(height[i] < height[j]){
                i++;
            }
            else {
                j--;
            }
        }
        return max;
    }
};