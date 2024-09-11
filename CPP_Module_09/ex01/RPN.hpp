#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
    public:
        static double Calculate(const std::string& expression);
        static void EvaluateExpressionToken(std::stack<double>& stack, const std::string& expressionToken);
        static bool IsOperand(const std::string& expressionToken);
        static void PushOperand(std::stack<double>& stack, const std::string expressionToken);
        static bool IsOperator(const std::string& expressionToken);
        static void PerformOperation(std::stack<double>& stack, const char op);
        static double PopOperand(std::stack<double>& stack);

    private:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();

};

#endif