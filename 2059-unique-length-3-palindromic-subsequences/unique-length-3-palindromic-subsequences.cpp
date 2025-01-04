class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector <int> fo(26,-1), lo(26,-1);
        for(int i = 0; i < s.size(); i++){
            if(fo[s[i] - 'a'] == -1){
                fo[s[i] - 'a'] = i;
            }
        }
        for(int i = s.size() - 1; i >= 0; i--){
            if(lo[s[i] - 'a'] == -1){
                lo[s[i] - 'a'] = i;
            }
        }
        int ans = 0;
        set <string> st;
        for(int i = 0; i < 26; i++){
            char c = char(i + 'a');
            string temp = "";
            for(int j = 0; j < 3; j++){
                temp += c;
            }
            temp[1] = '#';
            if(fo[i] != -1 and lo[i] != -1 and lo[i] > fo[i]){
                string temp2 = temp;
                for(int k = fo[i] + 1; k < lo[i]; k++){
                    temp2[1] = s[k];
                    st.insert(temp2);
                }
                cout << temp2 << endl;
            }
        }
        return st.size();
    }
};