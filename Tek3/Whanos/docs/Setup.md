## Setup

### Préréquis

- [Docker](https://docs.docker.com/get-docker/)
- [Jenkins](https://www.jenkins.io/doc/book/installing/)

### Explication des outils

**Jenkins :**

> Jenkins est un outil d'intégration continue open source qui facilite l'automatisation des tâches liées au développement logiciel. Il permet l'intégration, les tests et le déploiement automatisés, contribuant ainsi à accélérer le cycle de développement.

**Dockerfile :**

> Un Dockerfile est un script utilisé pour créer une image Docker. Il contient des instructions décrivant les étapes nécessaires à la construction de l'image, notamment la configuration de l'environnement, l'installation des dépendances et l'exécution des commandes spécifiques au projet.

**Docker Registry :**

> Un registre Docker est un dépôt centralisé qui stocke et gère les images Docker. Il permet aux développeurs de partager, distribuer et récupérer des images Docker en toute facilité. Docker Hub est l'un des registres publics les plus utilisés, mais il est également possible de déployer des registres privés pour un contrôle accru sur la distribution des images.

**Kubernetes :**

> Kubernetes est une plateforme open source de gestion d'orchestration de conteneurs. Elle automatise le déploiement, la mise à l'échelle et la gestion des applications conteneurisées. Kubernetes offre une orchestration robuste, permettant de déployer et de gérer efficacement des applications dans des environnements conteneurisés.

**Google Cloud :**

> Google Cloud est la plateforme cloud de Google, offrant une gamme complète de services cloud, notamment le calcul, le stockage, les bases de données, l'analyse de données et bien plus encore. Google Cloud propose également Kubernetes Engine, un service géré Kubernetes, simplifiant le déploiement et la gestion d'applications conteneurisées sur le cloud.



### Configuration

#### Jenkins

1. Créer un nouveau projet de type "Pipeline" et le nommer "whanos".
2. Dans la section "Pipeline", sélectionner "Pipeline script from SCM" dans la liste déroulante "Definition".
3. Dans la section "SCM", sélectionner "Git" dans la liste déroulante "SCM".
4. Dans la section "Repository URL", entrer l'URL du dépôt Git de Whanos :


#### Yaml file

1. Créer un fichier whanos.yml à la racine du projet.

2. Ajouter les configurations suivantes :

```yaml
jenkins:
  systemMessage: "Welcome to the Whanos Jenkins Instance."
  securityRealm:
    local:
      allowsSignup: false
      users:
        - id: "admin"
          name: "Admin"
          password: ${ADMIN_PASSWORD}

  authorizationStrategy:
    roleBased:
      roles:
        global:
          - name: "admin"
            description: "Whanos master"
            permissions:
              - "Overall/Administer"
            assignments:
              - "admin"

tool:
  git:
    installations:
      - name: git
        home: /usr/local/bin/git

jobs:
  - file: jobs.groovy

credentials:
  system:
    domainCredentials:
      - credentials:
          - usernamePassword:
              scope: GLOBAL
              id: "github"
              username: ${GITHUB_USERNAME}
              password: ${GITHUB_PASSWORD}
              description: "Github credentials"
```
