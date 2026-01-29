class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        int n=s.size();
        queue<char>q;
        unordered_map<char,int>mp;
        string ans;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if(mp[s[i]]==1){
                q.push(s[i]);
            }
            while(!q.empty() && mp[q.front()] > 1) {
                q.pop();
            }
            if(q.empty())ans.push_back('#');
            else ans.push_back(q.front());
        }
        return ans;
    }
};