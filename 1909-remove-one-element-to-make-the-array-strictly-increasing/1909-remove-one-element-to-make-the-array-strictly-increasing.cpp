class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count = 0;
        if(nums.size() == 1)
        {
            return true;
        }
        int i = 1;
        while (i < nums.size())
        {
            if(nums[i] <= nums[i - 1])
            {
                count++;
                if(i > 1)
                {
                    if(nums[i] <= nums[i - 2])
                    {
                        nums[i] = nums[i - 1];
                    }
                    else
                    {
                        nums[i - 1] = nums[i - 2];
                        i--;
                    }
                }
                if(count == 2)
                {
                    return false;
                }      
            }
            i++;
        }
        return true;
    }
};