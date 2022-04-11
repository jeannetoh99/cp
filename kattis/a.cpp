#include <bits/stdc++.h>

using namespace std;

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}
 
std::string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

bool solve(string s) {
  return regex_match(s, regex("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)"));
}

int main() {
  string s;
  while (getline(cin, s) && s != "*") {
    s = trim(s);
    cout << s << " is " << (solve(s) ? "legal.\n" : "illegal.\n");
  }
}