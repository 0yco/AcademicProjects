# 🐙 Octopus - Automated Machine Management

## 📌 Description
**Octopus** is a DevOps project designed to **deploy and configure** a polling application across multiple machines using **Ansible**. Instead of manually setting up each machine, **Octopus** automates service installation and ensures efficient resource management.

The polling application consists of several components:
- **A Flask web client** to collect votes.
- **A Redis server** to store votes in a queue.
- **A Java worker** to process votes and send them to a database.
- **A PostgreSQL database** to store results.
- **A Node.js web client** to display the counted votes.

## 🚀 Deployment
The entire infrastructure is deployed across **5 separate machines**, without containerization, using **Ansible** only.

### ▶️ Running the Playbook
Run the following command to execute the deployment:
```bash
export ANSIBLE_VAULT_PASSWORD_FILE=/tmp/.vault_pass
echo "verySecretPassword" > /tmp/.vault_pass
ansible-playbook -i production playbook.yml
```
The `production` inventory ensures that machines are properly accessible and configured.

## 🏗️ Architecture
The project follows a modular architecture with **six Ansible roles**:

### 🏠 Base
➡️ Installs and configures essential packages (e.g., Git) for all machines.

### 🔴 Redis
➡️ Installs and sets up **Redis** to manage the vote queue.

### 🐘 PostgreSQL
➡️ Installs **PostgreSQL 12**, creates the `paul` database, and sets up a secure `paul` user.

### 📊 Poll
➡️ Deploys the **poll** service to collect votes (Flask).

### ⚙️ Worker
➡️ Deploys the **worker Java service**, which retrieves votes and stores them in the database.

### 📢 Result
➡️ Deploys the **result service** to display voting results (Node.js).

## 🔐 Security
- **No sensitive data** (e.g., passwords) should be stored in plain text in the repository.
- Authentication to databases and services is handled through **environment variables**.
- All machines operate as **normal users** with limited `sudo` access.

## 🎯 Objective
Streamline the management and deployment of a **multi-machine** infrastructure efficiently and effortlessly using **Ansible automation**.
