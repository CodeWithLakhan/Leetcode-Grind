class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas=0, tcost=0;
        for(int i=0;i<gas.size();i++)
        {
            tgas+=gas[i];
        }
        for(int i=0;i<cost.size();i++)
        {
            tcost+=cost[i];
        }
        if(tgas<tcost) return -1;
        
        int sidx = 0 , currcost=0;
        for(int i=0;i<gas.size();i++)
        {
            currcost = currcost + gas[i] - cost[i];
            if(currcost < 0 )
            {
                currcost = 0;
                sidx = i+1;
            }
        }
        return sidx;
    }
};