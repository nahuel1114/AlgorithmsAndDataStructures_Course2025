//
// Created by nahue on 29/5/2025.
//
#include "explorationTracker.hpp"
#include <iostream>

bool ExplorationTracker::wasExplored(int x, int y) const
{
    return map.test(x*CHUNKS + y);
}

void ExplorationTracker::tickExplored(int x, int y)
{
    map.set(x * CHUNKS + y);
}

void ExplorationTracker::printMap() const
{
    for (int i = 0; i < CHUNKS; i++)
    {
        std::cout <<"-";
    }
    std::cout << "\n" << "|";
    for (int i = 0; i < map.size(); i++)
    {
        if (map.test(i))
        {
            std::cout<<"🟩";
        }
        else
        {
            std::cout<<"⬛";
        }
        if (i%CHUNKS == 0)
        {
            std::cout<<"\n"<< "|";
        }
    }
    for (int i = 0; i < CHUNKS; i++)
    {
        std::cout <<"-";
    }
}
