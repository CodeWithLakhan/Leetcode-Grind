class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int minn = INT_MAX , maxx = INT_MIN;
        int n=nums.size();
        for(int i=0 ; i<n ; i++)
        {
            minn = min(minn,nums[i]);
            maxx= max(maxx,nums[i]);
        }
        int l=1 , h=maxx;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(check(nums,mid,threshold)==true)
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
    bool check(vector<int>& nums, int no, int t)
    {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            double x = (double)nums[i]/no;
            sum = sum + ceil(x);
        }
        cout<<sum<<endl;
        if(sum<=t) return true;
        else return false;
    }
};