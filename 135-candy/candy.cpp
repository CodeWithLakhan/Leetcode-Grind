class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        int l2r[n];
        l2r[0]=1;
        for(int i=1;i<n;i++)
        {
            if (r[i] > r[i - 1]) {
                l2r[i] = l2r[i - 1] + 1;
            }

            else
            {
                l2r[i]=1;
            }
        }
        int sum = l2r[n - 1];
        int right = 1;
        for(int i=n-2;i>=0;i--)
        {
            if(r[i]>r[i+1])
            {
                right++;
            }
            else
            {
                right =1;
            }
            sum += max(l2r[i], right);
        }
        return sum;
    }
};