class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int i=0,j=0,ans=0;
        while(j<arr.size()){
            while(abs(arr[i]-arr[j])>=k){
                i++;
            }
            ans+=(j-i)*(abs(arr[i]-arr[j])<k);
            j++;
        }
        return ans;
    }
};