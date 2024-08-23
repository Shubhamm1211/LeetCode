class Solution {
public:
    int getGCD(int a, int b) {
        if (a == 0) return b;
        return getGCD(b % a, a);
    }
    string fractionAddition(string expression) {
        int num = 0;
        int den = 1;
        int n = expression.length();
        int i = 0;
        while (i < n) {
            int curNum = 0;
            int curDen = 0;
            bool isNeg = false;
            char ch = expression[i];
            if (ch == '+' || ch == '-') {
                if (ch == '-') {
                    isNeg = true;
                }
                i++;
            }
            int start = i;
            while (isdigit(expression[i])) {
                i++;
            }
            curNum = stoi(expression.substr(start, i - start));
            if (isNeg) curNum *= -1;
            i++; 
            start = i;
            while (i < n && isdigit(expression[i])) {
                i++;
            }
            curDen = stoi(expression.substr(start, i - start));
            
            num = num * curDen + curNum * den;
            den *= curDen;
        }
        int gcd = abs(getGCD(num, den));
        num /= gcd;
        den /= gcd;
        return to_string(num) + "/" + to_string(den);
    }    
};
