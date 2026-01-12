class Solution {
  public:
    virtual vector<int> maxOfSubarrays(vector<int>& arr, int k){
      int maxi=-1, maxv=INT_MIN;
      int i=0, n=arr.size();
      
      vector<int> ans;
      for(int j=0; j<n; j++){
        if(maxv < arr[j]) {maxv=arr[j]; maxi=j;}
        
        if((j-i+1) == k){
          ans.push_back(maxv);
          if(i == maxi){
            i++;
            maxv=INT_MIN;
            for(int k=i; k<=j; k++){
              if(arr[k] > maxv) {maxv=arr[k]; maxi=k;}    
            }
          }else{
              i++;
          }
        }
      }
      
      return ans;
    }
};