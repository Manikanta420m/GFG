class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int ans=0;
        int n=arr.size();
        if(!(n&1))return 0;
        for(int i=0;i<n;i+=2){
            ans^=arr[i];
        }
        return ans;
    }
};