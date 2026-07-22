class Solution {
  private:
    int solve(vector<int>& arr){
        vector<int>temp;
        for(auto i:arr){
            int it=lower_bound(temp.begin(),temp.end(),i)-temp.begin();
            if(it==temp.size())temp.push_back(i);
            else temp[it]=i;
        }
        return temp.size();
    }
  public:
    int minDeletions(vector<int>& arr) {
        return arr.size()-solve(arr);
    }
};