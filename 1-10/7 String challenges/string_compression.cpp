#include <iostream>
#include <string>
using namespace std;

string compress(string s)
{
    string ans;
    int l = s.length();
    for(int i = 0;i<l;i++){
        int count =1;
        while(i<l-1 and s[i]==s[i+1]){
            count++;
            i++;
        }
        ans=ans.append(s[i]+to_string(count));
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    cout << compress(s);
    return 0;
}