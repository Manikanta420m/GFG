class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& intervals, int k) {
        // code here
        map<int,int>st,en;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            ++st[intervals[i][0]];
            ++en[intervals[i][1]];           
        }
        int ls=0;
        for(auto &e:st){
            e.second+=ls;
            ls=e.second;
        }
        int ans=-1;
        ls=0;
        auto e=en.begin();
        while(e!=en.end()){
            en[(*e).first]+=ls;
            ls=(*e).second;
            auto ptr=e;
            auto stptr=st.lower_bound((*e).first);
            if(stptr==st.end() or (*stptr).first>(*e).first)--stptr;
            int strd=(*stptr).second;
            int end=0;
            if(ptr!=en.begin()){
                --ptr;
                end=(*ptr).second;
            }
            if(strd-end>=k){
                ans=max(ans,(*e).first);
            }
            ++e;
        }
        return ans;
    }
};