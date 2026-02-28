class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        vector<int>ans;
        int i=0,j=arr2.size()-1,maxi=INT_MAX;
        while(i<arr1.size() and j>=0){
            int sm=arr1[i]+arr2[j];
            int dif=abs(x-sm);
            if(dif<maxi){
                maxi=dif;
                ans=vector<int>{arr1[i],arr2[j]};
            }
            if(sm>x)j--;
            else i++;
        }
        return ans;
    }
};