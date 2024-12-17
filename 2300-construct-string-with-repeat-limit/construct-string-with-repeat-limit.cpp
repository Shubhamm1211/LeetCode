class Solution {
public:
    string repeatLimitedString(string s, int maxi) {
        int n = s.size();
        map<char,int> mp;
        for(auto x : s) mp[x]++;
        priority_queue <pair<char,int>> pq;
        for(auto x : mp) pq.push({x.first,x.second}); 
        string ans = "";
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            char c = x.first;
            int freq = x.second;
            if(freq <= maxi){
                int temp = freq;
                while(temp > 0){
                    ans += x.first;
                    temp--;
                }
            }
            else{
                int left = freq - maxi;
                int temp = maxi;
                while(temp > 0){
                    ans += x.first;
                    temp--;
                }
                if(!pq.empty()){
                    auto top2 = pq.top();
                    pq.pop();
                    char c2 = top2.first;
                    int f2 = top2.second;
                    ans += c2;
                    f2--;
                    if(f2 > 0){
                        pq.push({c2,f2});
                    }
                    if(left > 0){
                        pq.push({c,left});
                    }
                }
                else break;
            }
        }
        return ans;
    }
};