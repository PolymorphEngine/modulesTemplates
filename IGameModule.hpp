namespace arcade 
{
    class IGameModule
    {
        /**
         * @returns (1) if next game, (-1) if previous game, (0) if end, (84) if error
         */
        int run();
    };
}