#pragma once

#include "timer.h"

class RoundManager
{
public:
    int update(int livingEnemyCount);

    int getRoundNumber() const { return roundNumber; }
    int getRemainingToSpawn() const { return remainingToSpawn; }
    bool isIntermission() const { return intermission; }
    int getIntermissionSecondsRemaining() const;

private:
    static constexpr int spawnBatchSize {5};
    static constexpr int maxLivingEnemies {20};
    static constexpr float spawnIntervalSeconds {10.0f};
    static constexpr float intermissionDurationSeconds {12.0f};

    int roundNumber {1};
    int remainingToSpawn {10};
    bool firstBatch {true};
    bool intermission {false};
    Timer spawnTimer {spawnIntervalSeconds};
    Timer intermissionTimer {intermissionDurationSeconds};
};
