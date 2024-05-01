class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int sum=0;
        vector<char> v={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        for(int i=s.size()-1;i>=0;i--){
            sum=(sum+shifts[i])%26;
            int k=s[i]-'a';
            s[i]=v[(k+sum)%26];
        }
        return s;
    }
};