


string postfixToPrefix(string s)
{
    stack<string> stk;

    // Length of expression
    int length = s.size();
    for (int i = 0; i < length; i++)
    {
        // Check if symbol is operator
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            // Pop two operands from stack
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();

            string temp = s[i] + op2 + op1;

            // Push string temp back to stack
            stk.push(temp);
        }
        else
        {
            // Push the operand to the stack
            string add = "";
            add += s[i];
            stk.push(add);
        }
    }
    
    // Concatenate all strings in stack and return the answer
    string ans = "";

    while(stk.size() != 0)
    {
        ans += stk.top();
        stk.pop();
    }

    return ans;
}
