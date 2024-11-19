class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxx=0;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                c++;
                maxx = max(maxx,c);
            }
            else
            {
                c=0;
            }
        }
        return maxx;
    }
};