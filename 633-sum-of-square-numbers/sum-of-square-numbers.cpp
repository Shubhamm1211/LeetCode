class Solution {
public:
    bool judgeSquareSum(int c) {
        long long rt=sqrt(c);
        long long i=0,j=rt;
        while(i<=j){
            if(i*i + j*j == c)return true;
            else if(i*i + j*j>c)j--;
            else i++;
        }
        return false;
    
    }
};