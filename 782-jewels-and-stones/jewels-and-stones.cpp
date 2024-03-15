class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n1=jewels.size();
        int n2=stones.size();
        int cnt=0;
        for(int i=0;i<n1;i++){
            char c=jewels[i];
            for(int j=0;j<n2;j++){
                if(c==stones[j])cnt++;
            }
        }
        return cnt;
    }
};