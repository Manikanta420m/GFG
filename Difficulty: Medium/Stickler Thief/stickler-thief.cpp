class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        int prev2=0,prev=arr[0],cur=0;
        for(int i=1;i<n;i++){
            int take=prev2+arr[i];
            int skip=prev;
            cur=max(take,skip);
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};