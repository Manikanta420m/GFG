class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int ans=0,c=1;
        while(p){
            p-=(c*c);
            if(p<0)break;
            ans++,c++;
        }
        return ans;
    }
};
