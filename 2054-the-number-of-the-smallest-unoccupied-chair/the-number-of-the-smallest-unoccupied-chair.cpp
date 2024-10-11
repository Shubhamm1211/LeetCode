#define pi pair<int,int>

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector <pair<pi,int>> v; // {{arrive,leave},ind};
        for(int i = 0; i < times.size(); i++){
            v.push_back({{times[i][0],times[i][1]},i});
        }
        sort(begin(v),end(v));
        priority_queue <int,vector<int>,greater<int>> pq1;
        for(int i = 0; i < times.size(); i++){
            pq1.push(i);
        }
        priority_queue <pi,vector<pi>, greater<pi>> pq2; //{leave,chairNum}

        for(int i = 0; i < v.size(); i++){
            int curr = v[i].first.first;
            int lea = v[i].first.second;
            int ind = v[i].second;
            while(!pq2.empty() and curr >= pq2.top().first){
                pq1.push(pq2.top().second);
                pq2.pop();
            }
            if(targetFriend == ind){
                return pq1.top();
            }

            pq2.push({lea,pq1.top()});
            pq1.pop();
        }
        return -1;
    }
};