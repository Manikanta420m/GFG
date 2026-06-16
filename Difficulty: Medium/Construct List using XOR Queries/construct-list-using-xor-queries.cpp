class Solution {
  public:
    vector<int> constructList(vector<vector<int>> &queries) {
        // code here
        vector<int>v;
        int xr=0;
        int n=queries.size();
        for(int i=n-1;i>=0;i--){
            int type=queries[i][0];
            int ele=queries[i][1];
            if(type==0){ele^=xr;v.push_back(ele);}
            else xr^=ele;
        }
        v.push_back(xr);
        sort(v.begin(),v.end());
        return v;
    }
};
