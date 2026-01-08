class Solution {
  public:
  int atleastK(vector<int>&arr, int k)
  {
      int n = arr.size(),i = 0,j = 0,ans = 0,count = 0;
      while(i<n && j<n)
      {
          count = count + (arr[j]%2 != 0);
          while(count== k)
          {
              ans = ans + (n-j);
              count = count - (arr[i]%2 != 0);
              i++;
          }
          j++;
      }
      return ans;
  }
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        int x1 = atleastK(arr,k+1);
        int x2 = atleastK(arr,k);
        return (x2-x1);
        
    }
};