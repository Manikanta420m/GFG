class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int x = q[2];
            auto &v = mp[x];
            int cnt =
                upper_bound(v.begin(), v.end(), r) -
                lower_bound(v.begin(), v.end(), l);

            ans.push_back(cnt);
        }

        return ans;
    }
};