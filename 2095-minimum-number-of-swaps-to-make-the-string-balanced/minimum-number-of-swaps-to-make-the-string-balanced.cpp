class Solution {
public:
    int minSwaps(string s) {
        int n=0;
        
        for(auto ch : s) {
            if(ch=='[')n++;
            else if(n!=0) n--;
        }
        
        return (n+1)/2;
    }
};