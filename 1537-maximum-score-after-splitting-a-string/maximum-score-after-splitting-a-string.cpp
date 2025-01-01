class Solution {
public:
    int maxScore(string s) {
        int cnt1 = count(s.begin(), s.end(),'1');
        int ans = 0;
        int cnt0 = 0;
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == '1'){
                cnt1--;
            }
            else{
                cnt0++;
            }
            ans = max(ans, cnt0 + cnt1);
        }
        return ans;
    }
};