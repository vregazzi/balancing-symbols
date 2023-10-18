#include <iostream>
#include <stdexcept>

#include "Stack.h"
using namespace std;

void balanceSymbols(string phrase)
{
    array<char, 8> groupingSymbols = {'(', ')', '[', ']', '<', '>', '{', '}'};
    Stack<char> stack;
    cout << "----------" << endl;
    cout << "Checking phrase: " << phrase << endl;

    // iterate through phrase
    for (int i = 0; i < phrase.length(); i++)
    {
        // iterate through symbols to check if character is a grouping symbol
        for (int j = 0; j < groupingSymbols.size(); j++)
        {
            if (phrase[i] == groupingSymbols[j])
            {
                // even index means it's an opening symbol, so push it to the stack
                if (j % 2 == 0)
                {
                    stack.push(phrase[i]);
                }
                // odd index means it's a closing symbol, so check if it matches the top of the stack
                else
                {
                    try
                    {
                        // if the top of the stack matches the closing symbol, pop it and continue
                        if (stack.top() == groupingSymbols[j - 1])
                        {
                            stack.pop();
                            continue;
                        }
                        // if the top of the stack does not match the closing symbol, show the mismatch and return
                        else
                        {
                            cout << "unmatched characters " << stack.top() << " and " << phrase[i] << endl;
                            cout << "Phrase is NOT balanced." << endl;
                            return;
                        }
                    }
                    // if the stack is empty, then there is no opening symbol to match the closing symbol
                    catch (std::out_of_range)
                    {
                        cout << "unmatched ending characer " << phrase[i] << endl;
                        cout << "Phrase is NOT balanced." << endl;
                        return;
                    }
                }
            }
        }
    }
    // if the stack is not empty, then there is an opening symbol without a closing symbol
    if (stack.size() > 0)
    {
        cout << "unmatched beginning characer " << stack.top() << endl;
        cout << "Phrase is NOT balanced." << endl;
        return;
    }

    // otherwise, the phrase is balanced
    cout << "Phrase is balanced." << endl;
    return;
}

int main()
{
    balanceSymbols("(hello)world");
    balanceSymbols("(hello[there])");
    balanceSymbols("(hello<there])");
    balanceSymbols("(hello[there<my>{friend}]))");
    balanceSymbols("[(hello[there<my>{friend}])");
    balanceSymbols("hello<there(<my<friend>>)>");
    balanceSymbols("hello<there(<my<friend>>)>}");
    balanceSymbols("[[hello<there(<my<friend>)>]]");
}
