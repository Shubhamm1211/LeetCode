class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});
        string s = "";
        while(!pq.empty()){
            int f = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            if(s.size() >= 2 and s.back() == c and s[s.size() - 2] == c){
                if(pq.empty()) break;
                int f2 = pq.top().first;
                char c2 = pq.top().second;
                pq.pop();
                f2--;
                s += c2;
                if(f2 > 0){
                    pq.push({f2,c2});
                }
            }
            else{ 
                if(f > 1){
                    s = s + c + c;
                    f = f - 2;
                }
                else {
                    s = s + c;
                    f--;
                }
            }
            if(f > 0){
                pq.push({f,c});
            }
        }
        return s;
    }
};