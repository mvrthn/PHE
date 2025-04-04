#include "app.hpp"

#include "yacht.hpp"


namespace PHEApp {

void App::run() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "PHE");

    Yacht yacht;
    yacht.setPosition({WIDTH / 2, HEIGHT / 2});

    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        yacht.update();

        window.clear();
        
        yacht.display(window);

        window.display();
    }
}

} // namespace PHEApp