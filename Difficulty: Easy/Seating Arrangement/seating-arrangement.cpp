class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        for(int i=0;i<seats.size() and k>0;i++){
            if(seats[i]==0){
                int left=(i==0)?0:seats[i-1];
                int right=(i==seats.size()-1?0:seats[i+1]);
                if(left==0 and right==0){
                    seats[i]=1;
                    k--;
                }
            }
        }
        return k==0;
    }
};