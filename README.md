# Platformer

Examen oral du module 1 — sujet **C**. Un platformer d'un seul écran, en fenêtre SFML.

## Ce que le jeu doit faire

Le héros est le **rectangle vert**. Il démarre sur le sol, en bas à gauche.

| Touche | Action |
|---|---|
| ← → | courir |
| Espace | sauter, seulement quand il a les pieds sur quelque chose |

Le niveau tient en **trois surfaces de pierre** — le sol, une plateforme à mi-hauteur, une
plateforme en haut à gauche — et une **porte jaune** posée sur la plateforme du haut.

La chute est gouvernée par la gravité : la vitesse verticale augmente à chaque image, puis
la position suit. **Le héros s'arrête sur une surface dès que ses pieds l'atteignent par le
dessus**, quelle que soit sa vitesse de chute. Il peut en revanche traverser une plateforme
par en dessous pendant qu'il monte.

La partie est gagnée quand le héros se tient sur la **porte jaune**.

## Le lancer

Dans **CLion** : ouvrir le dossier, laisser CLion configurer le projet (SFML est déclaré
dans `vcpkg.json`, le panneau *Vcpkg* s'en charge), puis *Build* et *Run* sur la cible
`platformer`.

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

Ce qui est noté, c'est l'entretien. `REPONSES.md` est une trace, pas un rendu : il ne
rapporte pas de points et ne peut pas t'en coûter. Attends-toi à devoir **dérouler** tes
réponses à la main — reproduire le problème à la demande, refaire un calcul au tableau, dire
ce que ta correction ne couvre pas.

## Ce que tu peux faire

Tout. Compiler, lancer, modifier le code, le casser, le réparer, ajouter des affichages.
**Internet et les assistants IA sont autorisés** pendant les 30 minutes.
