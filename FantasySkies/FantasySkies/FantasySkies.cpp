#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Actor.h"
#include "checkDeaths.h"

int main()
{
    std::cout << "FantasySkies: Dungeons and Dragons 5E combat tracker by Lucas M. Noel.\nAvailable " <<
	"functions: \n\t - 'l' = > Lists creatures in the combat tracker ordered by initiative count along " <<
	"with their hit points.\n\t - 'a' = > Adds a creature to the combat tracker.Monsters that reach 0H P" <<
	"will automatically be removed from the combat tracker.\n\t - 'm' = > Modifies a creature's HP by name. " <<
	"Use negative numbers if you want to deal damage.\n\t - 'x' = > Closes the program.\n\nWARNING! This " <<
	"program speaks in somewhat Shakespearean English.\nEnjoy!\n" << std::endl;

    std::vector<Actor> combatTracker{};

    auto sortInitiative{
    	[](const Actor& initA, const Actor& initB) -> bool { return initA.getInitiative() > initB.getInitiative(); }
	};
    auto encounterMembers{
    	[](const std::vector<Actor>& cTracker) -> void {
            for (auto& creature : cTracker)
            {
                std::cout << "Initiative: " << creature.getInitiative() << ", " << creature.getName() << ". ";
                std::cout << creature.getName() << " has " << creature.getHp() << " hit points." << std::endl;
            }
		}
    };

    std::cout << "I bid thee welcome!";

    while (true)
    {
        char function{};

        std::string name{};
        int hp{};
        int init{};

        checkDeaths(combatTracker);
        std::cout << "O' Great Master o' Dungeons, what is thy bidding?: ";
        std::cin >> function;

        switch(function)
        {
        case 'l':
            encounterMembers(combatTracker);
            break;
        case 'a':
            std::cout << "Tell me of thine champion's name, vitality, and haste: ";
            std::cin >> name >> hp >> init;

            combatTracker.emplace_back(Actor(name, hp, init));
            std::sort(combatTracker.begin(), combatTracker.end(), sortInitiative);
            break;
        case 'm':
            std::cout << "Speak of they who wilt receive thy blessing or curse and the might of this effect: ";
            std::cin >> name >> hp;

            for (auto& creature: combatTracker)
                if (creature.getName() == name)
                    creature.modHp(hp);
            break;
        case 'x':
            std::cout << "I bid thee Farewell";
            return 0;
        default:
            std::cout << "Sorry for mine incompetence, for I hath failed to comprehend thy message : '" << function << "'." << std::endl;
        }
    }
}
