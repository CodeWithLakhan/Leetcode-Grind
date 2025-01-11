class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int r = 0, l=0;
        int j=0;
        while(r<n-1){
            int far = 0;
            for(int i=l;i<=r;i++)
            {
                far = max(far , i+nums[i]);
            }
            l=r+1;
            r=far;
            j++;
        }
        return j;
    }
};