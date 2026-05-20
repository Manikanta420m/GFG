// User function template for C++

class Solution {
  public:
    long long nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    // Use symmetry property nCr = nC(n-r)
    if (r > n / 2) r = n - r;
    
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
  }

    int countPairs(vector<long> arr) {
        int n=arr.size();
        int count = 0, left = 0, right = 0;
        vector<bool>visit(n, false);
        while(right<n){
            while(right<n && !visit[arr[right]])
            {
            count +=(right-left);
            visit[arr[right]]=true;
            right++;
            }
            while(left<right && right != n && visit[arr[right]])
            {
            visit[arr[left]]=false;
            left++;
            }
        }
        return count;
    }
};