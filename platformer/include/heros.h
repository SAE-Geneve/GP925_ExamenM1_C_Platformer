#pragma once

#include <SFML/Graphics.hpp>

// Le heros. Sa position verticale est celle de ses pieds.
class Heros {
 public:
  Heros(float x, float pied_y);

  float X() const;
  float PiedY() const;
  float VitesseY() const;

  // direction vaut -1 (gauche), 0 (immobile) ou +1 (droite).
  void Deplacer(float direction, float pas_de_temps);
  void Sauter();

  // Gravite, puis position.
  void MettreAJour(float pas_de_temps);

  // Pose les pieds du heros sur une plateforme et coupe sa chute.
  void PoserSur(float hauteur);

  void Dessiner(sf::RenderWindow& fenetre) const;

 private:
  float x_;
  float pied_y_;
  float vitesse_y_;
  bool au_sol_;
};
