class Solution
{
public:
    bool help(string all, set<char> st){
        set<char> stl;
        for (auto i : all)
            stl.insert(i);
        for (auto i : st){
            if (stl.find(i) == stl.end())
            return false;
        }
        return true;
    }

    int countConsistentStrings(string allowed, vector<string> &words){
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            set<char> st;
            for (auto j : words[i])
                st.insert(j);
            bool chec = help(allowed, st);
            if (chec)
                ans++;
        }
        return ans;
    }
};