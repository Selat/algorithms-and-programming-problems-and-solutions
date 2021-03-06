#include <iostream>
#include <stack>

using namespace std;

/*
 * 6.1.1. Check the correctness of a given sequence that consists of
 * the following characters {'(', ')', '[', ']'}.
 */

int main()
{
	string str;
	cin >> str;
	stack <char> s;
	for(int i = 0; i < str.length(); ++i) {
		if(!s.empty() &&
		   (((s.top() == '[') && (str[i] == ']')) ||
		    ((s.top() == '(') && (str[i] == ')')))) {
			s.pop();
		} else {
			s.push(str[i]);
		}
	}
	if(s.empty()) {
		cout << "CORRECT" << endl;
	} else {
		cout << "INCORRECT" << endl;
	}
	return 0;
}
