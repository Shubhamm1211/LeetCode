class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size(), ans = 0 ;
        for(int i = 0; i < n; i++){
            string curr = words[i];
            if(curr.substr(0,pref.size()) == pref){
                ans++;
            }
        }
        return ans;
    }
};