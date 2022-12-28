class Solution {
public:
    bool isValid(string s) {
        stack <char> stack1st, stack2nd, stack3rd;
        if(s.size() == 0) return true;
      //  cout << stack.empty();
        for(int i=0;i< s.size();i++)
        {
            if(s[i] == '(') stack1st.push('(');
            else if(s[i] == '{') stack2nd.push('{');
            else if(s[i] == '[') stack3rd.push('[');

            else if(s[i] == ')' && stack1st.size() >= 1 ) 
            {
                stack1st.pop();
            }
             else   if(s[i] == '}' && stack2nd.size() >= 1) 
            {
                stack2nd.pop();
            }

             else  if(s[i] == ']' && stack3rd.size() >= 1) 
            {
                stack3rd.pop();
            }
             else  return false;
        }
        cout << stack1st.size() << stack2nd.size() << stack3rd.size();

        if(stack1st.empty() && stack2nd.empty() &&  stack3rd.empty()) return true;
        return false;
    }
};