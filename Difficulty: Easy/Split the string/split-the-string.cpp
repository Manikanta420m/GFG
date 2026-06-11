class Solution {
  public:
     int isPossible(string S) {
        unordered_set<string>s;
        string str="";
        for(int i=0;i<S.size();i++)
        {
            str+=S[i];
            if(s.find(str)==s.end())
            {
            s.insert(str);
            str="";
            }
            if(s.size()==4)
            return 1;
        }
        return 0;
    }
};
