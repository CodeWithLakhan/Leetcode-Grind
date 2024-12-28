class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long pre = 1;
        long suf = 1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(pre==0) pre=1;
            if(suf==0) suf=1;
            pre = pre * nums[i];
            suf = suf * nums[n-1-i];
            ans = max(ans,(int)max(pre,suf));
        }
        return ans;
    }
};