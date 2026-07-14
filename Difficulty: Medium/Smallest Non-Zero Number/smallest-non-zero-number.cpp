class Solution {
  public:
    int find(vector<int>& arr) {
        // code here
        int x=0;
        for(int i=arr.size()-1;i>=0;i--){
            x=(x+arr[i]+1)/2;
        }
        return max(1,x);
    }
};