class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        int n = d.size();
        int xorr = 0;
        for(int i = 0; i < n; i++){
            xorr ^= d[i];
        }
        if(xorr != 0){
            return false;
        }
        if(n == 2){
            return xorr == 0;
        }
        int tar = d[0] ^ d.back();
        int temp = 0;
        for(int i = 1; i < n - 1; i++){
            temp ^= d[i];
        }
        return temp == tar;
    }
};