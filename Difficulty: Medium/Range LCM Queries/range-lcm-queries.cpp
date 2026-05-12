class Solution {
  public:
  
   long long lcmVal(long long a,long long b){
       return (a/__gcd(a,b))*b;
   }
    
   void build(int node,int st,int en,vector<long long>&seg,vector<int>&arr){
       if(st==en){
           seg[node]=arr[st];
           return ;
       }
       int mid=(st+en)/2;
       build(node*2,st,mid,seg,arr);
       build(node*2+1,mid+1,en,seg,arr);
       seg[node]=lcmVal(seg[2*node],seg[2*node+1]);
   }
   
   void update(int node,int st,int en,int idx,int val,vector<long long>&seg){
       if(st==en){
           seg[node]=val;
           return ;
        }
       int mid=(st+en)/2;
       if(idx<=mid){
           update(node*2,st,mid,idx,val,seg);
       }
       else{
           update(node*2+1,mid+1,en,idx,val,seg);
       }
       seg[node]=lcmVal(seg[2*node],seg[2*node+1]);
   }
  
   long long query(int node,int st,int en,int l,int r,vector<long long>&seg){
       if(r<st or en<l)return 1;
       if(l<=st and en<=r)return seg[node];
       int mid=(st+en)/2;
       long long left=query(node*2,st,mid,l,r,seg);
       long long right=query(node*2+1,mid+1,en,l,r,seg);
       return lcm(left,right);
   }
  
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n=arr.size();
        vector<long long>seg(4*n);
        build(1,0,n-1,seg,arr);
        vector<long long>ans;
        for(auto i:queries){
            if(i[0]==1){
                int idx=i[1];
                int val=i[2];
                arr[idx]=val;
                update(1,0,n-1,idx,val,seg);
            }
            else{
                int l=i[1];
                int r=i[2];
                ans.push_back(query(1,0,n-1,l,r,seg));
            }
        }
        return ans;
    }
};