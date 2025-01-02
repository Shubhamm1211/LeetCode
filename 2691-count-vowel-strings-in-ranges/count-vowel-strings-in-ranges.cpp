class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {
        int n = words.size();
        set <char> st = {'a', 'e', 'i', 'o', 'u'};
        vector <int> ans, org(n), pre(n);
        for(int i = 0; i < n; i++){
            string w = words[i];
            if(st.count(w[0]) and st.count(w.back())){
                org[i] = 1;
            }
            else org[i] = 0;
        }
        pre[0] = org[0];
        for(int i = 1; i < n; i++){
            pre[i] = pre[i - 1] + org[i];
        }
        for(int i = 0; i < q.size(); i++){
            int l = q[i][0];
            int r = q[i][1];
            if(l - 1 >= 0){
                ans.push_back(pre[r] - pre[l - 1]);
            }
            else ans.push_back(pre[r]);
        }
        
        return ans; 
    }
};