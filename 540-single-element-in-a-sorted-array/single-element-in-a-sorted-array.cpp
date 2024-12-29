class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0, h=n-1;
        if(n==1) return nums[0];
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(mid>0 && nums[mid]==nums[mid-1]  )
            {
                if(mid%2==0)
                {
                    h=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else if(nums[mid]==nums[mid+1])
            {
                if(mid%2==0)
                {
                    l=mid+1;
                }
                else
                {
                    h=mid-1;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return 0;
    }
};