#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <tuple>


bool Agreed() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
        return true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
        return false;
    }
}

struct Academic {
    sf::Sprite sprite;
    float rating;       // Maybe sth else
};

bool IsaFucker(Academic *deg) { // Use rating. Maybe for OLEG
    deg->rating;
    //FIX
    return true;
}


std::tuple<Academic, Academic> AddCoupleOfAcademic(Academic *left, Academic *right) { // For OLEG. Do as the next, but better use srand() with current time of SFML. Use rand() % 10
                                                                // It should create 2 academics with sprite and rating uploaded
    return std::make_tuple(*left, *right);
}
bool DidUserGuess(sf::Text text, bool init, Academic *left, Academic *right, int score, float time) {
    if (init == true) {
        float answer_time = 0;
        int var = rand() % 3;
        answer_time = time;

        if (var == 0) {
            text.setString("If the left is a fucker?[Y/n]");
            if ((Agreed() && IsaFucker(left) && answer_time <= 2.0)) {
                score++;                        // I dunno, you can add here conditions for score decrement
                return true;
            }
            else {
                text.setString("You are fucked");
                return false;
            }
        }
        else if (var == 1) {
            text.setString("If the right is a fucker?[Y/n]");
            if ((Agreed() && IsaFucker(right) && answer_time <= 2.0)) {
                score++;
                return true;
            }
            else {
                text.setString("You are fucked");
                return false;
            }
        }
        else if (var == 2) {
            text.setString("If they both are fuckers?[Y/n]");
            if ((Agreed() && IsaFucker(left) && IsaFucker(right) && answer_time <= 2.0)) {
                score++;
                return true;
            }
            else {
                text.setString("You are fucked");
                return false;
            }
        }
    }
}
void PlayTheSound(sf::SoundBuffer buffer, sf::Sound sound) { // For DAN. Do as the previous, sounds for fuckers in the folder Heavy_responses. Use rand() % as many as you like
    sound.setBuffer(buffer);
    sound.play();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 960), "Matan demo"); // Wanna rid of this stuff, so cut what do you need
    sf::SoundBuffer buffer; // For DAN. Upload the sound
    buffer.loadFromFile("");
    sf::Font font;
    sf::Text text("", font, 24);
    text.setPosition(640, 800); // the right position need to be found, that what I presume
    sf::Texture academic; // For OLEG. Upload the image
    academic.loadFromFile("");


    Academic *left_portrait;
    left_portrait->sprite.setTexture(academic);
    left_portrait->sprite.setTextureRect(sf::IntRect(100, 100, 100, 100)); // Cut it from texture properly
    left_portrait->sprite.setPosition(200, 300); // Place it properly

    Academic *right_portrait;
    right_portrait->sprite.setTexture(academic);
    right_portrait->sprite.setTextureRect(sf::IntRect(100, 100, 100, 100)); // Cut it from texture properly
    right_portrait->sprite.setPosition(500, 300); // Place it properly

    sf::Sound sound;
    font.loadFromFile("arial.ttf");
    text.setFillColor(sf::Color(34, 139, 34));
    text.setStyle(sf::Text::Bold);



    int score = 0;


    sf::Clock clock;

    sf::Event event;
    while(window.isOpen()) {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        time = time/666;

        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        bool init = false;
        bool term;
        text.setString("Are you ready for exam?[Y/n]");
        if (Agreed())
            init = true;
        else if (not Agreed())
            text.setString("See you at the retake");

        do {
            AddCoupleOfAcademic(left_portrait, right_portrait);
     //missing template arguments for tuple       //std::tuple(left_portrait, right_portrait) = AddCoupleOfAcademic(left_portrait, right_portrait);
            DidUserGuess(text, init, left_portrait, right_portrait, score, time);
            PlayTheSound(buffer, sound);
           /* std::thread image(AddCoupleOfAcademic, (left_portrait, right_portrait));
            std::tuple(left_portrait, right_portrait) = AddCoupleOfAcademic(left_portrait, right_portrait);
            std::thread general(DidUserGuess, (text, init, left_portrait, right_portrait, score, time));
            std::thread audio(PlayTheSound, (buffer, sound));

            image.join();
            general.join();
            audio.join();   */

            window.clear(sf::Color(255, 250, 205));
            window.draw(left_portrait->sprite);
            window.draw(right_portrait->sprite);
            window.draw(text);
            window.display();
        } while (score <= 10);
    }

    window.clear(sf::Color(255, 250, 205));
    /*if (DidUserGuess() = true)
        window.clear(sf::Color(164, 211, 238));
    if (DidUserGuess() = false)
        window.clear(sf::Color(139, 0, 0)); */
    return 0;
}