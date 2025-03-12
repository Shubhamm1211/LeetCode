class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        string ans = "";
        priority_queue<pair<int, char>> pq;
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        for (auto x : mp) {
            if (x.second > (n + 1) / 2) return "";
            pq.push({x.second, x.first});
        }
        vector<char> v(n, '#');
        int ptr = 0;
        while (!pq.empty()) {
            char c = pq.top().second;
            int freq = pq.top().first;
            pq.pop();
            while (ptr < n && freq > 0) {
                v[ptr] = c;
                ptr += 2;
                freq--;
            }
            if (ptr >= n) ptr = 1;
            while (ptr < n && freq > 0) {
                v[ptr] = c;
                ptr += 2;
                freq--;
            }
        }
        for (int i = 0; i < n; i++) {
            ans += v[i];
        }
        for (int i = 0; i < n - 1; i++) {
            if (ans[i] == ans[i + 1] or ans[i] == '#') return "";
        }
        return ans;
    }
};
