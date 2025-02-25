# 🐳 Whanos - Automated Deployment Infrastructure

## 🚀 Overview

Whanos is a powerful infrastructure that allows developers to automatically deploy any application into a Kubernetes cluster simply by pushing to a Git repository. This project integrates Docker 🐳, Jenkins 🤖, and Kubernetes 🧑‍💻 to automate the process of containerizing and deploying applications based on the technologies specified in the repository.

---

## 🔧 Setup Guide

### Clone a Test Project

1. Download the zip containing the example test projects if you can acess to the Intranet (you can create yours) ➜ [Download Link](https://intra.epitech.eu/module/2023/B-DOP-500/MPL-5-1/acti-610014/project/file/whanos_example_apps.zip).
2. Clone a sample test project:

   ```bash
   cd tests/
   git clone https://github.com/Epi-Whanos/$-app.git
   cp jenkins/whanos.yml $-app/  # For full testing
   cd $-app
   touch Dockerfile  # For standalone testing
   ```

### 🐳 Test Docker Images

#### Base Image

1. Copy the base Dockerfile:

   ```bash
   cp -r ../../images/$/Dockerfile.base ./
   ```

2. Build the base image:

   ```bash
   sudo docker build -t whanos-base -f Dockerfile.base .
   ```

3. Run the base image:

   ```bash
   sudo docker run --name whanos-base-container whanos-base
   ```

4. Remove the container and image:

   ```bash
   sudo docker kill whanos-base-container
   sudo docker rm whanos-base-container
   sudo docker rmi whanos-base
   ```

#### Standalone Image

1. Build the image:

   ```bash
   cd ../../images/$/
   sudo docker build -t whanos -f Dockerfile .
   cd tests/$-app/
   ```

2. Remove the container and image:

   ```bash
   sudo docker kill whanos-container
   sudo docker rm whanos-container
   sudo docker rmi whanos
   ```

### 🤖 Test Jenkins Image

1. Build the Jenkins image:

   ```bash
   cd jenkins/
   sudo docker build -t whanos-jenkins-image .
   ```

2. Run the Jenkins image:

   ```bash
   docker run -p 8080:8080 -p 50000:50000 --name whanos-jenkins-container whanos-jenkins-image
   ```

3. Remove the Jenkins container and image:

   ```bash
   sudo docker kill whanos-jenkins-container
   sudo docker rm whanos-jenkins-container
   sudo docker rmi whanos-jenkins-image
   ```

For more information about the project, consult the detailed project documentation 📚.

---

## 🌟 Project Description

Whanos is a DevOps project that integrates Docker, Jenkins, and Kubernetes to automate the process of building, containerizing, and deploying applications. It fetches a Git repository, determines the technology stack, and containerizes the application into an image. The application is then pushed to a Docker registry and, if a `whanos.yml` file exists, deployed to a Kubernetes cluster.

### Key Components

- **Docker** 🐳: Used for containerizing applications.
- **Jenkins** 🤖: Automates the process of building and deploying applications.
- **Kubernetes** 🧑‍💻: Manages and orchestrates containerized applications.

The system automatically detects the type of application in the repository (C, Java, Python, JavaScript, or Befunge) and uses the appropriate Docker images to containerize and deploy the application.

---

## 💻 Supported Languages

- **C**: Uses GCC and Makefile for compilation.
- **Java**: Uses Maven for compilation and `app.jar` for execution.
- **JavaScript**: Uses Node.js and `package.json`.
- **Python**: Uses `pip` for dependency management.
- **Befunge**: A stack-based language with free compilation/execution.

---

## 🖼️ Image Specifications

Whanos uses two types of images:

1. **Standalone Images**: For applications that don’t require any additional configuration.
2. **Base Images**: For applications that need further configuration, with a custom Dockerfile referencing a Whanos base image.

---

## 🛠️ Jenkins Configuration

Whanos uses Jenkins for automating builds and deployments. The Jenkins setup includes:

- **Build Jobs**: For each supported language, a job builds the corresponding base image.
- **Link-Project Job**: Links a project to the Whanos infrastructure by creating a job that automatically builds and deploys the application when changes are detected.

---

## 🧑‍💻 Kubernetes Deployment

If a repository includes a `whanos.yml` file with deployment specifications, the application is deployed into a Kubernetes cluster. The deployment includes configurations such as replica count, resource needs, and port forwarding.

---

## 📂 Project Structure

- **images**: Contains Dockerfiles for each language (base and standalone images).
- **docs**: Project documentation.
- **jenkins**: Jenkins configuration files.
- **kubernetes**: Kubernetes deployment files.

---

## 🏆 Evaluation Criteria

The project will be evaluated based on:

- **Functionality** ✅: Does the system deploy applications correctly?
- **Good Practices** 🧹: Clean, maintainable, and well-documented code.
- **Redeployability** 🔄: The ability to easily redeploy the infrastructure.
