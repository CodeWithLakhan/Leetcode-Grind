class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int cnt = 1 ;
        int ans = 1;
        int n= nums.size();
        if(n==0) return 0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]>nums[i])
            {
                cnt++;
                ans = max(ans,cnt);
            }
            else
            {
                cnt=1;
            }
        }
        cnt = 1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                cnt++;
                ans = max(ans,cnt);
            }
            else
            {
                cnt=1;
            }
        }
        return ans;
    }
};