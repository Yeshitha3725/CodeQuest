#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <sstream>

using namespace std;

// MM.DD.YYYY HH:MM:SS format
time_t parse_timestamp(string ts)
{
    struct tm t = {0};

    // Remove leading/trailing whitespace to prevent stream errors
    size_t first = ts.find_first_not_of(" ");
    size_t last = ts.find_last_not_of(" ");
    if (first == string::npos)
        return 0;
    ts = ts.substr(first, (last - first + 1));

    // Replace dots with spaces for easy extraction
    for (char &c : ts)
        if (c == '.')
            c = ' ';
    // Replace colons with spaces to ensure HH:MM:SS parses correctly
    for (char &c : ts)
        if (c == ':')
            c = ' ';

    stringstream ss(ts);
    int month, day, year;
    // Extracting all components as individual integers
    if (!(ss >> month >> day >> year >> t.tm_hour >> t.tm_min >> t.tm_sec))
    {
        return 0;
    }

    t.tm_year = year - 1900; // Years since 1900
    t.tm_mon = month - 1;    // 0-indexed months
    t.tm_mday = day;
    t.tm_isdst = -1; // Ignore daylight savings

    return mktime(&t);
}

// Formats output with leading zeros and correct pluralization
string format_unit(long long val, string unit)
{
    stringstream ss;
    // Minimum of two digits with leading zeroes
    ss << setfill('0') << setw(2) << val << " " << unit;
    // Proper pluralization: Only singular if val is exactly 1
    if (val != 1)
        ss << "s";
    return ss.str();
}

int main()
{
    int testCases;
    if (!(cin >> testCases))
        return 0; // Read number of test cases

    string dummy;
    getline(cin, dummy); // Consume the newline after the integer

    vector<string> results;

    for (int i = 0; i < testCases; ++i)
    {
        string line;
        if (!getline(cin, line))
            break;

        // Split exactly at the pipe character
        size_t pipePos = line.find('|');
        if (pipePos == string::npos)
            continue;

        string currentTs = line.substr(0, pipePos);
        string eventTs = line.substr(pipePos + 1);

        time_t start = parse_timestamp(currentTs);
        time_t end = parse_timestamp(eventTs);

        // Calculate difference in seconds
        long long diff = (long long)difftime(end, start);

        // Break down into units
        long long days = diff / (24 * 3600);
        diff %= (24 * 3600);
        long long hours = diff / 3600;
        diff %= 3600;
        long long mins = diff / 60;
        long long secs = diff % 60;

        // Build the result string
        stringstream resultLine;
        resultLine << format_unit(days, "Day") << " "
                   << format_unit(hours, "Hour") << " "
                   << format_unit(mins, "Minute") << " "
                   << format_unit(secs, "Second");

        results.push_back(resultLine.str());
    }

    // Output all final results at once
    for (const string &res : results)
    {
        cout << res << endl;
    }

    return 0;
}