class Solution {
  public:
    static bool comp(string first,string second){
        return (first+second<second+first);
    }
  
    string findLargest(vector<int> &arr) {
        vector<string>v;
        for(auto i:arr)v.push_back(to_string(i));
        sort(v.rbegin(),v.rend(),comp);
        string s="";
        for(auto i:v){s+=i;}
        return (s[0]=='0'?"0":s);
    }
};