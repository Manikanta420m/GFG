class Solution {
  public:
    void move(int &i, int &j, int &dir)
    {
        if(dir==1)
        {
            j++;
        }
        else if(dir==2)
        {
            i++;
        }
        else if(dir==3)
        {
            j--;
        }
        else
        {
            i--;
        }
    }
    vector<int> exitPoint(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int dir=1;
        int i=0,j=0;
        while(i<n && j<m && i>=0 && j>=0)
        {
            if(mat[i][j]==0)
            {
                move(i,j,dir);
            }
            else
            {
                mat[i][j]=0;
                dir=(dir+1)%4;
                move(i,j,dir);
            }
            
        }
        if(i>=0 && i<n && j==-1)
        {
            return {i,0};
        }
        else if(i>=0 && i<n && j==m)
        {
            return {i,m-1};
        }
        else if(j>=0 && j<m && i==-1)
        {
            return {0,j};
        }
        else
        {
            return {n-1,j};
        }
    }
};