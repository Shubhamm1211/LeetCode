class Solution {
public:
    int appendCharacters(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else if(s[i]!=t[j]){
                i++;
            }
        }
        int ans=t.size()-j;
        return ans;
    }
};