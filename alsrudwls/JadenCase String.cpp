#include <string>
#include <sstream>
#include <cctype>

using namespace std;

string solution(string s) {
    bool bStart_JadenCase = true;

    for (char& c : s)
    {
        if (c == ' ')
        {
            bStart_JadenCase = true;
        }
        else if (bStart_JadenCase)
        {
            c = toupper(c);
            bStart_JadenCase = false;
        }
        else
        {
            c = tolower(c);
        }

    }

    string answer = s;

    return answer;
}