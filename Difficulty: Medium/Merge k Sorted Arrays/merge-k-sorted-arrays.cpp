class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        priority_queue<int,vector<int>,greater<int>>ch;
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
                ch.push(mat[i][j]);
        }
        
        vector<int>v;
        
        while(!ch.empty())
        {
            //work
            
            v.push_back(ch.top());
            ch.pop();
        }
        return v;
    }
};