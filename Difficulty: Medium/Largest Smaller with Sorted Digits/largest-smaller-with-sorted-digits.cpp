class Solution {
  public:
    int find(int n) {
        // code here
        while(n>0){
            bool f=true;
            int las=9;
            int ele=n;
            while(ele){
                if(las<ele%10){
                    f=false;
                    break;
                }
                las=ele%10;
                ele/=10;
            }
            if(f)return n;
            n--;
        }
        return 0;
    }
};