#include <vector>

#include "Actor.h"

void checkDeaths(std::vector<Actor>& combatTracker)
{
    int index{ 0 };

    for (auto& creature : combatTracker)
    {
        if (creature.getHp() <= 0)
        {
            if (!creature.hasDeathSaves() || (creature.shouldDie()))
                combatTracker.erase(combatTracker.begin() + index);
            else
                creature.rollDeathSave();
        }
        index++;
    }
}
