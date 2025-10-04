class Solution {
  private:
    void solve(int idx,string &s,int target,string curr,vector<string>&ans,long prev,long res){
        if(idx==s.size()){
            if(res==target){
                ans.push_back(curr);
            }
            return;
        }
        string st="";
        long curRes=0;
        for(int i=idx;i<s.size();i++){
            if(i>idx && s[idx]=='0')break;
            st+=s[i];
            curRes=curRes*10+(s[i]-'0');
            if(idx==0)solve(i+1,s,target,st,ans,curRes,curRes);
            else{
                solve(i+1,s,target,curr+"+"+st,ans,curRes,res+curRes);
                solve(i+1,s,target,curr+"-"+st,ans,-curRes,res-curRes);
                solve(i+1,s,target,curr+"*"+st,ans,prev*curRes,res-prev+(prev*curRes));
            }
        }
    }
  public:
    vector<string> findExpr(string &s, int target) {
        // code here
        vector<string>ans;
        solve(0,s,target,"",ans,0,0);
        return ans;
    }
};