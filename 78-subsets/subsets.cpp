class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubVec;
        vector<int> ans;
        allsubsets(nums,ans,0,allSubVec);
        return allSubVec;
    }
    
    void allsubsets(vector<int>& nums, vector<int>& ans, int i,vector<vector<int>>& allSubVec){
        if(i==nums.size()) {
            allSubVec.push_back(ans);
            return;
        }
        //include
        ans.push_back(nums[i]);
        allsubsets(nums,ans,i+1,allSubVec);

        //exclude
        ans.pop_back();
        allsubsets(nums,ans,i+1,allSubVec);
    }
};