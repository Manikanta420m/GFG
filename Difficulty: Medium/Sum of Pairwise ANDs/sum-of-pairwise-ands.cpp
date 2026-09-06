class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        long long ans=0;
        for(int i=0;i<32;i++){
            long long bit=1<<i;
            long long c=0;
            for(auto j:arr){
                if(j&bit)c++;
            }
            if(c>1)ans+=(bit*(c*(c-1)/2));
        }
        return ans;
    }
};