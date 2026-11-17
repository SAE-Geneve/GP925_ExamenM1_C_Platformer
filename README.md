# Platformer

Examen oral du module 1 — sujet **C**. Un platformer d'un seul écran, en fenêtre SFML.

## Ce que le jeu doit faire

Le héros est le **rectangle vert**. Il démarre sur le sol de gauche.

Le niveau tient en quatre surfaces de pierre et une porte :

- le **sol de gauche**, où commence le héros, qui s'arrête au bord de la **fosse** ;
- une **plateforme à mi-hauteur**, au-dessus du sol de gauche ;
- une **longue plateforme en haut**, qui s'avance au-dessus de la fosse ;
- le **sol de droite**, de l'autre côté de la fosse, avec la **porte jaune** posée dessus.

La fosse est trop large pour être sautée : le seul chemin vers la porte passe par le haut —
monter de plateforme en plateforme, avancer au-dessus du vide, puis redescendre sur le sol de
droite.

La chute est gouvernée par la gravité : la vitesse verticale augmente à chaque image, puis la
position suit. **Le héros s'arrête sur une surface dès que ses pieds l'atteignent par le
dessus, quelle que soit sa vitesse de chute.** Il peut en revanche traverser une plateforme
par en dessous pendant qu'il monte.

Tomber au fond de la fosse ramène le héros au départ. La partie est gagnée quand il se tient
sur la porte jaune.

## Comment jouer

Lance la cible `platformer`. Une fenêtre **Platformer** s'ouvre : c'est là que tout se passe.
**Clique dedans** pour lui donner le focus, sinon le clavier va à la console et rien ne bouge.

| Touche | Action |
|---|---|
| ← → | courir |
| Espace | sauter, seulement quand il a les pieds sur quelque chose |

Le bandeau en haut de la fenêtre rappelle l'objectif ; la console tient le journal.

## Le lancer

Dans **CLion** : ouvrir le dossier, laisser CLion configurer le projet (SFML est déclaré dans
`vcpkg.json`, le panneau *Vcpkg* s'en charge), puis *Build* et *Run* sur la cible
`platformer`.

La police d'affichage est livrée avec le projet, dans `platformer/data/tuffy.ttf` — celle des
exemples SFML (Thatcher Ulrich, domaine public). CMake copie `data/` à côté de l'exécutable
à chaque build : le dossier de sortie s'emporte tel quel, rien à installer.

En ligne de commande :

```bash
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake
cmake --build build
```

## Ce qu'on te demande

**30 minutes seul avec ce dépôt**, puis **20 minutes d'entretien**. Tu prépares quatre
réponses, que tu notes dans `REPONSES.md` :

1. **Que fait ce jeu ?**
2. **Quel problème pose-t-il ? Quelle correction proposes-tu ?**
3. **Quelles améliorations proposes-tu ?**
4. Une question de **théorie**, posée à l'oral, écran fermé.

Ce qui est noté, c'est l'entretien. `REPONSES.md` est une trace, pas un rendu : il ne rapporte
pas de points et ne peut pas t'en coûter. Attends-toi à devoir **dérouler** tes réponses à la
main — reproduire le problème à la demande, refaire un calcul au tableau, dire ce que ta
correction ne couvre pas.

## Ce que tu peux faire

Tout. Compiler, lancer, modifier le code, le casser, le réparer, ajouter des affichages.
**Internet et les assistants IA sont autorisés** pendant les 30 minutes.
