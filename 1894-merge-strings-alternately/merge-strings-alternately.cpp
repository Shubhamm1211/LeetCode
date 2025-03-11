class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int ptr1 = 0, ptr2 = 0;
        bool f = true;
        string ans;
        while(ptr1 < n1 and ptr2 < n2){
            if(f) {
                ans += word1[ptr1];
                ptr1++;
                f = !f;
            }
            else{
                ans += word2[ptr2];
                ptr2++;
                f = !f;
            }
        }
        while(ptr1 < n1){
            ans += word1[ptr1]++;
            ptr1++;
        }
        while(ptr2 < n2){
            ans += word2[ptr2];
            ptr2++;
        }
        return ans;
    }
};