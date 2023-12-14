#include <iostream>
#include <stack>
#include <cctype>
#include <queue>

using namespace std;

bool isPalindromeStack(const string& input) {
    stack<char> s;
    for (char c : input) {
        s.push(c);
    }
    for (char c : input) {
        if (c != s.top()) {
            return false;
        }
        s.pop();
    }
    return true;
}

bool isPalindromeStackQueue(const string& input) {
    stack<char> s;
    queue<char> q;
    for (char c : input) {
        s.push(c);
        q.push(c);
    }
    for (char c : input) {
        if (c != s.top() || c != q.front()) {
            return false;
        }
        s.pop();
        q.pop();
    }
    return true;
}

int main () {
    cout << boolalpha ;
    cout << "test isPalindromeStack" << endl ;
    cout << "Is 'racecar' a palindrome ? "
    << isPalindromeStack("racecar") << endl ;
    cout << " Is 'hello' a palindrome ? "
    << isPalindromeStack("hello" ) << endl ;

    cout << "test isPalindromeStackQueue" << endl ;
    cout << "Is 'racecar' a palindrome ? "
    << isPalindromeStackQueue("racecar") << endl ;
    cout << " Is 'hello' a palindrome ? "
    << isPalindromeStackQueue("hello" ) << endl ;

    return 0 ;
}
