class Solution {
public:
    string getEncryptedString(string s, int k) {
        k=k%s.size();
        reverse(s.begin(),s.begin()+k);
        reverse(s.begin()+k,s.end());
        reverse(s.begin(),s.end());
        return s;
    }
};