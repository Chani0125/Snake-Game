#include "mission.h"
#include "game_map.h"
#include "random"

Mission::Mission()
{
    SetMission();
    achieve = vector<bool>(4, false);
}

Mission::Mission(GameInfo info)
{
    goal = info;
    achieve = vector<bool>(4, false);
}

Mission::~Mission()
{
}

void Mission::SetMission()
{
    goal = GameInfo();
    achieve = vector<bool>(4, false);

    random_device rd;
    mt19937 gen(rd());

    binomial_distribution<int> b_body_len(STAGE + 6, 0.2);
    binomial_distribution<int> b_n_growth(STAGE + 8, 0.3);
    binomial_distribution<int> b_n_poison(STAGE + 4, 0.2);
    binomial_distribution<int> b_n_gate  (STAGE + 2, 0.2);

    goal.body_len = 3 + b_body_len(gen);    
    // if (goal.body_len > (MAP_H + MAP_W) * 2)
    //     goal.body_len = (MAP_H + MAP_W) * 2;
    goal.n_growth = b_n_growth(gen);
    goal.n_poison = b_n_poison(gen);
    goal.n_gate   = b_n_gate(gen);
}

void Mission::IsAchieve(GameInfo current)
{
    if (!achieve[0])
        achieve[0] = current.body_len >= goal.body_len;
    if (!achieve[1])
        achieve[1] = current.n_growth >= goal.n_growth;
    if (!achieve[2])
        achieve[2] = current.n_poison >= goal.n_poison;
    if (!achieve[3])
        achieve[3] = current.n_gate >= goal.n_gate;
}

bool Mission::isCleared()
{
    bool ans = true;
    for (int i = 0; i < 4; i++)
        if (!achieve[i])
            ans = false;
    return ans;
}