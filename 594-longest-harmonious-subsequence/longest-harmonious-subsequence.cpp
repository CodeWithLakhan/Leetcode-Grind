class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int r=1,l=0;
        int ans=0,maxans=0;
        int n=nums.size();
        // while(r<n)
        // {
        //     if(nums[r]-nums[l]==1)
        //     {
        //         ans = max(ans,r-l+1);
        //     }
        //     else if(nums[r]-nums[l]>1)
        //     {
        //         l++;
        //     }
        //     r++;
        // }

        while (r < n) {
            if (nums[r] - nums[l] <= 1) {
                if (nums[r] - nums[l] == 1) {
                    ans = max(ans, r - l + 1);
                }
                r++; 
            } else {
                l++; 
            }
        }
        return ans;
    }
};