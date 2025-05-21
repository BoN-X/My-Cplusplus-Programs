#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int calculate(int a, int b, char op) {
    switch(op) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' : return a / b;
        default: return 0;
    }
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int evalExpression(const string& expr) {
    stack<int> nums;
    stack<char> ops;

    for (int i = 0; i < expr.size(); i++) {
        if (isspace(expr[i])) continue;
        if (isdigit(expr[i])) {
            int num = 0;
            while (i < expr.size() && isdigit(expr[i])) {
                num = num * 10 + (expr[i++] - '0');
            }
            nums.push(num);
            i--;
        }
        else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                int b = nums.top(); nums.pop();
                int a = nums.top(); nums.pop();
                nums.push(calculate(a, b, ops.top()));
                ops.pop();
            }
            ops.push(expr[i]);
        }
    }
    while (!ops.empty()) {
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        nums.push(calculate(a, b, ops.top()));
        ops.pop();
    }
    return nums.top();
}

int main() {
    string expr;
    cout << "Enter expression (e.g). 3+5*2\n";
    getline(cin, expr);
    cout << "Result: " << evalExpression(expr) << endl;
    system("pause");
    return 0;
}