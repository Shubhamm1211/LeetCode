class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector <string> v1, v2;
        if(s1.size() < s2.size()) swap(s1,s2);
        int n1 = s1.size(); 
        int n2 = s2.size();
        int j = 0;
        int i = 0;
        for(; i < n1; i++){
            if(s1[i] == ' '){
                string temp = s1.substr(j, i - j);
                j = i + 1;
                v1.push_back(temp);
            }
        }
        string temp = s1.substr(j, i - j );
        v1.push_back(temp);

        int k = 0;
        int m = 0;
        for(; m < n2; m++){
            if(s2[m] == ' '){
                string temp = s2.substr(k, m - k);
                k = m + 1;
                v2.push_back(temp);
            }
        }
        string temp2 = s2.substr(k , m - k );
        v2.push_back(temp2);

        int l = 0, r = 0;
        while(l < v1.size() and l < v2.size()){
            if(v1[l] == v2[l]) l++;
            else break;
        }
        while(r < v1.size() and r < v2.size()){
            if(v1[v1.size() - r - 1] == v2[v2.size() - r - 1]) r++;
            else break;
        }
        if(l + r >= v2.size()){
            return true;
        }
        return false;
    }
};