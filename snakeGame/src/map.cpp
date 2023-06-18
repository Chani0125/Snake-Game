#include "map.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#define FILENAME(n) "./map/map" + to_string(n) + ".txt"

using namespace std;

vector<vector<vector<int>>> map;

int loadMapFile()
{
    int fileNum = 0;
    ifstream file;

    file.open(FILENAME(fileNum));
    
    while(file.is_open())
    {
        if (file.eof())
        {
            fileNum++;
            continue;
        }

        int x = 0, y = 0;
        string map_str_line;
        vector<vector<int>> tmp_map;

        getline(file, map_str_line);
        y = map_str_line.length();

        vector<int> tmp_map_line(y, 2);

        for (int i = 0; i < y; i++)
            tmp_map_line[i] = map_str_line[i] - '0';
        tmp_map.push_back(tmp_map_line); x++;



        while (!file.eof())
        {
            getline(file, map_str_line);
            for (int i = 0; i < y; i++)
                tmp_map_line[i] = map_str_line[i] - '0';
            tmp_map.push_back(tmp_map_line); x++;
        }

        map.push_back(tmp_map);

        file.close();
        file.open(FILENAME(++fileNum));
    }

    return fileNum;
}
