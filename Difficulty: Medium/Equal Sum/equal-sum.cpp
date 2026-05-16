class Solution {
  public:
    string equilibrium(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<long long>pre(n,0);
        pre[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)pre[i]=arr[i]+pre[i+1];
        pre[0]=arr[0];
        for(int i=1;i<n;i++){
            pre[i]=arr[i]+pre[i-1];
            if(i>0 and i<n-1 and pre[i-1]==pre[i+1])return "true";
        }
        return "false";
    }
};