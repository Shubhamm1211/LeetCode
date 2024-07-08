class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>v(n,0);
        int ptr=0;
        for(int i=0;i<n;i++){
            v[i]=i+1;
        }
        while(n>1){
            ptr=(ptr+k-1)%n;
            v.erase(v.begin()+ptr);
            n--;
        }
        return v[0];
        
    }
};