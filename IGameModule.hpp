namespace arcade 
{
    class IGameModule
    {

        /** @returns if this library is the menu */
        bool isMenu();

        /** @returns the path of the coreboard file */
        std::string scoreboardPath();

        /**
         * @returns int (status code): (1) if next game, (-1) if previous game, (0) if end, (84) if error
         *          string : path to actual .so grpahical lib
         */
        std::pair<int, std::string> run(std::string pathToGraphLib);

    };
}