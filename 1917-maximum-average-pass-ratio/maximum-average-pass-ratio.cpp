class Solution {
public:
    double delta(int a, int b){
        double alpha = (double)(a + 1) / (b + 1) - ((double)a/b);
        return alpha;
    }
    double maxAverageRatio(vector<vector<int>>&v, int e) {
        int n = v.size();
        priority_queue<pair<double, pair<int,int>>> pq;
        for(auto &vec : v){
            pq.push({delta(vec[0],vec[1]),{vec[0],vec[1]}});
        }
        while(e--){
            auto temp = pq.top();
            pq.pop();
            double del = temp.first;
            int pass = temp.second.first;
            int tot = temp.second.second;
            pq.push({delta(pass + 1,tot + 1), {pass + 1,tot + 1}});
        }
        double alpha = 0;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            double rat = (double)temp.second.first / (double)temp.second.second;
            alpha += rat;
        }
        double ans = (double)alpha / n;
        return ans;
    }
};