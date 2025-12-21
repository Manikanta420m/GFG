class Solution {
  public:
    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        vector<int>ans;
        unordered_map<int,pair<int,int>>mp;
        int prev=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=prev){
                mp[arr[i]].first=i;
                mp[arr[i]].second=i;
            }
            else mp[arr[i]].second=i;
            prev=arr[i];
        }
        for(auto q:queries){
            int l=q[0],r=q[1],x=q[2];
            if(mp.find(x)==mp.end())ans.push_back(0);
            else if(arr[l]<=x and arr[r]>=x){
                int l1=mp[x].first;
                int r1=mp[x].second;
                ans.push_back(abs(max(l,l1)-min(r,r1))+1);
            }
            else ans.push_back(0);
        }
        return ans;
    }
};