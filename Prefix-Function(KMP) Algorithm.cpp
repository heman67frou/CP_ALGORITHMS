#include <iostream>
#include <vector>
using namespace std;

// returns the longest proper prefix array of pattern p
// where lps[i]=longest proper prefix which is also suffix of p[0...i]
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    return pi;
}
int main() {
    string s = "abcdabcy";
    vector<int> lps = prefix_function(s);
}