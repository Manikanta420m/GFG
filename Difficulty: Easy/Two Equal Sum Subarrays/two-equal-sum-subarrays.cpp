class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        long long sm=accumulate(arr.begin(),arr.end(),0LL);
        for(int i=0;i<arr.size();i++){
            arr[i]+=(i!=0?arr[i-1]:0);
            if(arr[i]==sm-arr[i])return true;
        }
        return false;
    }
};
