class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        vector<int>a;
        int n=arr.size();
        int tot=(n+1)/2,ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%k>0)a.push_back(k-(arr[i]%k));
            else tot--;
        }
        sort(a.begin(),a.end());
        for(int i=0;i<tot;i++)ans+=a[i];
        return ans;
    }
};