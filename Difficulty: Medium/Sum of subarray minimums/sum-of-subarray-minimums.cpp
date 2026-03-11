class Solution {
  public:
    vector<int>getPSE(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() and arr[i]<arr[st.top()])st.pop();
            if(st.empty())pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int>getNSE(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>nse(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and arr[i]<=arr[st.top()])st.pop();
            if(st.empty())nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        return nse;
    }
    int sumSubMins(vector<int> &arr) {
        // code here
        int ans=0;
        vector<int>nse=getNSE(arr);
        vector<int>pse=getPSE(arr);
        for(int i=0;i<arr.size();i++){
            int lf=i-pse[i];
            int rg=nse[i]-i;
            ans+=(lf*rg*arr[i]);
        }
        return ans;
    }
};