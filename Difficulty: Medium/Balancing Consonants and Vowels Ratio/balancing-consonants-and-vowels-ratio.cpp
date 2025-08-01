class Solution {
  private:
    int vowelCount(string s){
        int cnt=0;
        for(auto i:s)cnt+=(i=='a'||i=='e'||i=='i'||i=='o'||i=='u'?1:0);
        return cnt;
    }
  public:
    int countBalanced(vector<string>& arr) {
       int n=arr.size(),ans=0,t=0;
       map<int,int>mp;
       mp[0]=1;
       for(int i=0;i<n;i++){
           int vowel_cnt=vowelCount(arr[i]);
           int const_cnt=arr[i].size()-vowel_cnt;
           int diff=vowel_cnt-const_cnt;
           t+=diff;
           ans+=mp[t];
           mp[t]++;
       }
       return ans;
    }
};