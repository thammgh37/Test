#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>
#include <stack>
using namespace std;

int f[255];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int Q;
    cin >> Q;
    f[(int) '('] = -1;
    f[(int) ')'] = -2;
    f[(int) 'H'] = 1 ;
    f[(int) 'C'] = 12 ;
    f[(int) 'O']  = 16;
    while (Q--){
        string s;
        cin >> s;
        stack<long long> st;
        for (int i=0;i < s.length();i++){
            if (f[s[i]]==0){
                long long tmp = st.top();
                st.pop();
                st.push(tmp*(s[i]-'0'));
            }
            else if (f[s[i]]==1 || f[s[i]]==12 ||f[s[i]]==16 ) st.push(f[s[i]]);
            else if (f[s[i]]==-1) st.push(-1);
            else {
                long long tmp2 = 0;
                while (st.top()!=-1){
                    tmp2 += st.top();
                    st.pop();
                }
                st.pop();
                st.push(tmp2);
            }
        }
        long long ans=0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        cout << ans <<'\n';
    }
    return 0;
}