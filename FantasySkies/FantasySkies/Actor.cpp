#include "Actor.h"

void Actor::rollDeathSave()
{
    const auto rollRes{ diceRoll(20) };

    if (rollRes >= 10)
    {
        m_sDeathSaves++;

        std::cout << m_name << "'s death save was a success!" << std::endl;

        if (rollRes == 20)
        {
            m_sDeathSaves = 0;
            m_fDeathSaves = 0;
            modHp(1);

            std::cout << m_name << "'s death save was a critical success!. " << m_name << " is now alive and with 1 HP!" << std::endl;
        }
    }
    else
    {
        if (rollRes == 1)
            m_fDeathSaves += 2;
        else
            m_fDeathSaves++;
    }


    if (m_sDeathSaves == 3)
    {
        m_isStable = true;

        std::cout << m_name << "is stable!" << std::endl;
    }
    else
        m_shouldDie = true;
}
