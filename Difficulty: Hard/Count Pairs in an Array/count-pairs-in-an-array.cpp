class Solution {
  public:
    int countPairs(vector<int>& arr) {
        // code here
        int count = 0;
         int n=arr.size();
        vector<int>b,s;
       for(int i=0;i<n;i++){
           b.push_back(i*arr[i]);
           s.push_back(b[i]);
       }
       sort(s.begin(),s.end());
       int ans=0;
       for(int i=0;i<n;i++){
           int i1=lower_bound(s.begin(),s.end(),b[i])-s.begin();
           count+=i1;
           s.erase(s.begin()+i1);
       }
       return count;
    }
};