class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        map<int,int>mp;
        int sm=0,n=arr.size(),ans=0;
        for(int i=0;i<n;i++){
            auto it=arr[i];
            if(it>k){
                sm++;
            }
            else sm--;
            if(sm>0)ans=i+1;
            else{
                if(mp.find(sm-1)!=mp.end()){
                    ans=max(ans,(i-mp[sm-1]));
                }
            }
            if(mp.find(sm)==mp.end()){
                mp[sm]=i;
            }
        } 
        return ans;
    }
};