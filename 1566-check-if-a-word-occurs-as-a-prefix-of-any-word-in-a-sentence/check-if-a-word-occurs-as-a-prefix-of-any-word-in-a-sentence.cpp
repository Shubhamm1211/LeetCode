class Solution {
public:
    bool check(string s1, string s2){
        int n1 = s1.size();
        int n2 = s2.size();
        for(int i = 0; i < n2; i++){
            if(s1[i] != s2[i]) return false;
        }
        return true;
    }
    int isPrefixOfWord(string sen, string s) {
        vector <string> v;
        int j = 0;
        for(int i = 0; i < sen.size(); i++){
            if(sen[i] == ' '){
                v.push_back(sen.substr(j, i - j));
                j = i + 1;
            }
        }
        v.push_back(sen.substr(j,sen.size() - j));
        for(int i = 0; i < v.size(); i++){
            if(check(v[i],s)) return i + 1;
        }
        return -1;
    }
};