#include "roundManager.h"

#include <algorithm>
#include <cmath>

int RoundManager::update(int livingEnemyCount)
{
    if (intermission)
    {
        if (!intermissionTimer.done())
        {
            return 0;
        }

        intermission = false;
        ++roundNumber;
        remainingToSpawn = 10 + 5 * (roundNumber - 1);
        firstBatch = true;
    }

    if (remainingToSpawn == 0 && livingEnemyCount == 0)
    {
        intermission = true;
        intermissionTimer.restart();
        return 0;
    }

    if (remainingToSpawn == 0 || livingEnemyCount > maxLivingEnemies - spawnBatchSize)
    {
        return 0;
    }

    if (!firstBatch && !spawnTimer.done())
    {
        return 0;
    }

    const int spawnCount = std::min(spawnBatchSize, remainingToSpawn);
    remainingToSpawn -= spawnCount;
    firstBatch = false;
    spawnTimer.restart();

    return spawnCount;
}

int RoundManager::getIntermissionSecondsRemaining() const
{
    const float secondsRemaining = intermissionTimer.getDuration() - intermissionTimer.delta();
    return static_cast<int>(std::ceil(std::max(0.0f, secondsRemaining)));
}
