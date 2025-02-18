class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double> ans;
        sort(nums.begin(),nums.end());
        double l=0,r=nums.size()-1;
        while(r>l)
        {
            ans.insert( (((float)nums[l]+(float)nums[r])/2) );
            l++;
            r--;
        }
        return ans.size();
    }
};