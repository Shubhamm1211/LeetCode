class Solution {
public:
    int calc(vector <int> &v){
        int n = v.size();
        stack <pair<int,int>> st;
        vector <int> nsr(n), nsl(n);
        for(int i = 0; i < n; i++){ // nsl
            if(st.empty()){
                nsl[i] = -1;
                st.push({v[i],i}); 
            }
            else{
                while(!st.empty() and st.top().first >= v[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsl[i] = -1;
                }
                else nsl[i] = st.top().second;
                st.push({v[i], i});
            }
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i >= 0; i--){
            if(st.empty()){
                nsr[i] = n;
                st.push({v[i],i});
            }
            else{
                while(!st.empty() and st.top().first >= v[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsr[i] = n;
                }
                else nsr[i] = st.top().second;
                st.push({v[i], i});
            }
        }
        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, v[i] * (nsr[i] - nsl[i] - 1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector <vector <int>> mat2(n,vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mat2[i][j] = mat[i][j] - '0';
            }
        }
        vector <vector <int>> hist(n, vector <int>(m));
        for(int i = 0; i < m; i++){
            hist[0][i] = mat2[0][i];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat2[i][j] != 0){
                    hist[i][j] = hist[i - 1][j] + mat2[i][j];
                }
                else hist[i][j] = 0;
            }
        }
        int maxi = 0;
        for(int i = 0; i < n; i++){
            int ans = calc(hist[i]);
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};