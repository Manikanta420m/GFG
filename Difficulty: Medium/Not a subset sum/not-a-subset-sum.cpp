class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        long long maxi=1;
        sort(arr.begin(),arr.end());
        for(auto i:arr){
            if(i>maxi)return maxi;
            else maxi+=i;
        }
        return maxi;
    }
};