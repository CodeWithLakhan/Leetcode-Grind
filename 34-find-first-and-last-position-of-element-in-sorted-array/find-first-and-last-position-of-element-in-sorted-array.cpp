class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1,mid=(l+h)/2;
        while(l<=h)
        {
            mid=(l+h)/2;
            if(nums[mid]==target) break;
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        if (l > h) return {-1, -1};
        int a1=mid,a2=mid;
        while (a1 > 0 && nums[a1] == nums[a1 - 1]) {
            a1--;
        }
        while (a2 < n - 1 && nums[a2] == nums[a2 + 1]) {
            a2++;
        }
        vector<int> ans = {a1,a2};
        return ans;

    }
};