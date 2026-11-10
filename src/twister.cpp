#include "../include/twister.h"
#include <iostream>
#include <random>

unsigned int last = 0;
int MAX = 0xFFFFFFFF;
float MAXF = float(0xFFFFFFFF);

std::random_device device;

std::mt19937 generator(device());

std::uniform_int_distribution<int> distribInt(0, MAX);
std::uniform_real_distribution<float> distribFloat(0.0f, 1.0f);

constexpr unsigned int A {3756735}, B {25434}, C {74342}, D {7654345}, E {6433335};

void seed_random()
{
    
}


unsigned int twist()
{
    return distribInt(generator);
}


int randint(int min, int max)
{
    return int(randomf() * float(max - min)) + min;
}


float randomf()
{
    return distribFloat(generator);
}

bool chance(float x)
{
    return randomf() < x;
}





