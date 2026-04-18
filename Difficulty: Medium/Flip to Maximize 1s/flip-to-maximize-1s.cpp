class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int n = arr.size();
        
        vector <int> onesMap(n);
        onesMap[0] = arr[0];
        for (int i = 1; i < n; i++) {
            onesMap[i] = onesMap[i - 1] + arr[i];
        }
        
        int ans = onesMap[n - 1];
        
        int subarray = 0;
        for (int left = 0, right = 0; left < n && right < n; right++) {
            if (arr[right] == 0)
                subarray++;
            else
                subarray--;
                
            if (subarray <= 0) {
                subarray = 0;
                left = right + 1;
                continue;
            }
            
            int outsideOnes = onesMap[n - 1] - 
                (onesMap[right] - (left == 0 ? 0 : onesMap[left - 1]));
                
            int inside = (right - left + 1) -
                (onesMap[right] - (left == 0 ? 0 : onesMap[left - 1]));
            ans = max(ans, outsideOnes + inside);
        }
        
        return ans;
    }
};

