//
// Created by nahue on 29/5/2025.
//

#ifndef EXPLORATIONTRACKER_H
#define EXPLORATIONTRACKER_H
#include <bitset>
#include <map>

const int CHUNKS = 64;

class ExplorationTracker
{
private:
    std::bitset<CHUNKS*CHUNKS> map;

public:
    bool wasExplored(int x, int y) const;
    void tickExplored(int x, int y);
    void printMap() const;
};

#endif //EXPLORATIONTRACKER_H
