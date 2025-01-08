class Solution {
public:
    bool check(string s1, string s2){
        if(s1.size() > s2.size()){
            return false;
        }
        int n1 = s1.size(), n2 = s2.size();
        string pre = s2.substr(0,n1);
        string suff = s2.substr(n2 - n1, n1);
        return pre == s1 and suff == s1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(check(words[i],words[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};