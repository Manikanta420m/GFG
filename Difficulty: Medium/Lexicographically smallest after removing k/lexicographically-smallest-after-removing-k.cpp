class Solution {
  public:
    string lexicographicallySmallest(string &s, int k) {
        // code here
        int n=s.size();
        if((n&(n-1))==0){
            k/=2;
        }
        else k*=2;
        if(n<k)return "-1";
        stack<char>st;
        for(auto i:s){
            while(!st.empty() and k>0 and st.top()>i){st.pop();k--;}
            st.push(i);
        }
        while(!st.empty() and k>0){st.pop();k--;}
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return (ans.size()==0?"-1":ans);
    }
};