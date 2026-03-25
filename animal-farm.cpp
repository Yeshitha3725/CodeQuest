/*#include <iostream>

using namespace std;

int main()
{
    int numTestCases;

    if (!(cin >> numTestCases))
        return 0;

    int *result = new int[numTestCases];
    int *animalCounts = new int[3];

    for (int i = 0; i < numTestCases; i++)
    {

        for (int t = 0; t < 3; t++)
        {

            cin >> animalCounts[t];
        }

        int totalLegs = (animalCounts[0] * 2) + (animalCounts[1] * 4) + (animalCounts[2] * 4);
        result[i] = totalLegs;
    }

    for (int i = 0; i < numTestCases; i++)
    {
        cout << result[i] << "\n";
    }

    delete[] result;

    return 0;
}*/