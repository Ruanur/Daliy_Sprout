#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

int ToSecond(const string& time)
{
    int m, s;
    char colon;
    istringstream iss(time);
    iss >> m >> colon >> s;
    return m * 60 + s;
}

string ToStringTime(int time)
{
    int m = time / 60;
    int s = time % 60;
    ostringstream oss;
    oss << setw(2) << setfill('0') << m << ":" << setw(2) << setfill('0') << s;
    return oss.str();
}

void skipOpening(int& pos, int op_start, int op_end)
{
    if (op_start <= pos && pos <= op_end)
    {
        pos = op_end;
    }
}

void prev(int& pos, int op_start, int op_end)
{
    skipOpening(pos, op_start, op_end);

    pos = max(0, pos - 10);

    skipOpening(pos, op_start, op_end);
}

void next(int& pos, int op_start, int op_end, int video_len)
{
    skipOpening(pos, op_start, op_end);

    pos += 10;
    if (pos > video_len)
    {
        pos = video_len;
    }

    skipOpening(pos, op_start, op_end);
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    int video_len_sec = ToSecond(video_len);
    int pos_sec = ToSecond(pos);
    int op_start_sec = ToSecond(op_start);
    int op_end_sec = ToSecond(op_end);

    for (const string& cmd : commands)
    {
        if (cmd == "prev")
        {
            prev(pos_sec, op_start_sec, op_end_sec);
        }

        else if (cmd == "next")
        {
            next(pos_sec, op_start_sec, op_end_sec, video_len_sec);
        }
    }

    return ToStringTime(pos_sec);
}
