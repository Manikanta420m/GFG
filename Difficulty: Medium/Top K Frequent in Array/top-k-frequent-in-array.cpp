class Solution {
  private:
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.second==b.second){
            return a.first>=b.first;
        }
        return a.second>b.second;
    }
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map<int,int>mp;
        for(auto i:arr)mp[i]++;
        vector<pair<int,int>>pr;
        for(auto i:mp){
            pr.push_back({i.first,i.second});
        }
        sort(pr.begin(),pr.end(),comp);
        vector<int>ans;
        for(int i=0;i<k;i++)ans.push_back(pr[i].first);
        return ans;
    }
};
