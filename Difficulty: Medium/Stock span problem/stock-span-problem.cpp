class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n=arr.size();
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[st.top()]<=arr[i])st.pop();
            if(st.empty())ans.push_back(i+1);
            else ans.push_back((i-st.top()));
            st.push(i);
        }
        return ans;
    }
};