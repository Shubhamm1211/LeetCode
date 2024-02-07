class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = haystack.find(needle);
        if(index>=0) return index;
        else return -1;
    }
};