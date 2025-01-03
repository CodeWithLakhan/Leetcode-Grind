class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MIN;
        int l=0,r=0;
        int zc=0;
        int len;
        while(r<n)
        {
            if(nums[r]==0) zc++;
            if(zc>k)
            {
                if(nums[l]==0) zc--;
                l++;
            }
            if(zc<=k)
            {
                len=r-l+1;
                ans = max(ans,len);
            }
            r++;
            
        }
        return ans;
    }
};