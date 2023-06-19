#include "mission.h"

Mission::Mission(int body_length, int num_growth, int num_poison, int num_gate, int item3, int item4)
{
    goal = GameInfo(body_length, num_growth, num_poison, num_gate, item3, item4);
    current = GameInfo();
}

Mission::~Mission()
{
}
