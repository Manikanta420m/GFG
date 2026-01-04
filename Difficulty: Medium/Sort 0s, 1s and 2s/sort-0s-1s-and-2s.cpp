class Solution {
  public:
    void sort012(vector<int>& a) {
        // code here
        int n=a.size();
        int l=0,r=n-1;
        int i=0;
        while(i<=r){
            if(a[i]==0){
                swap(a[l],a[i]);
                l++;
            }
            else if(a[i]==2){
                swap(a[r],a[i]);
                r--;
            }
            else i++;
            i=max(i,l);
        }
    }
};