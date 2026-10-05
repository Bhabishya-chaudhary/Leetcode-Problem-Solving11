class Solution {
public:
    int scoreOfParentheses(string s) {
      int n = s.size();
      int open = 0; 
      int result = 0;
      for( int i = 0; i <= n; i++) {
        if(s[i] == '(') { open++; }
        else { open--; 
         if(s[i-1] == '(') {
          result += 1 << open;
        } 
        }
      }
      return result;
    }
};