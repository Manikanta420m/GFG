class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
         int zero=0, i=0;

        int ans=0;
        int n=arr.size();

        

        while(zero!=n){

          zero=0;


           for(i=0;i<n;i++){

              if(arr[i]%2!=0){

                ans+=1;

                arr[i]-=1;

              }

              if(arr[i]==0){

                  zero++;

              }

            }

            for(i=0;i<n;i++){

                arr[i]=arr[i]/2;

            } 

             ans++;

        }

        return ans-1;


    }
};