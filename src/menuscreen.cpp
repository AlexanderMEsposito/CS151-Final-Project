#include "../include/menuscreen.h"
#include "../include/constants.h"

//default constructor
MenuScreen::MenuScreen() {
    bg.setOrigin({0, 0});
    bg.setPosition({0, 0});
    newGamebtn.setText(newGame);
    newGamebtn.setColor(sf::Color::Transparent);
    newGamebtn.setSize({510, 78});
    newGamebtn.setPosition({387, 584});
    menuButtons.push_back(newGamebtn);

    continuebtn.setText(continueGame);
    continuebtn.setColor(sf::Color::Transparent);
    continuebtn.setSize({510, 78});
    continuebtn.setPosition({387, 674});
    menuButtons.push_back(continuebtn);

    optionsbtn.setText(options);
    optionsbtn.setColor(sf::Color::Transparent);
    optionsbtn.setSize({510, 78});
    optionsbtn.setPosition({387, 764});
    menuButtons.push_back(optionsbtn);

    quitbtn.setText(quit);
    quitbtn.setColor(sf::Color::Transparent);
    quitbtn.setSize({510, 78});
    quitbtn.setPosition({387, 854});
    menuButtons.push_back(quitbtn);
    
    newGamebtn.setColorHover(Constants::Color::toxicGreen);
    optionsbtn.setColorHover(Constants::Color::toxicGreen);
    quitbtn.setColorHover(Constants::Color::toxicGreen);
}

void MenuScreen::handleEvent(const sf::Event& event, sf::RenderWindow &window) {
    for (unsigned int i = 0; i < menuButtons.size(); i++) {
        menuButtons[i].handleInput(event, window);
    }
}
void MenuScreen::update(float dt) {
    for (unsigned int i = 0; i < menuButtons.size(); i++) {
        menuButtons[i].update();
    }
}
void MenuScreen::draw(sf::RenderWindow& window) const {
    window.draw(bg);
    for (unsigned int i = 0; i < menuButtons.size(); i++) {
        window.draw(menuButtons[i]);
    }
    
}