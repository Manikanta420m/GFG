class Solution {
  public:
    string smallestNumber(string &num) {
        // code here
         int n=num.length();
    //code here.
    int arr[n];
    int midx=n-1,idx=0;
    for(int i=n-1;i>=0;i--){
        if(num[idx]>num[i] && num[i]!='0')idx=i;
        if(num[midx]>num[i]){
            midx=i;
        }
        arr[i]=midx;
    }
    if(idx!=0){swap(num[idx],num[0]);return num;}
    for(int i=1;i<n;i++){
        if(num[i]>num[arr[i]]){swap(num[i],num[arr[i]]);break;}
    }
    return num;
    }
};