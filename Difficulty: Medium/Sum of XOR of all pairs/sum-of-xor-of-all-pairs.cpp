class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n=arr.size();
        long long res=0;
        for(int i=0;i<32;i++){
            long long c1=0,c0=0;
            for(int j=0;j<n;j++){
                if(arr[j]&(1<<i))c1++;
                else c0++;
            }
            res+=(c0*c1)*(1LL<<i);
        }
        return res;
    }
};