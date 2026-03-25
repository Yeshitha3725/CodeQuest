#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    int numTestCases;
    int speed;
    bool isBirthday;

    if (!(cin >> numTestCases))
        return 0;

    vector<string> results;

    for (int i = 0; i < numTestCases; i++)
    {

        // Read the data
        cin >> speed >> boolalpha >> isBirthday;

        // Determine the result and save it to our vector
        int adjustment = isBirthday ? 5 : 0;

        if (speed <= 60 + adjustment)
        {
            results.push_back("no ticket");
        }
        else if (speed <= 80 + adjustment)
        {
            results.push_back("small ticket");
        }
        else
        {
            results.push_back("big ticket");
        }
    }

    for (const string &ticket : results)
    {
        cout << ticket << endl;
    }

    return 0;
}