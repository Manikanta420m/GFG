class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int n=a.size(),m=b.size();
        int i=0,j=0,sm1=0,sm2=0;
        a.push_back(INT_MAX);
        b.push_back(INT_MAX);
        while(i<n or j<m){
            if(a[i]<b[j]){
                sm1+=a[i];
                i++;
            }
            else if(a[i]>b[j]){
                sm2+=b[j];
                j++;
            }
            else{
                sm1=max(sm1,sm2)+a[i];
                sm2=sm1;
                i++,j++;
            }
        }
        return max(sm1,sm2);
    }
};