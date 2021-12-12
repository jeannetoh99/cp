#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline( cin , s );
    printf("Thank you, %s, and farewell!\n", s.c_str());

    return 0;
}