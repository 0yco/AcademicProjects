# Guide de test - Whanos

## Prendre un projet de test

- [Cloner le projet sur lequel tester le Whanos ➜](https://github.com/Epi-Whanos) (js | c | befunge | python | java)

- [Ou télécharger le zip qui contient des projets de test ➜](https://intra.epitech.eu/module/2023/B-DOP-500/MPL-5-1/acti-610014/project/file/whanos_example_apps.zip)

```bash
cd tests/
git clone https://github.com/Epi-Whanos/$-app.git
cp jenkins/whanos.yml $-app/ # Pour tester entièrement
cd $-app
touch Dockerfile # Pour tester avec Standalone
```


## Test Docker image

### Base image

```bash
cp -r ../../images/$/Dockerfile.base ./
```

- Build base image

```bash
sudo docker build -t whanos-base -f Dockerfile.base .
```

- Run base image

```bash
sudo docker run --name whanos-base-container whanos-base
```

- Supprimer le container et l'image

```bash
sudo docker kill whanos-base-container
sudo docker rm whanos-base-container
sudo docker rmi whanos-base
```



### Standalone image

- Build image

```bash
cd ../../images/$/
sudo docker build -t whanos -f Dockerfile .
cd tests/$-app/
```

- Supprimer le container et l'image

```bash
sudo docker kill whanos-container
sudo docker rm whanos-container
sudo docker rmi whanos
```

## Test Jenkins image

```bash
cd jenkins/
```

- Build image

```bash
sudo docker build -t whanos-jenkins-image .
```

- Run image

```bash
docker run -p 8080:8080 -p 50000:50000 --name whanos-jenkins-container whanos-jenkins-image
```

- Supprimer le container et l'image

```bash
sudo docker kill whanos-jenkins-container
sudo docker rm whanos-jenkins-container
sudo docker rmi whanos-jenkins-image
```

Pour plus d'informations sur le projet vous pouvez consulter la documentation du projets.