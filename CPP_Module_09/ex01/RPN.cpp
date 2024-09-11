#include "RPN.hpp"

double RPN::Calculate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string expressionToken;
    std::stack<double> stack;

    while (iss >> expressionToken)
    {
        EvaluateExpressionToken(stack, expressionToken);
    }

    if (stack.size() != 1)
    {
        throw std::runtime_error("Invalid RPN expression");
    }

    double result = stack.top();

    return (result);
}

void RPN::EvaluateExpressionToken(std::stack<double>& stack, const std::string& expressionToken)
{
    if (IsOperand(expressionToken))
    {
        PushOperand(stack, expressionToken);
    }
    else if (IsOperator(expressionToken))
    {
        PerformOperation(stack, expressionToken[0]);
    }
    else
    {
        throw std::runtime_error("Invalid expressionToken");
    }
}

bool RPN::IsOperand(const std::string& expressionToken)
{
    if (expressionToken.length() != 1)
    {
        return (false);
    }

    char operand = expressionToken[0];

    if (std::isdigit(operand) == false)
    {
        return (false);
    }

    return (true);
}

void RPN::PushOperand(std::stack<double>& stack, const std::string expressionToken)
{
    std::istringstream iss(expressionToken);
    double value;

    iss >> value;
    stack.push(value);
}

bool RPN::IsOperator(const std::string& expressionToken)
{
    if (expressionToken == "+" ||
        expressionToken == "-" ||
        expressionToken == "*" ||
        expressionToken == "/")
    {
        return (true);
    }

    return (false);
}

void RPN::PerformOperation(std::stack<double>& stack, const char op)
{
    if (stack.size() < 2)
    {
        throw std::runtime_error("Insufficient operands");
    }

    double RightValue = PopOperand(stack);
    double leftValue = PopOperand(stack);

    switch (op)
    {
        case '+':
            stack.push(leftValue + RightValue);
            break;
        case '-':
            stack.push(leftValue - RightValue);
            break;
        case '*':
            stack.push(leftValue * RightValue);
            break;
        case '/':
            if (RightValue == 0)
            {
                throw std::runtime_error("Division by zero");
            }
            stack.push(leftValue / RightValue);
            break;
        default:
            throw std::runtime_error("Unknown operator: ");
    }
}

double RPN::PopOperand(std::stack<double>& stack)
{
    double operand = stack.top();
    stack.pop();

    return (operand);
}