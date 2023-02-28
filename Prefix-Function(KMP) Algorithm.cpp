//for more information go to -> https://cp-algorithms.com/string/prefix-function.html

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

// algorithm used for patterm matching
// ans stores indices where pattern is found
// s is main string, p is string we have to find in s
void kmp(vector<int> lps, string s, string p, vector<int> &ans) {
    int psz = p.size(), sz = s.size();
    int j = 0;
    for(int i = 0; i < sz; i++) {
        while(j >= 0 && p[j] != s[i])
            if(j >= 1) j = lps[j - 1];
            else j = -1;
        j++;
        if(j == psz) {
            j = lps[j - 1];
            // pattern found in string s at position i-psz+1
            ans.push_back(i - psz + 1);
        }
        // after each loop we have j=longest common suffix of s[0..i] which is also prefix of p
    }
}
int main() {
    string s = "ab";
    string p = "abcdabcy";
    vector<int> lps = prefix_function(s);
    vector<int> ans;
    kmp(lps, p, s, ans);
}