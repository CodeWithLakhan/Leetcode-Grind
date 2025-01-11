class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        for(int i=0;i<n;i++)
        {
            if(index>=n) return true;
            else if(index<i) return false;
            index = max(index,i+nums[i]);
            
        }
        return true;
    }
};