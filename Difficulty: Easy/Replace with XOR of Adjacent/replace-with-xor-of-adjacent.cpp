class Solution {
  public:
    void replaceElements(vector<int>& arr) {
        int n=arr.size();
        // code here
        int prev=arr[0];
        arr[0]^=arr[1];
        for(int i=1;i<n-1;i++){
            int cur=arr[i];
            arr[i]=prev^arr[i+1];
            prev=cur;
        }
        arr[n-1]^=prev;
        return;
    }
};