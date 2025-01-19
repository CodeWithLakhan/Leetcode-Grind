class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        find(candidates , ans , ds , target ,0);
        return ans;
    }

    void find(vector<int>& nums , vector<vector<int>>& ans , vector<int>& ds, int target , int i)
    {
        if(i==nums.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }

        if(nums[i]<=target)
        {
            ds.push_back(nums[i]);
            find(nums,ans,ds,target-nums[i],i);
            ds.pop_back();
        }
        find(nums,ans,ds,target,i+1);
    }
};