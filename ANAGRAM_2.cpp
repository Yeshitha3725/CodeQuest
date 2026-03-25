#include <iostream>
#include <string>
#include <sstream>
#include <algorithm> // Required for std::sort

using namespace std;

int main()
{
    int numTestCases;
    string word1, word2;

    if (!(cin >> numTestCases))
        return 0;
    cin.ignore();

    // Read all inputs into an array
    string *fullInput = new string[numTestCases];
    for (int i = 0; i < numTestCases; i++)
    {
        cin >> fullInput[i];
    }

    for (int i = 0; i < numTestCases; i++)
    {
        stringstream ss(fullInput[i]);

        if (getline(ss, word1, '|') && getline(ss, word2))
        {
            // nEW ILINE
            if (word1 == word2)
            {
                cout << fullInput[i] << " = NOT AN ANAGRAM" << endl;
            }
            else
            {
                string sorted_word1 = word1;
                string sorted_word2 = word2;

                // Sorts strings alphabetically
                sort(sorted_word1.begin(), sorted_word1.end());
                sort(sorted_word2.begin(), sorted_word2.end());

                // If the sorted strings match, they are anagrams
                if (sorted_word1 == sorted_word2)
                {
                    cout << fullInput[i] << " = ANAGRAM" << endl;
                }
                else
                {
                    cout << fullInput[i] << " = NOT AN ANAGRAM" << endl;
                }
            }
        }
    }

    delete[] fullInput;
    return 0;
}