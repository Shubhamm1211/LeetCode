class Solution {
public:
    int minBitFlips(int start, int goal) {
            int xorval=start^goal;
            int count=0;
            while(xorval!=0){
                if((xorval&1)==1)count++;
                xorval=xorval>>1;
            }
            return count;
    }
};