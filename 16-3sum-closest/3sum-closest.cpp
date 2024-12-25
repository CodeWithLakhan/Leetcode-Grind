class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int mindif = INT_MAX;
        int resultsum = nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];
                if (x < target) {
                    j++;
                } else if (x > target) {
                    k--;
                } else {
                    return target;
                }
                int diff = abs(target-x);
                if(diff<mindif)
                {
                    resultsum=x;
                    mindif = diff;
                }
            }
        }
        return resultsum;
    }
};