// User function Template for C++

class Solution {
  public:
    int maxValue(vector<int>& arr) {
        // code here
        int max1=INT_MIN, min1=INT_MAX, max2=INT_MIN, min2=INT_MAX;
        int n = arr.size();
        for(int i=0;i<n;i++){
            max1 = max(max1, arr[i]+i);
            min1 = min(min1, arr[i]+i);
            
            max2 = max(max2, arr[i]-i);
            min2 = min(min2, arr[i]-i);
        }
        
        
        int dif1 = max1-min1;
        int dif2 = max2-min2;
        
        return max(dif1, dif2);
    }
};