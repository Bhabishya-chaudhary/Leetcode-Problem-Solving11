class Solution {
public:
    bool backspaceCompare(string s, string t) {
      
        string a = "";
        string b = "";

        // Process s
        for(char ch : s) {
            if(ch == '#') {
                if(!a.empty())
                    a.pop_back();
            }
            else {
                a.push_back(ch);
            }
        }
       //process t
       for(char ch : t) {
            if(ch == '#') {
                if(!b.empty())
                    b.pop_back();
            }
            else {
                b.push_back(ch);
            }
        } 
        return a==b;
   }
};