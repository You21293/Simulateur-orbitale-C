<div align="center">

# Simulateur orbital de satellites en C

### Mécanique orbitale · Satellites · Analyse des trajectoires

Un projet en C pour explorer le mouvement de satellites artificiels autour de la Terre.

[**Voir la présentation visuelle ↗**](https://you21293.github.io/Simulateur-orbitale-C/)

![Langage C](https://img.shields.io/badge/langage-C-5865F2)
![Mécanique orbitale](https://img.shields.io/badge/sujet-orbites-2E8B57)
![Simulation](https://img.shields.io/badge/projet-simulation-5de1e6)

</div>

---

## Aperçu

Le projet met en pratique les bases de la mécanique orbitale et la programmation en C. Les captures disponibles présentent des simulations de satellites GPS, des exemples impliquant l’ISS et Hubble, ainsi qu’une analyse de distances.

[Découvrir les captures et la présentation](https://you21293.github.io/Simulateur-orbitale-C/)

## Ce que montrent les simulations

- Plusieurs satellites artificiels autour de la Terre.
- Des scénarios autour des satellites GPS, de l’ISS et de Hubble.
- Une analyse de distances entre objets simulés.

## Modèle physique

L’attraction gravitationnelle fournit l’accélération centripète du modèle orbital. Pour un vecteur position $\vec r$ mesuré depuis le centre terrestre :

$$
\vec{a} = -\frac{\mu}{r^3}\,\vec{r}
$$

où $r=\lVert\vec r\rVert$ et $\mu=GM_{\mathrm{Terre}}$.

Les détails de l’intégration numérique et les paramètres employés doivent être lus avec le code source. Les images sont des sorties de simulation et ne constituent pas, à elles seules, une validation de précision orbitale.

## Captures d’écran

| Satellites GPS | ISS et Hubble | Analyse des distances |
|:--:|:--:|:--:|
| ![Simulation de satellites GPS](Simulation%20SATRLINK%20GPS.png) | ![Simulation de l’ISS et de Hubble](Donne%20GPS%20et%20Simulation%20ISS%20HUBBLE.png) | ![Analyse des distances](Analyse%20des%20distances.png) |

## Fichiers

Les sources et les images du projet sont disponibles dans ce dépôt. La page de présentation réunit les captures existantes dans une mise en page adaptée au navigateur et au mobile.

---

<div align="center">

Projet personnel d’apprentissage en mécanique orbitale et programmation C.

</div>