class Solution {
public:
    int ladderLength(string w1, string w2, vector<string>& wordList) {
        queue<pair<string,int>> q;
        q.push({w1,1});
        set<string> st(begin(wordList), end(wordList));
        while(!q.empty()){
            string word = q.front().first;
            int len = q.front().second;
            q.pop();
            if(word == w2) return len;
            for(int i = 0; i < word.size(); i++){
                char org = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,len + 1});
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};