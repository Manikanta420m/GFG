// User function Template for C++

string isDivisibleBy5(string bin) {
    int n=bin.size();
    int rem=0;
    
    for(int i=0;i<n;i++){
        if(bin[i]=='0'){
            rem=(rem*2)%5;
        }
        else{
            rem=(rem*2 + 1)%5;
        }
    }
    
    if(rem==0){
        return "Yes";
    }
    else{
        return "No";
    }

}