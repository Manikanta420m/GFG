class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int>ans,s_arr=arr;
        sort(s_arr.begin(),s_arr.end());
        for(auto i:queries){
            int l=lower_bound(s_arr.begin(),s_arr.end(),i[0])-s_arr.begin();
            int r=upper_bound(s_arr.begin(),s_arr.end(),i[1])-s_arr.begin();
            r--;
            ans.push_back(r-l+1);
        }
        return ans;
    }
};