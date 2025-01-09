class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5){
                mpp[bills[i]]++;
            }
            else if(bills[i]==10)
            {
                if(mpp[5]==0) return false;
                else{
                    mpp[5]--;
                }
                mpp[10]++;
            }
            else if(bills[i]==20)
            {
                if(mpp[5]>=1 && mpp[10]>=1){
                    mpp[5]--;
                    mpp[10]--;
                }
                else if(mpp[5]>=3){
                    mpp[5] = mpp[5] - 3;
                }
                else{
                    return false;
                }
            }

        }
        return true;
    }
};