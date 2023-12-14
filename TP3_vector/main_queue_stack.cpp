#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(const string& input) {
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

int main () {
    cout << boolalpha ;
    cout << "test isPalindrome" << endl ;
    cout << "Is 'racecar' a palindrome ? "
    << isPalindrome("racecar") << endl ;
    cout << " Is 'hello' a palindrome ? "
    << isPalindrome("hello" ) << endl ;
    return 0 ;
}
