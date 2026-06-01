class Solution {
  public:
    int buyMaximumProducts(int k, vector<int> price) {
        // code here
        int n=price.size();
        vector<pair<int,int>> store;
        for(int i=0;i<n;i++){
            store.push_back({price[i],i+1});
        }
        sort(store.begin(),store.end());
        int total_stocks=0;
        for(int i=0;i<n;i++){
            int curr=store[i].first;
            int max_allowed=store[i].second;
            int can_afford=k/curr;
            
            int mini=min(can_afford,max_allowed);
            total_stocks+=mini;
            k=k-(mini*curr);
            if(k<curr){
                break;
            }
        }
        return total_stocks;
    }
};
