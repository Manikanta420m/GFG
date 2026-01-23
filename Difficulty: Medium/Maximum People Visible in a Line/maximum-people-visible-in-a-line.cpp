class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>pge(n,0);
        stack<int>s1;
        s1.push(0);
        pge[0]=-1;
        for(int i=1;i<n;i++){
            while(!s1.empty() and arr[s1.top()]<arr[i])s1.pop();
            pge[i]=(s1.empty()?-1:s1.top());
            s1.push(i);
        }
        vector<int>nge(n,0);
        stack<int>s2;
        s2.push(n-1);
        nge[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!s2.empty() and arr[s2.top()]<arr[i])s2.pop();
            nge[i]=(s2.empty()?n:s2.top());
            s2.push(i);
        }
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,nge[i]-pge[i]-1);
        }
        return ans;
    }
};