class Solution {
public:
    int calculate(string s) {
        stack<long long> st;

        long long result = 0;
        long long num = 0;
        long long sign = 1;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if (ch == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }

            else if (ch == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }

            else if (ch == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (ch == ')') {
                result += sign * num;
                num = 0;

                long long prevSign = st.top();
                st.pop();

                long long prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result;
            }
        }

        result += sign * num;

        return result;
    }
};