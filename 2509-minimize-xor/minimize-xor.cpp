class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n1 = __builtin_popcount(num1);
        int n2 = __builtin_popcount(num2);

        if (n1 == n2) {
            return num1; 
        }
        if (n1 < n2) {
            int x = num1; 
            int rem = n2 - n1; 
            for(int i = 0; rem > 0 and i < 32; i++){
                if((x & (1 << i)) == 0){
                    x |= (1 << i);
                    rem--;
                }
            }
            return x;
        }
        int x = num1;
        int rem = n1 - n2; 
        for (int i = 0; rem > 0 && i < 32; ++i) {
            if (x & (1 << i)) {
                x &= ~(1 << i);
                rem--;        
            }
        }
        return x;
    }
};
