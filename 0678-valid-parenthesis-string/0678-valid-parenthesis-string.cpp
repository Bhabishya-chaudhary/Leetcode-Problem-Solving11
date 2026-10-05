class Solution {
public:
  // Apprach one using Recursion and memo
   int t [105][105];
   bool solve(int idx, int open, string &s, int n) { 

    if(idx == n) {
     return  open == 0;
    }

    if(t[idx][open] != -1) {
      return t[idx][open] == 1 ? true : false;
    } 

    bool isvalid = false;
     //case one star
     if(s[idx] == '*') {  //* = ---> //open --> empty --> close

          isvalid |=  solve(idx + 1, open + 1, s, n);  //open case 
          isvalid |=  solve(idx + 1, open , s, n);     //empty case

         if(open > 0) {
           isvalid |= solve(idx + 1, open - 1, s, n); //close case
          }
      }
      //case two open
      else if (s[idx] == '(') {
        isvalid |= solve(idx + 1, open + 1, s, n); //open 
      }
      
      //case two close 
      else if(open > 0) {
       isvalid |= solve(idx + 1, open - 1, s, n); //close
      }
    return t[idx][open] = isvalid;
  }

    bool checkValidString(string s) {

      int  n = s.size();
      memset(t, -1, sizeof(t));
      return solve(0, 0, s, n);

        
    }
};