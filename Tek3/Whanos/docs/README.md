# Whanos

## Introduction

Whanos est une initiative visant à proposer des images Docker flexibles, conçues pour prendre en charge divers langages de programmation et bibliothèques. Sa conception modulaire offre une adaptabilité aisée à de nouveaux langages ou bibliothèques, offrant une solution polyvalente pour différents projets. Toutes les configurations sont centralisées dans un fichier whanos.yml, facilitant la gestion via des variables d'environnement personnalisables.

Par ailleurs, Whanos propose une approche alternative : la création d'images personnalisées à partir d'une version autonome plutôt que de l'image de base. Cette flexibilité donne la liberté de personnaliser davantage les images selon les besoins spécifiques du projet.

Pour automatiser la détection du type de projet, la construction de l'image appropriée, ainsi que son déploiement sur le registre Docker et un cluster Kubernetes, Whanos s'appuie sur Jenkins. Cette automatisation garantit une gestion efficace du cycle de vie des images, offrant une solution intégrée pour le développement et le déploiement de projets divers.
