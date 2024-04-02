class Solution {
public:
    string greatestLetter(string s) {
     vector<int>v1(26,0); 
     vector<int>v2(26,0);
     for(int i=0;i<s.size();i++){
            if(s[i]-'a'>=0 &&  s[i]-'a'<=25){
                v2[s[i]-'a']++;   
            }
            else if(s[i]-'A'>=0 &&  s[i]-'A'<=25){
                v1[s[i]-'A']++;
            }
        }
        string k;
        for(int i=25;i>=0;i--){
            if(v1[i]>0 && v2[i]>0){
                k.push_back(i+'A'); 
                break;
            }
        }
        return k;
    }
};