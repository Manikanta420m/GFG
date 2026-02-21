class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int ans=0,n=citations.size();
        sort(citations.begin(),citations.end());
        for (int i=0; i<n; i++){
            int cit = citations[i];
            if (cit >= (n-i)) return n-i;
        }
        return 0;
    }
};