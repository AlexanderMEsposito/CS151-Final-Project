#pragma once

#include <SFML/Graphics.hpp>


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

/**
 * @brief Returns a float ranging from a to b
 * 
 * @param a 
 * @param b 
 * @return float 
 */
float randrange(float a, float b);

/**
 * @brief Returns a sf::Vector2f at a random point in the box bounded by a and b
 * 
 * @param a 
 * @param b 
 * @return sf::Vector2f 
 */
sf::Vector2f randpoint(const sf::Vector2f& a, const sf::Vector2f& b);
