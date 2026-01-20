class Solution {
  public:
    string ans="";
    stack<char>st;
    void append(char x) {
        // append x into document
        ans.push_back(x);
    }

    void undo() {
        // undo last change
        st.push(ans.back());
        ans.pop_back();
    }

    void redo() {
        // redo changes
        ans.push_back(st.top());
        st.pop();
    }

    string read() {
        // read the document
        return ans;
    }
};