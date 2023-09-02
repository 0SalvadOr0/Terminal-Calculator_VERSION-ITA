#include "..\include\expression.hpp"

using namespace std;

int calculateExpression(const string& expression) {
    stack<int> numbers;
    stack<char> operators;

    // Funzione locale per determinare la precedenza dell'operatore
    auto precedence = [](char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0; // Operatore sconosciuto o parentesi
    };

    // Funzione locale per applicare l'operatore
    auto applyOperator = [](int num1, int num2, char op) {
        switch (op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                if (num2 != 0) {
                    return num1 / num2;
                } else {
                    cerr << "Errore: Divisione per zero" << endl;
                    exit(1);
                }
            default:
                cerr << "Errore: Operatore non valido" << endl;
                exit(1);
        }
    };

    for (size_t i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            int num = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--;

            numbers.push(num);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                int num2 = numbers.top();
                numbers.pop();
                int num1 = numbers.top();
                numbers.pop();

                char op = operators.top();
                operators.pop();

                int result = applyOperator(num1, num2, op);
                numbers.push(result);
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        int num2 = numbers.top();
        numbers.pop();
        int num1 = numbers.top();
        numbers.pop();

        char op = operators.top();
        operators.pop();

        int result = applyOperator(num1, num2, op);
        numbers.push(result);
    }

    return numbers.top();
}
