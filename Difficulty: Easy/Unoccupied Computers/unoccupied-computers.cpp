class Solution {
  public:
    int solve(int n, string s) {
        // code here
        int ans=0;
        unordered_set<int>st,st2;
        for(auto i:s){
            if(st2.count(i))continue;
            if(st.count(i)){
                st.erase(i);
            }
            else if(st.size()<n){
                st.insert(i);
            }
            else {
                st2.insert(i);
                ans++;
            }
        }
        return ans;
    }
};
