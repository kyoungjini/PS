#include <iostream>
#include <stack>
using namespace std;

double calc (char op, double x, double y) {
    if (op == '+') return x + y;
    else if (op == '-') return x - y;
    else if (op == '*') return x * y;
    else if (op == '/') return x / y;

    return 0;
}

int main() {
    int n;
    cin >> n;

    string postfix_str;
    cin >> postfix_str;

    double alphabet_val[27] = {0, };
    for (int i = 0; i < n; i++) cin >> alphabet_val[i];

    stack<double> s;
    double first_num, second_num, res;

    for (auto iter: postfix_str) {
        if (iter >= 'A' && iter <= 'Z') {
            int idx = iter - 'A';
            s.push(alphabet_val[idx]);
        } else {
            second_num = s.top();
            s.pop();
            first_num = s.top();
            s.pop();

            res = calc(iter, first_num, second_num);
            s.push(res);
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << res << "\n";

    return 0;
}