class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> p = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };
        reverse(begin(p), end(p));
        string result = "";
        for(auto &x : p){
            while(num >= x.first){
                result += x.second;
                num -= x.first;
            }
        }
        return result;
    }
};