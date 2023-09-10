#include "..\include\expression.hpp"

using namespace std;

float calculateExpression(const string& expression) {
    stack<float> numbers;
    stack<char> operators;
    stack<char> parentheses;  // Stack per gestire le parentesi

    auto precedence = [](char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    };

   // Dentro la funzione applyOperator, cambia il risultato da int a float
    auto applyOperator = [](float num1, float num2, char op) {
        switch (op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                if (num2 != 0.0) { // Cambia da 0 a 0.0 per la divisione in virgola mobile
                    return num1 / num2;
                } else {
                    cerr << ANSI_COLOR_RED << "Errore: Divisione per zero" << ANSI_COLOR_RESET << endl;
                    exit(1);
                }
            default:
                cerr << ANSI_COLOR_RED << "Errore: Operatore non valido" << ANSI_COLOR_RESET << endl;
                exit(1);
        }
    }; 

    for (size_t i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            float num = 0.0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;

            numbers.push(num);
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
                parentheses.pop();  // Rimuovi la parentesi aperta corrispondente
            } else {
                cerr << ANSI_COLOR_RED << "Errore: Parentesi non bilanciate" << ANSI_COLOR_RESET << endl;
                exit(1);
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
