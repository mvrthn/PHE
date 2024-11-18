#include "app.hpp"

#include <iostream>


namespace PHE {

sf::RenderWindow* w; // DELETE

void update(Vector2f& vector) { 
    sf::Vector2i mousePos = sf::Mouse::getPosition(*w);
    vector.x = mousePos.x - (WIDTH / 2);
    vector.y = -mousePos.y + (HEIGHT / 2);
    vector -= {120, 160};
}

void App::run() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "PHE");
    w = &window; // DELETE

    Force forces[] = {
        Force(Vector2f(100, 200), Vector2f(120, 160), update)
    };

    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        drawPlain(window);
        drawCircle(window);

        for(Force& force : forces) {
            force.update();
            drawForce(window, force);
            drawResulatants(window, force);
            //drawDisplacement(window, force);
        }

        window.display();
    }
}

void App::drawDisplacement(sf::RenderTarget& target, const Force& force) {
    sf::Vertex line[2] = {
        sf::Vertex(sf::Vector2f(coord00.x, coord00.y), sf::Color::White), 
        sf::Vertex(sf::Vector2f(coord00.x + force.getOrigin().x, coord00.y - force.getOrigin().y), sf::Color::White)
    };
    target.draw(line, 2, sf::Lines);
}

void App::drawResulatants(sf::RenderTarget& target, const Force& force) {
    const Vector2f& d = force.getOrigin();
    const float dv = d();
    const float e = 1 / (dv * dv);
    const float dx2 = d.x * d.x * e;
    const float dy2 = d.y * d.y * e;
    const float dxdy = d.x * d.y * e;

    const Vector2f& f = force.getVector();
    const float x = f.x;
    const float y = f.y;

    Vector2f progresive = Vector2f(dx2 * x, dxdy * x) + Vector2f(dxdy * y, dy2 * y);
    drawForce(target, Force(progresive, d, nullptr));

    Vector2f rotation = Vector2f(dy2 * x, -dxdy * x) + Vector2f(-dxdy * y, dx2 * y);
    drawForce(target, Force(rotation, d, nullptr));
}

void App::drawVector(sf::RenderTarget& target, const Vector2f& origin, const Vector2f& vector) {
    sf::Vertex line[2] = {
        sf::Vertex(sf::Vector2f(origin.x, origin.y), sf::Color::Red), 
        sf::Vertex(sf::Vector2f(origin.x + vector.x, origin.y - vector.y), sf::Color::Green)
    };
    target.draw(line, 2, sf::Lines);
}

void App::drawForce(sf::RenderTarget& target, const Force& force) {
    drawVector(target, Vector2f(coord00.x + force.getOrigin().x, coord00.y - force.getOrigin().y), force.getVector());
}

void App::drawPlain(sf::RenderTarget& target) {
    sf::Vertex horizontal[2] = {
        sf::Vertex(sf::Vector2f(0, coord00.y)),
        sf::Vertex(sf::Vector2f(WIDTH, coord00.y)),
    };
    target.draw(horizontal, 2, sf::Lines);

    sf::Vertex vertical[2] = {
        sf::Vertex(sf::Vector2f(coord00.x, 0)),
        sf::Vertex(sf::Vector2f(coord00.x, HEIGHT)),
    };
    target.draw(vertical, 2, sf::Lines);
}

void App::drawCircle(sf::RenderTarget& target) {
    sf::CircleShape circle(200);
    circle.setOutlineThickness(-5);
    circle.setFillColor(sf::Color::Transparent);
    circle.setPosition({coord00.x - 200, coord00.y - 200});
    target.draw(circle);
}

} // namespace PHE