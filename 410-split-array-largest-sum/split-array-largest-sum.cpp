class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxx = INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            maxx = max(maxx,nums[i]);
            sum=sum+nums[i];
        }
        int l=maxx , h=sum;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(check(nums,mid)>k)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return l;
    }
    int check(vector<int>& nums, int k)
    {
        int curr=1 ;;
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(sum + nums[i]<=k)
            {
                sum = sum + nums[i];
            }
            else
            {
                curr++;
                sum = nums[i];
            }
        }
        return curr;
    }
};