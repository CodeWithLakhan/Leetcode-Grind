class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subpro(nums, k) - subpro( nums,  k-1) ;

    }
    int subpro(vector<int>& nums, int k)
    {
        int n = nums.size();
        int l=0,r=0;
        int cnt=0;
        unordered_map<int,int> mpp;
        while(r<n)
        {
            mpp[nums[r]]++;
            
                while(mpp.size()>k)
                {
                    mpp[nums[l]]--;
                    if(mpp[nums[l]]==0)
                    {
                        mpp.erase(nums[l]);
                    }
                    l=l+1;
                }
            
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
};