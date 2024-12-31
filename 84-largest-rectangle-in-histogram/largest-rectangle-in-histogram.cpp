class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector <int> nsr(n), nsl(n);
        stack <pair<int,int>> st1, st2;
        for(int i = n - 1; i >= 0; i--){ // for nsr
            if(st1.empty()){
                nsr[i] = n;
                st1.push({h[i],i});
            }
            else{
                while(!st1.empty() and h[i] <= st1.top().first){
                    st1.pop();
                }
                if(st1.empty()){
                    nsr[i] = n;
                }
                else nsr[i] = st1.top().second;
                st1.push({h[i],i});
            }
        }

        for(int i = 0; i < n; i++){ // for nsl
            if(st2.empty()){
                nsl[i] = -1;
                st2.push({h[i],i});
            }
            else{
                while(!st2.empty() and h[i] <= st2.top().first){
                    st2.pop();
                }
                if(st2.empty()){
                    nsl[i] = -1;
                }
                else nsl[i] = st2.top().second;
                st2.push({h[i],i});
            }
        }
        int maxi = 0;
        for(auto &it : nsr) cout << it << " " ;
        cout << endl;
        for(auto &it : nsl) cout << it << " " ;
        cout << endl;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, h[i] * (nsr[i] - nsl[i] - 1));
        }
        return maxi;
    }
};