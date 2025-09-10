class Solution {
  public:
    string largestSwap(string &s) {
        // code here
        string s1=s;
        sort(s1.rbegin(),s1.rend());
        for(int i=0;i<s.size();i++){
            if(s[i]!=s1[i]){
                for(int j=s.size()-1;j>i;j--){
                    if(s[j]==s1[i]){
                        swap(s[i],s[j]);
                        return s;
                    }
                }
            }
        }
        return s;
    }
};