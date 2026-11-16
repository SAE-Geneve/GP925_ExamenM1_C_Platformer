#pragma once

#include <SFML/Graphics.hpp>

#include "heros.h"

// Les deux morceaux de sol separes par la fosse, les deux plateformes et la porte.
class Niveau {
 public:
  Niveau();

  void Dessiner(sf::RenderWindow& fenetre) const;

  // Pose le heros sur la premiere surface qui le soutient. Rend vrai s'il en a
  // trouve une.
  bool PoseLeHeros(Heros& heros) const;

  bool EstSurLaSortie(const Heros& heros) const;

 private:
  static bool Atterrit(Heros& heros, const sf::RectangleShape& plateforme);

  sf::RectangleShape sol_gauche_;
  sf::RectangleShape sol_droite_;
  sf::RectangleShape plateforme_a_;
  sf::RectangleShape plateforme_b_;
  sf::RectangleShape sortie_;
};
