class Solution {
public:
    vector<int> assignElements(vector<int>& g, vector<int>& e) {
        int n1 = g.size();
        int n2 = e.size();
        map <int,int> mp;
        for(int i = 0; i < n2; i++){
            if(mp.find(e[i]) == mp.end()){
                mp[e[i]] = i;
            }
        }
        vector <int> ans(n1,INT_MAX);
        for(int i = 0; i < n1; i++){
            int num = g[i];
            for(int j = 1; j * j <= num; j++){
                if(num % j == 0){
                    if(mp.find(j) != mp.end()){
                        ans[i] = min(ans[i], mp[j]);
                    }
                    if(num / j != j){
                        if(mp.find(num / j) != mp.end()){
                            ans[i] = min(ans[i], mp[num / j]);
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n1; i++){
            if(ans[i] == INT_MAX) ans[i] = -1;
        }
        return ans;
    }
};