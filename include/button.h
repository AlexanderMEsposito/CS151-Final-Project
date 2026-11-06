/**
 * @file button.h
 * @author Professor Ekaterina Miller
 * @brief Button Class taken from Project Organization Repository (https://github.com/CS151-Fall2026/progectOrganization)
 * @version ?
 * @date 2026-10-06
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


enum state {normal, hovered, clicked};

class Button: public sf::Drawable
{
public:
    //Default constructor that loads texture from file “button.png” and font from “college.ttf” file.
    //set texture for mButton, set the origin to the middle of the button (texture), 
    //set color to White, position to {300,100}, set state to normal, size to 300 by 100
    //set font for the text, set the size of the text to the half of Button size, set the origin to the middle of the text 
    //and set position at the middle of the button, assign “Push me!” as a string of the button
    Button();
    ~Button(){};
    //change button position to position (what else needs to be changed?)
    void setPosition(sf::Vector2f position);
    //change button size to size (what else needs to be changed?)
    void setSize(sf::Vector2f  size);

    //change button fill color (normal) to parameter
    void setColor(sf::Color btnColor);
    //change button fill color (hover) to parameter
    void setColorHover(sf::Color btnColorHover);
    //change button fill color (clicked) to parameter
    void setColorClicked(sf::Color btnColor);


    void setText(sf::Text text);
    void setColorTextNormal(sf::Color textNormalColor);
    void setColorTextHover(sf::Color textHoverColor);
    void setColorTextClicked(sf::Color btnColor);

    sf::Vector2f getPosition() const {return mPosition;};
    sf::Vector2f getDimensions()const {return mButton.getSize();};
    state getState()const {return mBtnState;};

    //This function update the button state and/or look
    bool handleInput(const sf::Event& e, sf::RenderWindow& window);
    void update();
    virtual void draw(sf::RenderTarget& target,sf::RenderStates states) const;

private:
    sf::RectangleShape mButton;
    sf::Texture mTexture;
    sf::Vector2f mPosition;
    state mBtnState;
    
    //text
    sf::Font mFont{"assets/fonts/Oswald/Oswald-Regular.ttf"};
    sf::Text mText{mFont};

    sf::Color mTextNormal {sf::Color::Green};
    sf::Color mTextHover {sf::Color::Red};
    sf::Color mTextClicked;
    sf::Color mButtonColor;
    sf::Color mButtonColorHover;
    sf::Color mButtonColorClicked;

};