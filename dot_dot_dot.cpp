#include <iostream>
#include <string>

using namespace std;

int main()
{
    int totalSum = 0;
    string word;
    int position;
    int testCases;

    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        totalSum = 0;

        cin >> word;

        for (char c : word)
        {
            position = (c - 'a') + 1;
            totalSum += position;
        }

        cout << totalSum << endl;
    }

    return 0;
}
