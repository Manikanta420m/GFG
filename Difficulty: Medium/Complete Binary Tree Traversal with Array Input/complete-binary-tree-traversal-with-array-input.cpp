class Solution {
  public:
    vector<vector<int>> levelSort(vector<int>& arr) {
        // code here
        vector<vector<int>>ans;
        int n=arr.size();
     //   reverse(arr.begin(),arr.end());
        int siz=1,pre=0;
        while(pre<n){
            vector<int>temp(arr.begin()+pre,min(arr.begin()+pre+siz,arr.end()));
            sort(temp.begin(),temp.end());
            ans.push_back(temp);
            pre+=siz;
            siz*=2;
        }
      //  reverse(ans.begin(),ans.end());
        return ans;
    }
};
