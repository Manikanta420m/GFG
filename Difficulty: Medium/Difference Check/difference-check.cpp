class Solution {
  public:
    int minDifference(vector<string> &arr) {
        // code here
        vector<int>a;
        int ans=INT_MAX;
        for(auto i:arr){
            int hh=stoi(i.substr(0,2))*60;
            int mm=stoi(i.substr(3,2));
            int ss=stoi(i.substr(6,2));
            int tot=(hh+mm)*60+ss;
            a.push_back(tot);
        }
        sort(a.begin(),a.end());
        for(int i=1;i<a.size();i++)ans=min(ans,a[i]-a[i-1]);
        ans=min(ans,a[0]+((24*60*60)-a[a.size()-1]));
        return ans;
    }
};
