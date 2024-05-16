// 224. Basic Calculator
class Solution {
public:
    int calculate(string s) {
        stack<int> values;
        stack<int> signs;
        int result = 0;
        int currentNumber = 0;
        int sign = 1;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
            } else if (c == '+' || c == '-') {
                result += sign * currentNumber;
                currentNumber = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                values.push(result);
                signs.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * currentNumber;
                currentNumber = 0;
                result *= signs.top();
                signs.pop();
                result += values.top();
                values.pop();
            }
        }
        result += sign * currentNumber;
        return result;
    }

};
