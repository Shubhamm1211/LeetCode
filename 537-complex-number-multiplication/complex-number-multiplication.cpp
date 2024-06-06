class Solution {
public:
    bool isnum(char c) {
        return c >= '0' && c <= '9';
    }

    string complexNumberMultiply(string num1, string num2) {
        vector<int> v;
        bool negative = false;
        int currentNumber = 0;

        auto processChar = [&](char s) {
            if (s == '-') {
                negative = true;
            } else if (isnum(s)) {
                currentNumber = currentNumber * 10 + (s - '0');
            } else if (s == '+' || s == 'i') {
                if (negative) {
                    currentNumber = -currentNumber;
                    negative = false;
                }
                v.push_back(currentNumber);
                currentNumber = 0;
            }
        };

        for (size_t i = 0; i < num1.size(); ++i) {
            processChar(num1[i]);
        }

        for (size_t i = 0; i < num2.size(); ++i) {
            processChar(num2[i]);
        }

        int a = v[0], b = v[1], c = v[2], d = v[3];
        int real = a * c - b * d;
        int imaginary = a * d + b * c;

        return to_string(real) + "+" + to_string(imaginary) + "i";
    }
};
