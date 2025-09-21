class Solution {
  private:
    void PSE(vector<int>&a,vector<int>&pse){
        stack<int>st;
        for(int i=0;i<a.size();i++){
            while(st.size()>0 and a[st.top()]>=a[i])st.pop();
            if(st.size()==0)pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
    }
    void NSE(vector<int>&a,vector<int>&nse){
        stack<int>st;
        for(int i=a.size()-1;i>=0;i--){
            while(st.size()>0 and a[st.top()]>=a[i])st.pop();
            if(st.size()==0)nse[i]=a.size();
            else nse[i]=st.top();
            st.push(i);
        }
    }
  public:
    int maxArea(vector<vector<int>> &mat) {
       int ans=0;
       int n=mat.size(),m=mat[0].size();
       vector<int>a(m,0);
       vector<int>nse(m),pse(m);
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               a[j]=mat[i][j]==1?a[j]+1:0;
           }
           PSE(a,pse);
           NSE(a,nse);
           for(int k=0;k<m;k++){
             if(a[k]!=0)ans=max(ans,(nse[k]-pse[k]-1)*a[k]);
             nse[k]=0;
             pse[k]=0;
           }
       }
       return ans;
    }
};