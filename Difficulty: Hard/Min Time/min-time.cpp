class Solution {
  public:
    unordered_map<int,int>mini,maxi;
    
    long long solve(int pos,int idx,vector<int>&temp,vector<vector<long long>>&dp,int flag){
        if(idx==temp.size())return 0;
        if(dp[idx][flag]!=-1)return dp[idx][flag];
        long long a=0,b=0;
        int left=mini[temp[idx]];
        int right=maxi[temp[idx]];
        
        a=abs(pos-left)+abs(left-right)+solve(right,idx+1,temp,dp,1);
        if(idx==temp.size()-1)a+=abs(right-0);
        
        b=abs(pos-right)+abs(right-left)+solve(left,idx+1,temp,dp,0);
        if(idx==temp.size()-1)b+=abs(left-0);
        
        return dp[idx][flag]=min(a,b);
    }
    
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        mini.clear(),maxi.clear();
        int mx=*max_element(types.begin(),types.end());
        vector<int>ele(mx+1,0);
        int j=0;
        for(auto i:types){
            ele[i]=1;
            if(mini.find(i)==mini.end()){
                mini[i]=locations[j];
                maxi[i]=locations[j];
            }
            else{
                mini[i]=min(mini[i],locations[j]);
                maxi[i]=max(maxi[i],locations[j]);
            }
            j++;
        }
        vector<int>temp;
        for(int i=0;i<=mx;i++){
            if(ele[i]==1)temp.push_back(i);
        }
        vector<vector<long long>>dp(temp.size(),vector<long long>(2,-1));
        return solve(0,0,temp,dp,0);
    }
};
