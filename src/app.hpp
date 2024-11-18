#pragma once


#include <SFML/Graphics.hpp>

#include "vectors.hpp"
#include "force.hpp"

#define WIDTH 1600
#define HEIGHT 1000


namespace PHE {

class App {
public:
    void run();

private:
    void drawDisplacement(sf::RenderTarget&, const Force&);
    void drawResulatants(sf::RenderTarget&, const Force&);
    void drawVector(sf::RenderTarget&, const Vector2f&, const Vector2f&);
    void drawForce(sf::RenderTarget&, const Force&);
    void drawPlain(sf::RenderTarget&);
    void drawCircle(sf::RenderTarget&);

    const Vector2f coord00 = Vector2f(WIDTH / 2, HEIGHT / 2);
};

} // namespace PHE