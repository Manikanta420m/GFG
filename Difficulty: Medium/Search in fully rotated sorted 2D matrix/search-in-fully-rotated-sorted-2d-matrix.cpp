class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int l=0,r=n*m-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int ele=mat[mid/m][mid%m];
            int l1=mat[l/m][l%m];
            int r1=mat[r/m][r%m];
            if(x==ele)return true;
            if(l1<=ele){
                if(l1<=x and x<ele)r=mid-1;
                else l=mid+1;
            }
            else{
                if(x>ele and x<=r1)l=mid+1;
                else r=mid-1;
            }
        }
        return false;
    }
};
