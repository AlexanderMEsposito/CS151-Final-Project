/**
 * @file screen.h
 * @author Abstract Base Class
 * @brief 
 * @version 0.1
 * @date 2026-10-29
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#pragma once
#include <SFML/Graphics.hpp>

class Screen {
    public:
        virtual void handleEvent(const sf::Event& event) = 0;
        virtual void update(float dt) = 0;
        virtual void draw(sf::RenderWindow& window) const = 0;

        virtual ~Screen() = default;
    private:
};