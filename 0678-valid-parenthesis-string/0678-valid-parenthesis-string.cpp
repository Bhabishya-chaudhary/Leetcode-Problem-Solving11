class Solution
{
public:
    // Apprach two
    bool checkValidString(string s)
    {
        int n = s.size();

        vector<vector<bool>> t(n + 1, vector<bool>(n + 1, false));
        // State Definition :
        // t[i][j] = if the string from index i to n-1 is valid or not having j open brackets
        t[n][0] = true;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int open = 0; open <= n; open++)
            {
                bool isvalid = false;
                // for star
                if (s[i] == '*')
                {
                    isvalid |= t[i + 1][open + 1]; // Treating as open..
                    isvalid |= t[i + 1][open];     // Treating as empty..

                    if (open > 0)
                    {
                        isvalid |= t[i + 1][open - 1]; // Treating as close..
                    }
                }

                else if (s[i] == '(')
                {
                    isvalid |= t[i + 1][open + 1]; // Treating as open..
                }
                else if (open > 0)
                {
                    isvalid |= t[i + 1][open - 1]; // Treating as close..
                }
            t[i][open] = isvalid;
        }
    }
    return t[0][0];
}
};