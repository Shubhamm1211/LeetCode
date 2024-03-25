class Solution {
public:
    string sortSentence(string s) {
        string str ="";
        vector<string> res(10);
        for(int i=0; i<s.size(); i++){
            if(!isdigit(s[i])) str += s[i];

            else{
                res[s[i]-'0'] = str+" ";
                str = "";
                i++;
            }
        }
        for(auto it:res) {
            str += it;
        }
        str.pop_back(); 
        return str;
        
    }
};
