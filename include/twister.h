#pragma once


void seed_random();

// Returns a random unsigned integer
unsigned int twist();

/**
 * @brief Returns a random int I where min <= I <= max
 * 
 * @param min 
 * @param max 
 * @return int 
 */
int randint(int min, int max);

/**
 * @brief Returns a random float from 0 to 1
 * 
 * @return float 
 */
float randomf();


/**
 * @brief Returns a random bool based on x. If x is 1, will always return true. If x is 0, will always return false;
 * 
 * @return bool 
 */
bool chance(float x);

