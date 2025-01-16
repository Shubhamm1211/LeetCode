class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if((n1 & 1) and (n2 & 1)){
            int xorr1 = nums1[0];
            for(int i = 1; i < n1; i++){
                xorr1 ^= nums1[i];
            }
            int xorr2 = nums2[0];
            for(int i = 1; i < n2; i++){
                xorr2 ^= nums2[i];
            }
            return xorr1 ^ xorr2;
        }
        if(!(n1 & 1) and !(n2 & 1)){
            return 0;
        }
        if(((n1 % 2 == 0) and (n2 & 1)) or ((n1 & 1) and (n2 % 2 == 0))){
            if(n1 % 2 == 0){
                int xorr1 = nums1[0];
                for(int i = 1; i < n1; i++){
                    xorr1 ^= nums1[i];
                }
                return xorr1;
            }
            if(n2 % 2 == 0){
                int xorr1 = nums2[0];
                for(int i = 1; i < n2; i++){
                    xorr1 ^= nums2[i];
                }
                return xorr1;
            }
        }
        return -1;
    }
};