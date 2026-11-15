#pragma once

#include <SFML/Graphics.hpp>

#include "heros.h"

// Le sol, les deux plateformes et la porte de sortie.
class Niveau {
 public:
  Niveau();

  void Dessiner(sf::RenderWindow& fenetre) const;

  // Pose le heros sur la premiere plateforme qui le soutient. Rend vrai s'il en
  // a trouve une.
  bool PoseLeHeros(Heros& heros) const;

  bool EstSurLaSortie(const Heros& heros) const;

 private:
  static bool Atterrit(Heros& heros, const sf::RectangleShape& plateforme);

  sf::RectangleShape sol_;
  sf::RectangleShape plateforme_a_;
  sf::RectangleShape plateforme_b_;
  sf::RectangleShape sortie_;
};
