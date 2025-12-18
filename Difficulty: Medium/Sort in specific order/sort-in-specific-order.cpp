class Solution {
  private:
    static bool comp(int a,int b){
        if(a&1 and b&1)return a>b;
        else if(!(a&1) and !(b&1))return a<b;
        else if(a&1)return true;
        else return false;
    }
  public:
    void sortIt(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end(),comp);
    }
};