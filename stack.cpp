#include <iostream>
#include <stack>

using namespace std;
int main()
{
    stack <int> s;
    s.push(1);    
    s.push(2);    
    s.push(5);    
    s.push(4);    
    cout<<s.top();
    s.pop();
    cout<<s.top();
    cout<<s.empty();
    return 0;
}