class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max1 = piles[0];
        for (int i=0;i<piles.size();i++)
        {
            max1 = max(max1,piles[i]);
        }
        int l = 1, h1 = max1;
        int ans = max1;
        while(l<=h1)
        {
            int mid = (l+h1)/2;
            long sum = 0;
            for(int i=0;i<piles.size();i++)
            {
                sum = sum + ceil( double(piles[i]) / mid );            
            }
            if(sum<=h)
            {
                ans=mid;
                h1 = mid-1;
            }
            else 
            {
                l = mid+1;
            }
        }
        return ans;
    }
};