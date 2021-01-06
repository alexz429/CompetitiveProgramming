/*
Use stack to keep track of open brackets
if closing bracket matches first open bracket in stack, remove them both.
If open bracket, add it into stack.
Finally, check if extra open brackets exist at the end, if they do it is invalid.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                bracket.push(s[i]);
            }
            else if(bracket.empty()){
                return false;
            }
            else if(s[i]==')'){
                if(bracket.top()=='('){
                    bracket.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]==']'){
                if(bracket.top()=='['){
                    bracket.pop();
                }
                else{
                    return false;
                }
            }
            else if(s[i]=='}'){
                if(bracket.top()=='{'){
                    bracket.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(bracket.empty())return true;
        return false;
    }
};