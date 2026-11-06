/**
 * @file button.cpp
 * @author Professor Ekaterina Miller
 * @brief Button Class taken from Project Organization Repository (https://github.com/CS151-Fall2026/progectOrganization)
 * @version ?
 * @date 2026-10-06
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#include "../include/button.h"
#include "../include/constants.h"

Button::Button()
{

}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mButton, states);
    target.draw(mText, states);
}

bool Button::handleInput(const sf::Event& e, sf::RenderWindow& window)
{
    const sf::Vector2i mousePixelPos = sf::Mouse::getPosition(window);
    const sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixelPos);
    const bool mouseInButton = mButton.getGlobalBounds().contains(mousePosition);

    if (e.getIf<sf::Event::MouseMoved>())
    {
        mBtnState = mouseInButton ? hovered : normal;
    }

    if (const auto* mouseButtonPressed = e.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left)
        {
            if (mouseInButton)
            {
                mBtnState = clicked;
                return true;
            }
            mBtnState = normal;
        }
    }

    if (const auto* mouseButtonReleased = e.getIf<sf::Event::MouseButtonReleased>())
    {
        if (mouseButtonReleased->button == sf::Mouse::Button::Left)
        {
            mBtnState = mouseInButton ? hovered : normal;
        }
    }

    return false;
}

void Button::update()
{
    switch (mBtnState)
    {
    case normal:
        mButton.setRotation(sf::degrees(0.f));
        setColor(sf::Color::Transparent);
        setColorTextNormal(sf::Color::White);
        break;
    case hovered:
        mButton.setRotation(sf::degrees(0.f));
        setColorHover(Constants::Color::toxicGreen);
        setColorTextHover(sf::Color::Black);
        break;
    case clicked:
        setColorClicked(Constants::Color::toxicGreen);
        setColorTextClicked(sf::Color::Black);       
        break;
    }
}

void Button::setText(sf::Text text)
{
    mText = text;
}

void Button::setPosition(sf::Vector2f position)
{
    mPosition = position;
    mButton.setPosition(mPosition);
    unsigned int fontSize = mButton.getGlobalBounds().size.y/2;
    mText.setCharacterSize(fontSize);
    //set origin to the middle
    mText.setOrigin({mText.getGlobalBounds().size.x/2, mText.getGlobalBounds().size.y/2});
    //set position at the middle of the button
    mText.setPosition({mPosition.x, mPosition.y-fontSize/4});
}

void Button::setSize(sf::Vector2f size)
{
    mButton.setSize(size);
    //get size of image
    sf::Vector2f buttonSize=mButton.getSize();
    mButton.setOrigin({buttonSize.x/2.f, buttonSize.y/2.f});
    //set position
    mButton.setPosition(mPosition);

    //choose the font size based on button size (I choose half)
    unsigned int fontSize = mButton.getGlobalBounds().size.y/2;
    mText.setCharacterSize(fontSize);
    //set origin to the middle
    mText.setOrigin({mText.getGlobalBounds().size.x/2, mText.getGlobalBounds().size.y/2});
    //set position at the middle of the button
    mText.setPosition({mPosition.x, mPosition.y-fontSize/4});
}

void Button::setColor(sf::Color btnColor)
{
    mButtonColor = btnColor;
    mButton.setFillColor(mButtonColor);
}
void Button::setColorHover(sf::Color btnColor)
{
    mButtonColorHover = btnColor;
    mButton.setFillColor(mButtonColorHover);
}
void Button::setColorClicked(sf::Color btnColor)
{
    mButtonColorClicked = btnColor;
    mButton.setFillColor(mButtonColorClicked);
}
void Button::setColorTextNormal(sf::Color btnColor)
{
    mTextNormal = btnColor;
    mText.setFillColor(mTextNormal);
}
void Button::setColorTextHover(sf::Color btnColor)
{
    mTextHover = btnColor;
    mText.setFillColor(mTextHover);
}
void Button::setColorTextClicked(sf::Color btnColor)
{
    mTextClicked = btnColor;
    mText.setFillColor(mTextClicked);
}