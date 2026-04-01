class Solution {
//   private:
//     int solve(int ){
        
//     }
  public:
    int countStrings(int n) {
        int a = 1;
        int b = 1;
        for(int i=0;i<n;i++)
        {
            int sum = a+b;
            b = a;
            a = sum;
        }
        return a;
    }
};