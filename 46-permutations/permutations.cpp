class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> fans;
        vector<int> ans;
        int n = nums.size();
        int freq[n];
        for(int i=0 ; i<n ; i++) freq[i]=0;
        permute(nums , ans , fans , freq);
        return fans;
    }
    void permute(vector<int>& nums , vector<int>& ans , vector<vector<int>>& fans, int freq[])
    {
        if(ans.size() == nums.size())
        {
            fans.push_back(ans);
            return;
        }
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(!freq[i])
            {
                ans.push_back(nums[i]);
                freq[i]=1;
                permute(nums , ans , fans , freq);
                ans.pop_back();
                freq[i] = 0;
            }
        }
    }
};