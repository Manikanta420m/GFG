class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int i=0,j=arr.size()-1,ans=0;
        while(i<j){
            ans=max(ans,min(arr[i],arr[j])*(j-i));
            if(arr[i]<arr[j])i++;
            else j--;
        }
        return ans;
    }
};