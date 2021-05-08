/*
	author: dtsdwarak
*/

# include <bits/stdc++.h>

#define pval(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using namespace std;

typedef long long ll;

bool isDigit(string s) {
    for(auto i: s) {
        if (!isdigit(i))
            return false;
    }
    return true;
}

bool isOperator(string s) {
    if (s == "+" || s =="-" || s =="*" || s=="/" || s=="^")
        return true;
    return false;
}

string evaluate(string a, string b, string op) {
    
    int a_i = stoi(a);
    int b_i = stoi(b);
    
    switch(op[0]) {
            case '+': return to_string(a_i + b_i); break;
            case '-': return to_string(a_i - b_i); break;
            case '*': return to_string(a_i * b_i); break;
            case '/': return to_string(a_i / b_i); break;
            case '^': return to_string(pow(a_i,b_i)); break;
            default: cout<<"Invalid operator"; exit(1);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<string> cstack;
    
    vector<string> exp = {"-","+","*","2","3","*","5","4","9"};
    
    for(int i=exp.size()-1;i>-1;i--) {
            
            if (isDigit(exp[i])) {
                cstack.push(exp[i]);
            } else if(isOperator(exp[i])) {
                string a = cstack.top(); cstack.pop();
                string b = cstack.top(); cstack.pop();
                cstack.push(evaluate(a, b, exp[i]));
            }
    }
    
    cout<<"Value ="<< cstack.top();
    
}
