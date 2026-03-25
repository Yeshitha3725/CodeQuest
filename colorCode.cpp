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

            if (sentence.find(word) != string::npos || sentence.find(word2) != string::npos)
            {
                if (sentence.find(word) != string::npos)
                {
                    results.push_back("red");
                }
                else if (sentence.find(word2) != string::npos)

                    results.push_back("blue");
            }
            else
            {

                results.push_back("no color found");
            }
        }
    }

    for (const string &res : results)
    {
        cout << res << endl;
    }

    return 0;
}
