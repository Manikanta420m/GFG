class Solution {
  public:
    int countWays(int n, int k) {
        // code here
        int ans=1;
        int prev=1;
        for(int i=1;i<n;i++){
            int temp=((k-1)*ans);
            ans=(prev+temp);
            prev=temp;
        }
        return (ans*k);
    }
};