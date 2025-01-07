class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector <string> ans;
        set <string> st;
        for(int i = 0; i < n; i++){
            string s = words[i];
            for(int j = 0; j < n; j++){
                if(i != j){
                    string curr = words[j];
                    for(int k = 0; k < curr.size(); k++){
                        if(curr.substr(k,s.size()) == s){
                            if(st.find(s) == st.end()){
                                ans.push_back(s);
                                st.insert(s);
                            }
                        }
                    }
                }
            }
            
        }
        return ans;
    }
};