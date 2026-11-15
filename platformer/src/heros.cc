#include "heros.h"

#include <SFML/Graphics.hpp>

namespace {

constexpr float kGravite = 2000.f;      // pixels par seconde carree
constexpr float kVitesse = 240.f;       // pixels par seconde
constexpr float kImpulsionDeSaut = 950.f;

constexpr float kLargeur = 24.f;
constexpr float kHauteur = 32.f;

// Les bords de la fenetre arretent le heros.
constexpr float kLargeurDeLEcran = 800.f;

}  // namespace

Heros::Heros(float x, float pied_y) : x_(x), pied_y_(pied_y), vitesse_y_(0.f), au_sol_(true) {}

float Heros::X() const { return x_; }

float Heros::PiedY() const { return pied_y_; }

float Heros::VitesseY() const { return vitesse_y_; }

void Heros::Deplacer(float direction, float pas_de_temps) {
  x_ += direction * kVitesse * pas_de_temps;

  if (x_ < kLargeur / 2.f) {
    x_ = kLargeur / 2.f;
  }
  if (x_ > kLargeurDeLEcran - kLargeur / 2.f) {
    x_ = kLargeurDeLEcran - kLargeur / 2.f;
  }
}

void Heros::Sauter() {
  if (au_sol_) {
    vitesse_y_ = -kImpulsionDeSaut;
    au_sol_ = false;
  }
}

void Heros::MettreAJour(float pas_de_temps) {
  vitesse_y_ += kGravite * pas_de_temps;
  pied_y_ += vitesse_y_ * pas_de_temps;
  au_sol_ = false;
}

void Heros::PoserSur(float hauteur) {
  pied_y_ = hauteur;
  vitesse_y_ = 0.f;
  au_sol_ = true;
}

void Heros::Dessiner(sf::RenderWindow& fenetre) const {
  sf::RectangleShape corps({kLargeur, kHauteur});
  corps.setOrigin({kLargeur / 2.f, kHauteur});
  corps.setPosition({x_, pied_y_});
  corps.setFillColor(sf::Color(90, 200, 130));
  fenetre.draw(corps);
}
