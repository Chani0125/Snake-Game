#ifndef _MISSION_
#define _MISSION_

#include "game_info.h"
#include "snake.h"

class Mission
{
private:
public:
    GameInfo goal;
    vector<bool> achieve;

    Mission();
    Mission(GameInfo info);

    void SetMission();
    void IsAchieve(GameInfo current);
    bool isCleared();
    
    ~Mission();
};

#endif