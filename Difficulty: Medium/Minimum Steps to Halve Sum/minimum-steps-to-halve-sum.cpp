class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        int ans=0;
        priority_queue<double>q(arr.begin(),arr.end());
        double sm=(double)accumulate(arr.begin(),arr.end(),0);
        double req=sm/2.0;
        while(sm>req){
            double ele=q.top();
            q.pop();
            sm-=(ele/2.0);
            q.push(ele/2.0);
            ans++;
        }
        return ans;
    }
};