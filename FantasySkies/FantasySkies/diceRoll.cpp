#include <chrono>
#include <random>

int diceRoll(int faces)
{
    static std::mt19937 mt{
                static_cast<std::mt19937::result_type>(std::chrono::steady_clock::now().time_since_epoch().count())
    };
    std::uniform_int_distribution<> d{ 1, faces };

    return d(mt);
}
