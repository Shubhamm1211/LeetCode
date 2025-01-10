class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxi(26, 0);
        for (auto& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxi[i] = max(maxi[i], freq[i]);
            }
        }
        vector <string> ans;
        for (auto word : words1) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            bool f = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxi[i]) {
                    f = false;
                    break;
                }
            }
            if (f) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
