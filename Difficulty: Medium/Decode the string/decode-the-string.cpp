class Solution {
  public:
    string decodedString(string &s) {
        // code here
        string ans="";
        stack<string>str;
        stack<int>cnt;
        int num=0;
        for(auto c:s){
            if(isdigit(c)){
                num=num*10+(c-'0');
            }
            else if(c=='['){
                cnt.push(num);
                num=0;
                str.push(ans);
                ans="";
            }
            else if(c==']'){
                int rep=cnt.top();
                cnt.pop();
                
                string temp=str.top();
                str.pop();
                
                for(int i=0;i<rep;i++){
                    temp+=ans;
                }
                ans=temp;
            }
            else ans+=c;
        }
        return ans;
    }
};