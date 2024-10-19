class Solution {
public:
    string invert(string s){
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                ans += '0';
            }
            else ans += '1';
        }
        return ans;
    }
    string reversee(string s){
        reverse(s.begin(), s.end());
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        int i = 1;
        while(n > 1){
            s = s + "1" + reversee(invert(s));
            i++;
            n--;
        }
        cout << s ;
        return s[k - 1];
    }
};