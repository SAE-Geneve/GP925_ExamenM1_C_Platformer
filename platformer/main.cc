// Platformer : courir, sauter de plateforme en plateforme, franchir la fosse par le haut
// et atteindre la porte posee sur le sol de droite.

#include <iostream>
#include <optional>
#include <string>

#include <SFML/Graphics.hpp>

#include "heros.h"
#include "niveau.h"

namespace {

constexpr float kPasDeTemps = 1.f / 60.f;
constexpr float kDepartX = 100.f;
constexpr float kDepartPiedY = 570.f;
constexpr float kHorsDeLEcran = 660.f;

}  // namespace

int main() {
  // La police est livree dans data/, que CMake copie a cote de l'executable.
  sf::Font police;
  if (!police.openFromFile("data/tuffy.ttf")) {
    std::cerr << "Police introuvable : data/tuffy.ttf" << std::endl;
    return 1;
  }

  sf::RenderWindow fenetre(sf::VideoMode({800u, 600u}), "Platformer");
  fenetre.setFramerateLimit(60);

  Niveau niveau;
  Heros heros(kDepartX, kDepartPiedY);
  std::string message;

  sf::Text ligne(police, "", 16);

  std::cout << "Platformer -- clique dans la fenetre, puis fleches pour courir, espace pour "
               "sauter. La porte jaune est la sortie."
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

    if (heros.PiedY() > kHorsDeLEcran) {
      heros = Heros(kDepartX, kDepartPiedY);
      message = "Tombe. Retour au depart.";
      std::cout << message << std::endl;
    }

    fenetre.clear(sf::Color(28, 32, 44));
    niveau.Dessiner(fenetre);
    heros.Dessiner(fenetre);

    ligne.setFillColor(sf::Color(140, 149, 168));
    ligne.setString("Fleches : courir     Espace : sauter     Objectif : la porte, de l'autre "
                    "cote de la fosse");
    ligne.setPosition({24.f, 16.f});
    fenetre.draw(ligne);

    ligne.setFillColor(sf::Color(224, 160, 90));
    ligne.setString(message);
    ligne.setPosition({24.f, 40.f});
    fenetre.draw(ligne);

    fenetre.display();
  }
}
