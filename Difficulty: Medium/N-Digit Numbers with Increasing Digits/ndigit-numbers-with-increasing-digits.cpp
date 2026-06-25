class Solution {
  public:
    vector<int> increasingNumbers(int n) {
        // code here
        vector<int>ans={1,2,3,4,5,6,7,8,9};
        if(n==1)return {0,1,2,3,4,5,6,7,8,9};
        if(n>9)return {};
        queue<int>q;
        for(auto i:ans)q.push(i);
        n-=1;
        while(n--){
            int siz=q.size();
            for(int i=0;i<siz;i++){
                int ele=q.front();
                q.pop();
                int las=ele%10;
                for(int j=las+1;j<=9;j++){
                    q.push(ele*10+j);
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};