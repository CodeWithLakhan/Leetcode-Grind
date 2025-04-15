class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end());
        int sum = 0;
        for(int i=0;i<amount.size();i++) sum = sum + amount[i];
        return max(((sum/2)+(sum%2)),amount[amount.size()-1]);

    }
};