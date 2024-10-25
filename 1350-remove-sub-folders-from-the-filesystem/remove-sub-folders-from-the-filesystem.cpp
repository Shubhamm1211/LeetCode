class Solution {
public:
    vector<string> removeSubfolders(vector<string>& f) {
        sort(f.begin(),f.end());
        int i = 0, n =f.size();
        vector<string>ans;
        while(i<n){
            string cur  = f[i];
            int j = i+1,sz = cur.size();
            while(j<n and f[j].size()>sz and cur == f[j].substr(0,sz) and f[j][sz]=='/'){
                j++;
            }

            ans.push_back(f[i]);
            i=j;
        }
        return ans;
    }
};