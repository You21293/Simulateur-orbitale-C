<div align="center">

# Simulateur orbital de satellites en C

**Explorer la mécanique orbitale en simulant des satellites autour de la Terre.**

</div>

---

## Aperçu du projet

Ce projet met en pratique la programmation en C et les bases de la mécanique spatiale. Il vise à modéliser le mouvement de satellites soumis à l’attraction gravitationnelle terrestre, puis à observer leurs trajectoires et leurs distances.

## Captures d’écran

| Simulation de satellites GPS | ISS et Hubble | Analyse des distances |
|:--:|:--:|:--:|
| <img src="Simulation%20SATRLINK%20GPS.png" alt="Simulation de satellites GPS" width="260"> | <img src="Donne%20GPS%20et%20Simulation%20ISS%20HUBBLE.png" alt="Données GPS et simulation de l’ISS et de Hubble" width="260"> | <img src="Analyse%20des%20distances.png" alt="Analyse des distances entre satellites" width="260"> |

## Ce que le projet illustre

- La gravitation universelle appliquée au mouvement orbital.
- La simulation de plusieurs satellites.
- La comparaison de scénarios impliquant des satellites GPS, l’ISS et Hubble.
- L’analyse de l’évolution des distances entre objets.

## Modèle physique

Dans le modèle gravitationnel à deux corps, l’accélération d’un satellite situé en position **r** par rapport au centre de la Terre s’écrit :

$$
\vec{a} = -\frac{\mu}{r^3}\,\vec{r}
$$

avec :

- $\vec{r}$ : vecteur position du satellite depuis le centre de la Terre ;
- $r = \lVert \vec{r} \rVert$ : distance au centre de la Terre ;
- $\mu = G M_{\mathrm{Terre}}$ : paramètre gravitationnel terrestre.

Le signe négatif indique que l’accélération est dirigée vers la Terre. La précision des résultats dépend des hypothèses physiques et de la méthode numérique utilisée.

## Utilisation

La commande de compilation, les paramètres d’entrée et les étapes de lancement ne sont pas encore documentés dans le dépôt. Ils restent à ajouter pour rendre le programme facile à reproduire sur une autre machine.

## Améliorations à prévoir

- Ajouter les prérequis et une commande de compilation vérifiée.
- Fournir un exemple d’entrée et la sortie attendue.
- Documenter la méthode d’intégration et le pas de temps.
- Comparer les résultats à des cas orbitaux de référence.

---

*Projet personnel d’apprentissage en mécanique orbitale et en programmation C.*