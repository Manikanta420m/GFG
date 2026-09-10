class Solution {
  public:
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    }
    int lcm(int a,int b){
        return (a*b)/gcd(a,b);
    }
    int pairCount(int x, int y) {
         int req=x*y,c=0,ans=0;
         for(int i=1;i*i<=req;i++){
             if(req%i==0){
                 int a=i,b=req/i;
                 if(gcd(a,b)==x and lcm(a,b)==y){
                     ans++;
                     if(a!=b)ans++;
                 }
                /// req/=i;
             }
         }
         return ans;
    }
};


