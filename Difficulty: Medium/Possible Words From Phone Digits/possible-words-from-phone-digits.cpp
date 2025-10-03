class Solution {
  private:
    void solve(int idx,string &cur,vector<string>&mp,vector<string>&ans,vector<int> &arr){
        if(idx==arr.size()){
            ans.push_back(cur);
            return;
        }
        if(arr[idx]==1 or arr[idx]==0){
            solve(idx+1,cur,mp,ans,arr);
            return;
        }
        for(auto j:mp[arr[idx]]){
            cur.push_back(j);
             solve(idx+1,cur,mp,ans,arr);
            cur.pop_back();
        }
    }
  public:
    vector<string> possibleWords(vector<int> &arr) {
        vector<string>mp{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if (arr.empty()) return ans;
        string cur="";
        solve(0,cur,mp,ans,arr);
        sort(ans.begin(), ans.end()); 
        return ans;
    }
};