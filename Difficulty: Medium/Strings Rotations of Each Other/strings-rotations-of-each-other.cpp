class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        string t1=s1+s1;
        return t1.find(s2)<t1.size();
    }
};