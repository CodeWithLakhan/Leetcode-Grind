class Solution {
public:
    bool check(vector<int>& nums) {
        int c = 0;
        for(int i = 1;i < nums.size(); i++)
        {
            if(nums[i - 1] > nums[i])
            {
                c += 1;
            }
        }
        if(nums[nums.size() - 1] > nums[0]) c+= 1;
        if(c == 1 || c == 0) return true;
        else return false;
    }
};