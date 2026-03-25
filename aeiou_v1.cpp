#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    int numTestCases;
    

    if (!(cin >> numTestCases))
        return 0;

    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < numTestCases; ++i)
    {
        string line;
        
        getline(cin, line);

        int vowelCount = 0;
        
        for (char c : line)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                vowelCount++;
            }
        }

        
        cout << vowelCount << endl;
    }

    return 0;
}