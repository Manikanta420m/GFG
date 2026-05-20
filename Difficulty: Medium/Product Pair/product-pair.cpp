class Solution {
    /*
      manikanta 
    
    */
  public:
    bool isProduct(vector<int>& arr, long long target) {
        // code here
        unordered_map<long long,long long>mp;
        for(auto i:arr){
            if(i==0){
                if(target==0)return true;
                continue;
            }
            if(target%i==0){
                long long need=target/i;
                if(mp.find(need)!=mp.end()) return true;
            }
            mp[i]=i;
        }
        return false;
    }
};