class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int mmax = INT_MIN;
        for(int i=0;i<candies.size();i++){
            mmax = max(mmax,candies[i]);
        }

        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies >= mmax) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};