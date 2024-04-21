class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n=s.size();
        int c=0;
        for(int i=0;i<=25;i++) {
            vector<int>v1;
            vector<int>v2;
            for(int j=0;j<n;j++) {
                if(s[j]-'a'==i)
                    v1.push_back(j);
                else if(s[j]-'A'==i)
                    v2.push_back(j);
            }
            if(v1.size()>0 && v2.size()>0 && v1.back()<v2[0]) {
                c++;   
            }
        }
        return c;
    }
};