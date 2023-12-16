#include <iostream>
#include <stack>

bool isWellParenthesized(const std::string &expression)
{
    std::stack<char> s;
    for (char c : expression)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (s.empty())
            {
                return false; // unmatched closing bracket
            }
            char opening = s.top();
            s.pop();
            if ((c == ')' && opening != '(') ||
                (c == '}' && opening != '{') ||
                (c == ']' && opening != '['))
            {
                return false; // mismatched brackets
            }
        }
        else
        {
            // ignore other characters not considered brackets
        }
    }
    return s.empty(); // all brackets were matched and closed
}

int main()
{
    std::string expression1 = "((a + b) * (c - d))";
    std::string expression2 = "(a + b] * (c - d)";

    if (isWellParenthesized(expression1))
    {
        std::cout << expression1 << " is well-parenthesized." << std::endl;
    }
    else
    {
        std::cout << expression1 << " is not well-parenthesized." << std::endl;
    }

    if (isWellParenthesized(expression2))
    {
        std::cout << expression2 << " is well-parenthesized." << std::endl;
    }
    else
    {
        std::cout << expression2 << " is not well-parenthesized." << std::endl;
    }

    return 0;
}
