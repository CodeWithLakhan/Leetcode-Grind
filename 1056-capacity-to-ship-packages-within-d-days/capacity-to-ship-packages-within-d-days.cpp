class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int  maxd = INT_MIN;
        int n=weights.size();
        for(int i=0 ; i<n ; i++)
        {
            maxd= max(maxd,weights[i]);
        }
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum = sum+weights[i];
        }
        int l=maxd, h=sum;
        while(l<=h)
        {
            int mid = (l+h)/2;
            int x = check(weights,mid);
            if(x<=days)
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
    int check(vector<int>& weights, int cap)
    {
        int load=0,days=1;
        for(int i=0 ; i<weights.size(); i++)
        {
            if(weights[i]+load>cap)
            {
                days=days+1;
                load=weights[i];
            }
            else
            {
                load=load+weights[i];
            }
        }
        return days;
    }
};