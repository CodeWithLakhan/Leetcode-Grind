class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag = false;
        int n = nums.size();
        if(n<=1) return true;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<=nums[i+1]) flag = true;
            else
            {
                flag = false;
                break;
            }
        }
        if(flag) return flag;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>=nums[i+1]) flag = true;
            else
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
};