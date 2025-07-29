class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        vector<int>f(26,-1),l(26,-1),ans;
        for(int i=0;i<s.size();i++){
            int idx=s[i]-'a';
            if(f[idx]==-1)f[idx]=i;
            l[idx]=i;
        }
        for(int i=0;i<26;i++){
            if(f[i]!=-1 and l[i]!=-1 and f[i]<l[i]){
                int sm=0;
                for(int j=f[i]+1;j<l[i];j++){
                    sm+=s[j];
                }
                if(sm)ans.push_back(sm);
            }
        }
        return ans;
    }
};