class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
         vector<int>t = arr;
        sort(t.begin(),t.end());
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        int c = 0;
        int i=0;
        while(i<arr.size()){
            if(arr[i]!=t[i]){
                int temp = mp[t[i]];
                mp[t[i]] = i;
                mp[arr[i]] = temp;
                swap(arr[i],arr[temp]);
                c++;
            }
            i++;
        }
        return c;
    }
};