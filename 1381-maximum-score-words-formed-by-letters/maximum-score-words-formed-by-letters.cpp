class Solution {
public:
    int a[26], b[26], ans = 0;
    void solve(int i, vector<string>& words, vector<int>& score) {
        if(i==words.size()){
            int sc=0;
            for(int i=0;i<26;i++){
                if(b[i]>a[i])return;
                sc=sc+b[i]*score[i];
            }
            ans=max(ans,sc);
            return;
        }
        solve(i+1,words,score);
        for(auto x:words[i])b[x-'a']++;
        solve(i+1,words,score);
        for(auto x:words[i])b[x-'a']--;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for (auto i : letters) a[i - 'a']++;
        solve(0, words, score);
        return ans;
    }
};