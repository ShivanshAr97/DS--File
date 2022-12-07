#include <iostream>
#include <stack>

using namespace std;
int main()
{
    
    string str;
    cin>>str;

    stack <char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ans= str[i];
        st.push(ans);
    }

    string ans = "";

    while (!st.empty())
    {
        char an = st.top();
        ans.push_back(an);
        st.pop();
    }

    cout<<ans;
    return 0;
}