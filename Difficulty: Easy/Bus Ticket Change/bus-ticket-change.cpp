class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int f=0,t=0,tw=0;
        for(auto i:arr){
            if(i==5){f++;continue;}
            else if(i==10){t++;f--;if(f<0)return false;}
            else{
                tw++;
                f--;
                if(t>0 and f>=0)t--;
                else if(f>=2)f-=2;
                else return false;
            }
        }
        return true;
    }
};