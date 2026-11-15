#include "niveau.h"

#include <SFML/Graphics.hpp>

#include "heros.h"

namespace {

const sf::Color kCouleurDeLaPierre(110, 110, 122);
const sf::Color kCouleurDuBord(70, 70, 80);

constexpr float kTailleDeLaSortie = 30.f;

}  // namespace

Niveau::Niveau() {
  sol_.setSize({800.f, 16.f});
  sol_.setPosition({0.f, 570.f});
  sol_.setFillColor(kCouleurDeLaPierre);
  sol_.setOutlineThickness(1.f);
  sol_.setOutlineColor(kCouleurDuBord);

  plateforme_a_.setSize({320.f, 16.f});
  plateforme_a_.setPosition({240.f, 370.f});
  plateforme_a_.setFillColor(kCouleurDeLaPierre);
  plateforme_a_.setOutlineThickness(1.f);
  plateforme_a_.setOutlineColor(kCouleurDuBord);

  plateforme_b_.setSize({260.f, 16.f});
  plateforme_b_.setPosition({40.f, 177.f});
  plateforme_b_.setFillColor(kCouleurDeLaPierre);
  plateforme_b_.setOutlineThickness(1.f);
  plateforme_b_.setOutlineColor(kCouleurDuBord);

  sortie_.setSize({kTailleDeLaSortie, kTailleDeLaSortie});
  sortie_.setPosition({150.f, 177.f - kTailleDeLaSortie});
  sortie_.setFillColor(sf::Color(240, 210, 90));
  sortie_.setOutlineThickness(1.f);
  sortie_.setOutlineColor(kCouleurDuBord);
}

void Niveau::Dessiner(sf::RenderWindow& fenetre) const {
  fenetre.draw(sol_);
  fenetre.draw(plateforme_a_);
  fenetre.draw(plateforme_b_);
  fenetre.draw(sortie_);
}

bool Niveau::PoseLeHeros(Heros& heros) const {
  if (Atterrit(heros, sol_)) {
    return true;
  }
  if (Atterrit(heros, plateforme_a_)) {
    return true;
  }
  if (Atterrit(heros, plateforme_b_)) {
    return true;
  }
  return false;
}

bool Niveau::Atterrit(Heros& heros, const sf::RectangleShape& plateforme) {
  const float gauche = plateforme.getPosition().x;
  const float droite = gauche + plateforme.getSize().x;
  const float haut = plateforme.getPosition().y;
  const float epaisseur = plateforme.getSize().y;

  if (heros.X() < gauche || heros.X() > droite) {
    return false;
  }
  if (heros.VitesseY() < 0.f) {
    return false;
  }
  if (heros.PiedY() >= haut && heros.PiedY() <= haut + epaisseur) {
    heros.PoserSur(haut);
    return true;
  }
  return false;
}

bool Niveau::EstSurLaSortie(const Heros& heros) const {
  const float gauche = sortie_.getPosition().x;
  const float droite = gauche + sortie_.getSize().x;
  const float pieds = sortie_.getPosition().y + sortie_.getSize().y;
  return heros.X() >= gauche && heros.X() <= droite && heros.PiedY() > pieds - 1.f &&
         heros.PiedY() < pieds + 1.f;
}
