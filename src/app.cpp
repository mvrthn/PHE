#include "app.hpp"

#include <SFML/Graphics.hpp>

#include "yacht.hpp"
#include "vectors.hpp"
#include "force.hpp"


namespace PHEApp {

void App::run() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "PHE", sf::Style::Close);
    window.setFramerateLimit(100);

    Yacht yacht({WIDTH / 2, HEIGHT / 2});

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