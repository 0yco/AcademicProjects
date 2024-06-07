# Gomuku

### Notes

- On ne joue que sur une petite partie du jeu, pas besoin de calculer sur tous le plateau, mais plutôt sur un périmètre rectangulaire englobant les pions (excepté les pions à des positions extrêmes)
- Il vaut mieux entouré la personne (surtout lors de la défensive) et de distancer le plus loin nos pions entre eux pour pouvoir avoir plus d'opportunités de contre-attaquer

### Defensive

- Si l'adversaire a 3 pions côte à côte et qu'il n'est pas bloqué à gauche ni à droite, alors il faut en poser un dans la direction des ses pions
- 3 pions n'est pas dangereux s'il est bloqué dans un des deux sens (on peut attendre encore un coup), alors on est **safe**
- Si malgré qu'un sens soit bloqué, mais qu'il peut avoir une 2 opportunité en un placement de pion, alors il faut le défendre (de préférence, il faut placer son pion sur la 5ème place plutôt que la 4ème)

### Offensive

- Si on est **safe**, alors on joue offensive
- Si on a aucune opportunité, placé des pions pas très loin de l'adversaire de manière espacé (et l'entourer si possible), jusqu'à qu'il est une opportunité de gagner en 1 ou 2 coups
- Si on à l'opportunité de placé un 4ème pion dans la même direction, alors il faut le placer à une position selon ces critères:
    1. Défendre s'il est à 1 coup tout en attaquant
    2. Créer deux opportunités ou plus
    3. Défendre s'il est à 2 coups tout en attaquant
    4. Mettre son pion là le plus proche de nos autres pions **non-gênés par l'adversaire**, sinon faire l'inverse, donc le plus loin de nos pions pour se débloquer

### Vocabulaire

- **Une opportunité**: avoir une occasion de terminer la partie en 1 ou 2 coups max
- **Un pion gêné**: Ceux qui sont **gênés** c'est ceux qui peuvent avoir plus aucune combinaison car l'adversaire les à déjà entouré
- **diff entre direction et sens**: sens haut-bas, bas-haut, donc direction verticale
- **un coup**: un tour où tu place ton pion