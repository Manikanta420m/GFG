class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        // code here
        int maxi=0,ans=0;
        for(auto i:arr){
            if(i>=maxi){
                ans++;
                maxi=i;
            }
        }
        return ans;
    }
};