// #include <ncurses/ncurses.h>
#include <ncurses.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "map.h"
// #include "draw.h"
// #include "mission.h"
// #include "growthItem.h"
// #include "poisonItem.h"
// #include "gate.h"

using namespace std;

int main()
{
    int num = 0;
    loadMapFile();

    cout << "[Map Test]" << "\n\n";

    for (vector<vector<int>> m : map)
    {
        cout << "[Map" << num++ << "]" << "\n";
        for (vector<int> x : m)
        {
            for (int y : x)
            {
                cout << y << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }



    return 0;
}


