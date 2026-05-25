class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int ans=0;
        for(auto i:arr){
            if(i>=start and i<=end)ans++;
        }
        return ans==(end-start+1);
    }
};
