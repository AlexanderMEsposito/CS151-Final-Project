/**
 * @file menuscreen.h
 * @author The Cool Guys
 * @brief Menu Screen derived from Screen class
 * @version 0.1
 * @date 2026-10-29
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once
#include "../include/screen.h"
class MenuScreen: public Screen {
    public:
        MenuScreen Menu();
        virtual void handleEvent(const sf::Event& event) override;
        virtual void update(float dt) override;
        virtual void draw(sf::RenderWindow& window) const override;
    private:

};