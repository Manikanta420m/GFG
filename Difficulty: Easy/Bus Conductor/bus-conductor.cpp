class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        // code here
        int ans;
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        for(int i=0;i<chairs.size();i++){
            ans+=abs(chairs[i]-passengers[i]);
        }
        return ans;
    }
};