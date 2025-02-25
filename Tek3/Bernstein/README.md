# 🎶 Bernstein - Orchestrate Your Own Symphony of Containers

## 📌 Description
**Bernstein** is a DevOps project designed to deploy and manage a containerized web poll application using **Kubernetes**. The project involves orchestrating several microservices in a **multi-host cluster** and ensuring seamless communication between components using **Traefik** as a reverse proxy and load balancer.

The polling application consists of several components:
- **Poll**, a Flask web application that collects votes and pushes them into a Redis queue.
- **Redis**, a queue that holds the votes sent by the Poll application for the Worker to consume.
- **Worker**, a Java service that consumes votes from the Redis queue and stores them in a PostgreSQL database.
- **PostgreSQL**, a database that persistently stores the results of the poll.
- **Result**, a Node.js web application that fetches the results from the database and displays them.

## 🚀 Deployment
This project uses **Kubernetes** to deploy and manage all components across multiple hosts. The deployment is handled through YAML configuration files for each service.

### ▶️ Running the Deployment
Run the following commands to deploy the entire system:
```bash
kubectl apply -f cadvisor.daemonset.yaml
kubectl apply -f postgres.secret.yaml \
-f postgres.configmap.yaml \
-f postgres.volume.yaml \
-f postgres.deployment.yaml \
-f postgres.service.yaml
kubectl apply -f redis.configmap.yaml \
-f redis.deployment.yaml \
-f redis.service.yaml
kubectl apply -f poll.deployment.yaml \
-f worker.deployment.yaml \
-f result.deployment.yaml \
-f poll.service.yaml \
-f result.service.yaml \
-f poll.ingress.yaml \
-f result.ingress.yaml
kubectl apply -f traefik.rbac.yaml \
-f traefik.deployment.yaml \
-f traefik.service.yaml
```

Once deployed, you can access the following:
- Poll → `poll.dop.io:30021`
- Result → `result.dop.io:30021`
- Traefik dashboard → `localhost:30042`

## 🏗️ Architecture
The system is built using Kubernetes with the following components:

### 🏠 Load Balancer
- **Traefik**: A reverse proxy and load balancer managing the traffic for `poll.dop.io` and `result.dop.io`.

### 🧑‍💻 Databases
- **Redis**:
  - Version: `redis:5.0`
  - Exposes port `6379`
  - Not replicated
  - Always restarts
  - Does not use Traefik

- **PostgreSQL**:
  - Version: `postgres:12`
  - Exposes port `5432`
  - Persistent volume at `/var/lib/postgresql/data`
  - Uses environment variables:
    - `POSTGRES_HOST`
    - `POSTGRES_PORT`
    - `POSTGRES_DB`
    - `POSTGRES_USER`
    - `POSTGRES_PASSWORD`

### 📊 Services
- **Poll**:
  - Based on `epitechcontent/t-dop-600-poll:k8s`
  - Replicated once (2 instances)
  - Exposes port `80`
  - Traefik rule: `poll.dop.io`
  - Memory limit: `128M`
  - Environment variable: `REDIS_HOST`

- **Worker**:
  - Based on `epitechcontent/t-dop-600-worker:k8s`
  - Not replicated
  - Exposes no public port
  - Memory limit: `256M`
  - Environment variables:
    - `REDIS_HOST`
    - `POSTGRES_HOST`
    - `POSTGRES_PORT`
    - `POSTGRES_DB`
    - `POSTGRES_USER`
    - `POSTGRES_PASSWORD`

- **Result**:
  - Based on `epitechcontent/t-dop-600-result:k8s`
  - Replicated once (2 instances)
  - Exposes port `80`
  - Traefik rule: `result.dop.io`
  - Memory limit: `128M`
  - Environment variables:
    - `POSTGRES_HOST`
    - `POSTGRES_PORT`
    - `POSTGRES_DB`
    - `POSTGRES_USER`
    - `POSTGRES_PASSWORD`

### 📊 Monitoring
- **cAdvisor**:
  - Based on `google/cadvisor:latest`
  - Scheduled on all nodes
  - Exposes port `8080`
  - Always restarts

## 🔐 Security
- **Sensitive Data**: No sensitive data (e.g., passwords) should be stored in plain text.
- **Environment Variables**: Used to manage authentication to databases and services.
- **Kubernetes Secrets**: For storing database credentials securely.
- **Kubernetes ConfigMap**: For storing common environment variables.

## 🎯 Objective
Orchestrate a containerized web poll application using **Kubernetes** and ensure all components are managed efficiently using **Traefik** as a load balancer. The end result is a scalable, fault-tolerant, and automated deployment of a multi-service application.
