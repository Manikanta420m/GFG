class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        stack<char>st;
        for(auto i:s){
            if(!st.empty() and i==')'  and st.top()=='('){
                st.pop();
            }
            else{
                st.push(i);
            }
        }
        return st.size();
    }
};