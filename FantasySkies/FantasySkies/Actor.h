#pragma once

#include <iostream>

#include "diceRoll.h"

class Actor
{
    std::string m_name{};
    int m_hp{};
    int m_initiative{};
    bool m_hasDeathSaves{};
    int m_sDeathSaves{};
    int m_fDeathSaves{};
    bool m_isStable{};
    bool m_shouldDie{};
public:
    Actor() = default;

    Actor(std::string name, const int hp, const int init, const bool hasDSs = false)
        : m_name{ std::move(name) }, m_hp{ hp }, m_initiative{ init }, m_hasDeathSaves{ hasDSs }
    {
        if (!init)
            m_initiative = diceRoll(20);
    }

    auto getName() const { return m_name; }
    auto getHp() const { return m_hp; }
    auto getInitiative() const { return m_initiative; }
    auto hasDeathSaves() const { return m_hasDeathSaves; }
    auto getFailedSaves() const { return m_fDeathSaves; }
    auto isStable() const { return m_isStable; }
    auto shouldDie() const { return m_shouldDie; }

    void modHp(const int amount) { m_hp += amount; }
    void rollDeathSave();
};
