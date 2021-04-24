#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
//          Use a stack to process parenthesized expressions. 
//          When you see an open parenthesis, note that it was seen. 
//          When you see a close parenthesis after an open parenthesis, 
//          pop elements down to and including the open parenthesis off the stack. 
//          push a value onto the stack to indicate that a parenthesized expression was replaced. 


int main()
{
	string expr("this is a (paranthesized expression)");
	stack<char> stk;
	string replacement("the string has been replaced");
	bool seen=0;
	for(const auto &i : expr)
	{
		if(i=='(')
		{
			seen=1;
			continue;
		}
		else if(i==')')
			seen = 0;
	if(seen)
		stk.push(i);
	}
	string r;
	while(!stk.empty())
	{
		r+=stk.top();
		stk.pop();
	}
	expr.replace(expr.find("(") +1, r.size(), replacement);
	cout<<expr;
}
