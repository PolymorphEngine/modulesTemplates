/*
** EPITECH PROJECT, 2022
** archi
** File description:
** IGameModule
*/

#include <string>
#include <vector>

namespace arcade 
{
    class IGameModule
    {
        /** @returns the path of the coreboard file */
        std::string scoreboardPath();

        /**
         * @returns tuple with :
         *              - int : status code
         *              - std::string : path to the next gameLib to launch
         *              - std::string : path to graphical lib to launch by the the new game
         * @params gameLibs vector of all the loadable game libs
         * @params graphLibs vector of all the loadable graphical libs
         * @params pathToGraphLib the path of the grpahical lib that will be used at the start of the game
         */
        std::tuple<int, std::string, std::string> run(const std::vector<std::string>& gameLibs, 
                                                      const std::vector<std::string>& graphLibs, 
                                                      const std::string &pathToMenuLib, 
                                                      const std::string& pathToGraphLib);

    };
}