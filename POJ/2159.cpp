#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string line1;
    string line2;

    cin >> line1;
    cin >> line2;

    if (line1.size() != line2.size())
    {
        cout << "NO\n";
        return 0;
    }
    else
    {
        int line1Count[26] = {0};
        int line2Count[26] = {0};

        for (int i = 0; i < line1.size(); i++)
        {
            line1Count[line1[i] - 'A']++;
            line2Count[line2[i] - 'A']++;
        }

        sort(line1Count, line1Count + 26);
        sort(line2Count, line2Count + 26);

        for (int i = 0; i < 26; i++)
        {
            if (line1Count[i] != line2Count[i])
            {
                cout << "NO\n";
                return 0;
            }
        }

        cout << "YES\n";
    }
}