class Solution {
  public:
    bool kSubstr(string &s, int k) {
       int n=s.size();
       string s1="";
       if(n%k!=0)return false;
       unordered_map<string,int>mp;
       for(auto i:s){
           s1.push_back(i);
           if(s1.size()==k){
               mp[s1]++;
               s1="";
           }
       }
       if(mp.size()>2)return false;
       for(auto i:mp){
           if(i.second==1)return true;
       }return mp.size()==1;
    }
};