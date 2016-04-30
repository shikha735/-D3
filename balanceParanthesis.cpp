#include <iostream>
#include <stack>
using namespace std;

bool arePair(char opening, char closing){
    if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}

bool areParanthesisBalanced(string expr){
    stack<char> S;
    for(int i=0;i<expr.length();i++)
	{
		if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[')
			S.push(expr[i]);
        else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']'){
            if(S.empty() || !arePair(S.top(),expr[i])){
                return false;
            }
            else
                S.pop();
        }
    }
    return S.empty()? true:false;
}

int main(){
    string expression;
    cout << "Enter the expression: ";
    cin >> expression;
    if(areParanthesisBalanced(expression))
        cout << "Balanced";
    else
        cout << "Not balanced";
    return 0;
}
