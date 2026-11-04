# Simulateur orbital de satellites en C

Un simulateur pédagogique de mécanique orbitale qui modélise le mouvement de satellites autour de la Terre à partir de la gravitation universelle.

Le projet explore notamment la simulation de plusieurs objets, l’utilisation de paramètres orbitaux et l’analyse des distances entre satellites. Il est écrit en C.

## Aperçu

### Simulation de satellites GPS

![Simulation de satellites GPS](Simulation%20SATRLINK%20GPS.png)

### Comparaison avec l’ISS et Hubble

![Données GPS et simulation de l’ISS et de Hubble](Donne%20GPS%20et%20Simulation%20ISS%20HUBBLE.png)

### Analyse des distances

![Analyse des distances entre satellites](Analyse%20des%20distances.png)

## Objectifs

- Mettre en pratique la loi de la gravitation universelle.
- Simuler les trajectoires de satellites autour de la Terre.
- Comparer les résultats du modèle avec des satellites réels.
- Étudier l’évolution des distances entre objets.

## Contenu du dépôt

Les captures d’écran ci-dessus montrent des exemples de simulations et d’analyses produites par le projet. Le code source et ses fichiers d’entrée se trouvent dans le dépôt.

## Utilisation

Le dépôt ne documente pas encore la commande de compilation ni les paramètres d’entrée. Pour lancer le programme, consulte le code source et les éventuels fichiers de données associés. Une prochaine étape utile sera d’ajouter une commande de compilation reproductible ainsi qu’un exemple complet d’exécution.

## Modèle physique

Le simulateur s’appuie sur la gravitation universelle. Pour un satellite de masse (m) situé à une distance (r) du centre de la Terre, l’accélération gravitationnelle idéale est :

[
\vec{a} = -\frac{\mu}{r^3}\vec{r}
]

où (\mu = GM_{\mathrm{Terre}}) est le paramètre gravitationnel terrestre et (\vec{r}) le vecteur position du satellite par rapport au centre de la Terre.

Les résultats dépendent des hypothèses et de la méthode numérique employées par le programme. Les captures illustrent les sorties du projet ; elles ne constituent pas à elles seules une validation de précision orbitale.

## Pistes d’amélioration

- Documenter les prérequis, la compilation et l’exécution pas à pas.
- Ajouter un jeu de paramètres d’exemple et les résultats attendus.
- Préciser le schéma d’intégration numérique et son pas de temps.
- Ajouter des tests sur des cas orbitaux connus et vérifier la conservation de l’énergie.
- Décrire les limites du modèle, par exemple l’absence éventuelle de perturbations orbitales.

## Auteur

Projet personnel d’apprentissage en mécanique orbitale et en programmation C.
