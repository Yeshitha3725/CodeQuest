#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main()
{

    int numSentences;

    cin >> numSentences;
    cin.ignore();

    vector<int> results;

    for (int i = 0; i < numSentences; ++i)
    {
        string sentence;
        int currentCount = 0;

        getline(cin, sentence);

        for (char c : sentence)
        {
            char lowerC = tolower(c);

            if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' ||
                lowerC == 'o' || lowerC == 'u')
            {
                currentCount++;
            }
        }

        results.push_back(currentCount);
    }

    for (int count : results)
    {
        cout << "\n"
             << count;
    }

    return 0;
}