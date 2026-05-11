// User function Template for C++
class Solution {
  public:
  int f(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            int coins=nums[i-1]*nums[k]*nums[j+1];
            int rem_coins=f(k+1,j,nums,dp)+f(i,k-1,nums,dp);
            ans=max(ans,coins+rem_coins);
        }
        return dp[i][j]=ans;
    }
    
    int maxCoins(int N, vector<int> &nums) {
         int n=nums.size();
         vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
         nums.push_back(1);
         nums.insert(nums.begin(),1);
         return f(1,n,nums,dp);
    }
};

// class Solution {
// public:
//     int f(int i,int j,vector<int>& nums,vector<vector<int>>&dp){
//         if(i>j)return 0;
//         if(dp[i][j]!=-1)return dp[i][j];
//         int ans=INT_MIN;
//         for(int k=i;k<=j;k++){
//             int coins=nums[i-1]*nums[k]*nums[j+1];
//             int rem_coins=f(k+1,j,nums,dp)+f(i,k-1,nums,dp);
//             ans=max(ans,coins+rem_coins);
//         }
//         return dp[i][j]=ans;
//     }
//     int maxCoins(vector<int>& nums) {
//      int n=nums.size();
//      vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
//      nums.push_back(1);
//      nums.insert(nums.begin(),1);
//      return f(1,n,nums,dp);
//     }
// };