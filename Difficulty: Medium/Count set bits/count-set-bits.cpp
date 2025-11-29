// class Solution {
//   public:
//     int countSetBits(int n) {
//         // code here
//         int ans=0;
//         for(int i=1;i<=35;i++){
//             int pw=(1<<i);
//             int pw2=(1<<i-1);
//             int div=(n+1)/pw;
//             int rem=(n+1)%pw;
//             if(div&1){
//                 ans+=(div/2)*pw2;
//                 ans+=rem;
//             }
//             else{
//                 ans+=(div/2)*pw2;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
  public:
    int countSetBits(int n) {
        long long ans = 0;
        for (int b = 0; b < 31; ++b) {
            long long half  = 1LL << b;
            long long cycle = half << 1;
            if (half > n) break;
            long long full = ( (long long)n + 1 ) / cycle;
            long long rem  = ( (long long)n + 1 ) % cycle;
            ans += full * half;
            ans += max(0LL, rem - half);
        }
        return (int)ans; // careful: may overflow for big n; prefer long long return
    }
};
