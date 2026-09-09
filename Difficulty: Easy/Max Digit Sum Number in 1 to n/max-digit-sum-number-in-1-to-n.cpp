class Solution {
  public:
    int findMax(int n) {
        // code Here
        int sm1=0,sm2=0;
        int n1=n,ele=0,c=0,nine=0;
        while(n1>=10){
            sm2+=(n1%10);
            sm1+=9;
            ele=n1%10;
            n1/=10;
            c++;
            nine=(nine*10)+9;
        }
        ele=n1;
        sm2+=ele;
        sm1+=(ele-1);
        if(sm2>=sm1)return n;
        int ans=0;
        int c1=1;
        int elex=(nine+(pow(10,c)*(ele)));
        for(int i=0;i<c;i++){
            int res=elex-c1;
            if(res<=n)ans=max(ans,res);
            c1*=10;
        }
        return max(ans,(int)(nine+(pow(10,c)*(ele-1))));
    }
};
