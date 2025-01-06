class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        int sum = 0;
        int ro=0;
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='1')
            {
                sum = sum + i;
                ro++;
            }
        }
        int prefixSum = 0;
        int lo = 0;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int moves = sum+prefixSum;
            ans[i]=moves;
            if(boxes[i]=='1')
            {
                lo++;
                ro--;
            }
            prefixSum = prefixSum + lo;
            sum = sum - ro;
        }
        return ans;
    }
};