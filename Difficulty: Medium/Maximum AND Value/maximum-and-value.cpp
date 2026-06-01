class Solution {
  public:
    int maxAND(vector<int>& arr) {
        int N=arr.size();
        int ans=0;
        vector<int> v;
        for(int i=0;i<N;i++)
        {
            v.push_back(arr[i]);
        }
        int cnt = 0;
        for(int i=31;i>=0;i--)
        {
            vector<int> set_bit;
            for(auto &j:v)
            {
                if(j&(1<<i))
                {
                    set_bit.push_back(j);
                }
            }
            if(set_bit.size()>=2)
            {
                ans+=(1<<i);
                v = set_bit;
            }
        }
        return ans;
    }
};