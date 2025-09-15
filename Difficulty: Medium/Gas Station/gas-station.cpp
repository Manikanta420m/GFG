class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) 
    {
        int n = gas.size();
        int ans = -1;
        int total_gas = accumulate(gas.begin(), gas.end(), 0);
        int total_cost = accumulate(cost.begin(), cost.end(), 0);
        if(total_gas < total_cost)
            return ans;
        int gas_avail = 0;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            gas_avail += gas[i] - cost[i];
            if(gas_avail < 0)
            {
                start = i+1;
                gas_avail = 0;
            }
            
        }
        return start;
        
        
    }
};