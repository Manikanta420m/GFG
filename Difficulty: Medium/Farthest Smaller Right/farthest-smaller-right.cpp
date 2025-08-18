class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n=arr.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
        vector<int>ans(n,-1);
        int maxi=v[0].second;
        for(int i=1;i<n;i++){
            if(maxi>v[i].second){
                ans[v[i].second]=maxi;
            }
            maxi=max(maxi,v[i].second);
        }
        return ans;
    }
};