// Platformer : courir, sauter de plateforme en plateforme, atteindre la porte.

#include <iostream>
#include <optional>

#include <SFML/Graphics.hpp>

#include "heros.h"
#include "niveau.h"

namespace {

constexpr float kPasDeTemps = 1.f / 60.f;
constexpr float kDepartX = 100.f;
constexpr float kDepartPiedY = 570.f;
constexpr float kBasDeLEcran = 600.f;

}  // namespace

int main() {
  sf::RenderWindow fenetre(sf::VideoMode({800u, 600u}), "Platformer");
  fenetre.setFramerateLimit(60);

  Niveau niveau;
  Heros heros(kDepartX, kDepartPiedY);
  bool sorti_de_l_ecran = false;

  std::cout << "Platformer -- fleches pour courir, espace pour sauter. La porte jaune est la "
               "sortie."
            << std::endl;

  while (fenetre.isOpen()) {
    while (const std::optional evenement = fenetre.pollEvent()) {
      if (evenement->is<sf::Event::Closed>()) {
        fenetre.close();
      } else if (const auto* touche = evenement->getIf<sf::Event::KeyPressed>()) {
        if (touche->code == sf::Keyboard::Key::Space) {
          heros.Sauter();
        }
      }
    }

    float direction = 0.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
      direction -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
      direction += 1.f;
    }

    heros.Deplacer(direction, kPasDeTemps);
    heros.MettreAJour(kPasDeTemps);
    niveau.PoseLeHeros(heros);

    if (niveau.EstSurLaSortie(heros)) {
      std::cout << "Sortie atteinte." << std::endl;
      fenetre.close();
    }

    if (!sorti_de_l_ecran && heros.PiedY() > kBasDeLEcran) {
      std::cout << "Le heros est sorti de l'ecran par le bas." << std::endl;
      sorti_de_l_ecran = true;
    }

    fenetre.clear(sf::Color(28, 32, 44));
    niveau.Dessiner(fenetre);
    heros.Dessiner(fenetre);
    fenetre.display();
  }
}
