class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int temp = nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            {
                temp = temp + nums[i];
                ans = max(ans , temp);
            }
            else temp = nums[i];
        }
        return ans;
    }
};