#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
int main()
{
    int numTestCases;
    string sentence;
    string word = "red";
    string word2 = "blue";
    vector<string> results;

    if (!(cin >> numTestCases))
        return 0;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < numTestCases; i++)
    {
        if (getline(cin, sentence))
        {

            results.push_back(sentence);
        }
    }

    // Output exactly what was stored
    for (const string &line : results)
    {
        cout << line << endl;
    }

    return 0;
}
