#include <iostream>
#include <stack>
using namespace std;

int main() {
   string s;
   cin >> s;

   stack<char> st;
   int res = 0;
   int tmp = 1;

   for (int i = 0; i < s.length(); i++) {
      if (s[i] == '(') {
         tmp *= 2;
         st.push('(');
      }
      else if (s[i] == '[') {
         tmp *= 3;
         st.push('[');
      }
      else if (s[i] == ')') {
         if (st.empty() || st.top() != '(') {
            res = 0;
            break;
         }

         if (s[i - 1] == '(') res += tmp;

         tmp /= 2;
         st.pop();
      }
      else if (s[i] == ']') {
         if (st.empty() || st.top() != '[') {
            res = 0;
            break;
         }

         if (s[i - 1] == '[') res += tmp;
         
         tmp /= 3;
         st.pop();
      }
   }

   if (!st.empty()) res = 0;

   cout << res << "\n";

   return 0;
}