class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bb = prices[0];
        int maxp = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(bb<prices[i])
            {
                maxp= max(maxp , prices[i]-bb);
            }
            bb = min(bb,prices[i]);
        }
        return maxp;
    }
};