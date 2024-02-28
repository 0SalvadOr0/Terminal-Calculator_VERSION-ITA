#include "../include/expression.hpp"
using namespace std;

float calculateExpression(const string& expression) {
    stack<float> numbers;
    stack<char> operators;
    stack<char> parentheses;

    auto precedence = [](char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    };

    auto applyOperator = [](float num1, float num2, char op) {
        switch (op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                if (num2 != 0.0) {
                    return num1 / num2;
                } else {
                    throw runtime_error("Division by zero");
                }
            default:
                throw runtime_error("Invalid operator");
        }
    };

    auto isFunction = [](const string& func) {
        return (func == "sin" || func == "cos");
    };

    auto applyFunction = [](float num, const string& func) {
        if (func == "sin") {
            return sin(num);
        } else if (func == "cos") {
            return cos(num);
        }

        throw runtime_error("Unsupported function");
    };

    for (size_t i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            float num = 0.0;
            while (i < expression.length() && (isdigit(expression[i]) || expression[i] == '.')) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;

            numbers.push(num);
        } else if (isalpha(expression[i])) {
            string function;
            while (i < expression.length() && isalpha(expression[i])) {
                function += expression[i];
                i++;
            }
            i--;

            if (isFunction(function)) {
                if (expression[i + 1] != '(') {
                    throw runtime_error("Missing parenthesis after the function");
                }

                size_t start = i + 2;
                size_t end = start;
                int parenthesisCount = 1;

                while (end < expression.length() && parenthesisCount > 0) {
                    if (expression[end] == '(') {
                        parenthesisCount++;
                    } else if (expression[end] == ')') {
                        parenthesisCount--;
                    }
                    end++;
                }

                if (parenthesisCount > 0) {
                    throw runtime_error("Missing parenthesis after the function");
                }

                string argument = expression.substr(start, end - start - 1);
                float num = calculateExpression(argument);

                numbers.push(applyFunction(num, function));

                i = end - 1;
            } else {
                throw runtime_error("Unsupported function");
            }
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                float num2 = numbers.top();
                numbers.pop();
                float num1 = numbers.top();
                numbers.pop();

                char op = operators.top();
                operators.pop();

                float result = applyOperator(num1, num2, op);
                numbers.push(result);
            }
            operators.push(expression[i]);
        } else if (expression[i] == '(') {
            parentheses.push(expression[i]);
        } else if (expression[i] == ')') {
            while (!parentheses.empty() && parentheses.top() != '(') {
                char op = operators.top();
                operators.pop();

                float num2 = numbers.top();
                numbers.pop();
                float num1 = numbers.top();
                numbers.pop();

                float result = applyOperator(num1, num2, op);
                numbers.push(result);
            }

            if (!parentheses.empty()) {
                parentheses.pop();
            } else {
                throw runtime_error("Unbalanced parentheses");
            }
        }
    }

    while (!operators.empty()) {
        float num2 = numbers.top();
        numbers.pop();
        float num1 = numbers.top();
        numbers.pop();

        char op = operators.top();
        operators.pop();

        float result = applyOperator(num1, num2, op);
        numbers.push(result);
    }

    return numbers.top();
}
