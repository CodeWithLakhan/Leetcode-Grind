class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> allSubVec;
        vector<int> ans;
        allsubsets(nums , allSubVec , ans , 0);

        return allSubVec;
        
    }

    void allsubsets(vector<int>& nums , vector<vector<int>>& allSubVec , vector<int>& ans , int i)
    {
        if(i==nums.size())
        {
            allSubVec.push_back(ans);
            return ;
        }

        ans.push_back(nums[i]);
        allsubsets(nums,allSubVec , ans , i+1);

        ans.pop_back();
        
        int idx = i+1;
        while(idx < nums.size() && nums[idx]==nums[idx-1])
        {
            idx++;
        }
        allsubsets(nums,allSubVec , ans , idx);
    }
};