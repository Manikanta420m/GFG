class Solution {
  public:
    int maxTask(vector<int>& h, vector<int>& l) {
        int n=h.size();
        int prev1=0,prev2=0;
        for(int i=0;i<n;i++){
            int res=max(prev1+l[i],prev2+h[i]);
            prev2=prev1;
            prev1=res;
        }
        return prev1;
    }
};