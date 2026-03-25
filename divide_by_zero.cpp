#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// Helper function to check if a string is a valid number completely
bool isValidNumber(string s, double &value)
{
    stringstream ss(s);
    // Try to read a double, then check if anything is left over in the string
    if (!(ss >> value))
        return false;
    char remaining;
    if (ss >> remaining)
        return false; // If there's more data, it's not a clean number
    return true;
}

int main()
{
    int testcases;
    if (!(cin >> testcases))
        return 0;

    vector<string> results;

    for (int i = 0; i < testcases; i++)
    {
        string s1, s2;
        // The problem guarantees exactly two values per test case [cite: 31]
        if (!(cin >> s1 >> s2))
            break;

        double num1, num2;

        // Requirement: Check Dividend first [cite: 22, 23]
        if (!isValidNumber(s1, num1))
        {
            results.push_back("Invalid Dividend");
        }
        // Requirement: Check if Divisor is a number second [cite: 22, 23]
        else if (!isValidNumber(s2, num2))
        {
            results.push_back("Invalid Divisor");
        }
        // Requirement: Check if Divisor is zero third [cite: 22, 23]
        else if (num2 == 0)
        {
            results.push_back("Divide By Zero");
        }
        // All checks passed: Calculate and round to one decimal place
        else
        {
            stringstream ss;
            ss << fixed << setprecision(1) << (num1 / num2);
            results.push_back(ss.str());
        }
    }

    // Print all results at the end [cite: 37, 40-43]
    for (size_t i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }

    return 0;
}//