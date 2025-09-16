class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        // code here
        stack<int>st;
        for(auto i:arr){
            if(i=="*" || i=="+" || i=="-" || i=="/" || i=="^"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(i=="+")st.push(a+b);
                if(i=="-")st.push(b-a);
                if(i=="*")st.push(a*b);
                if(i=="/"){
                    int div=b/a;
                    int rem=abs(b)%abs(a);
                    if(rem!=0 and (a*b)<0)div--;
                    st.push(div);
                }
                if(i=="^")st.push((int)pow(b,a));
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};