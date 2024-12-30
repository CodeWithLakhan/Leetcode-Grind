class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mind = INT_MAX , maxd = INT_MIN;
        int n=bloomDay.size();
        if(n<(long long)m*k) return -1;
        for(int i=0 ; i<n ; i++)
        {
            mind = min(mind,bloomDay[i]);
            maxd= max(maxd,bloomDay[i]);
        }
        int l=mind , h=maxd;
        int ans;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(possible(bloomDay,mid,m,k)==true)
            {
                ans=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }


    bool possible(vector<int>&  arr , int day , int m , int k)
    {
        int cnt=0;
        int nb=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<=day)
            {
                cnt++;
            }
            else
            {
                nb = nb + (cnt/k);
                cnt=0;
            }
        }
        nb = nb + (cnt/k);
        if(nb>=m) return true;
        else return false;
    }
};