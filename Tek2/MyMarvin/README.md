# 🤖 My Marvin - Change Sides and Tame the Beast

---

## 🚀 Overview

**my_marvin** is a powerful Jenkins automation project that streamlines Continuous Integration and Continuous Deployment. By leveraging Jenkins Configuration as Code (JCasC) and Job DSL, my_marvin fully configures your Jenkins instance—setting up users, roles, and jobs—to automate your daily development tasks.

![Jenkins](https://upload.wikimedia.org/wikipedia/commons/e/e3/Jenkins_logo_with_title.svg)


---

## 🔧 Setup Guide

### 📂 Clone the Repository

1. Clone your my_marvin repository:

   ```bash
   git clone https://github.com/your-org/my_marvin.git
   cd my_marvin
   ```

2. Ensure the following critical files are present:
   - `my_marvin.yml` (Jenkins Configuration as Code)
   - `job_dsl.groovy` (Job DSL scripts)

### 🤖 Test Jenkins Instance

1. **Start Jenkins** using your preferred method (e.g., Docker, local installation). For example, using Docker:

   ```bash
   docker run -p 8080:8080 -v $(pwd)/my_marvin.yml:/var/jenkins_home/casc_configs/my_marvin.yml --name my_marvin-jenkins jenkins/jenkins:lts
   ```

2. **Configure Jenkins** to use the Configuration as Code plugin:
   - Point the plugin to your `my_marvin.yml` file.
   - Verify that Jenkins displays the system message:  
     *"Welcome to the Chocolatine-Powered Marvin Jenkins Instance."* 🍫

3. **Validate User Setup**: Confirm that the following users are configured with passwords provided via environment variables:
   - **Hugo** (`chocolateen`)
   - **Garance** (`vaugie_g`)
   - **Jeremy** (`i_dont_know`)
   - **Nassim** (`nasso`)

### 🛠️ Test Job DSL Scripts

1. Manually trigger the **SEED** job (located in the `Tools` folder) in your Jenkins instance.
2. Verify that:
   - A new job is created based on the parameters provided.
   - The job executes shell commands in sequence (e.g., `make fclean`, `make`, `make tests_run`, `make clean`).
3. Ensure that the **clone-repository** job functions correctly by cloning a repository and performing a workspace cleanup.

---

## 🌟 Project Description

my_marvin automates Jenkins configuration and job creation, ensuring a robust CI/CD pipeline. By using:
- **Jenkins** 🤖 for automation,
- **Configuration as Code** 📄 via `my_marvin.yml` to define global settings, users, and security,
- **Job DSL** 🖋️ via `job_dsl.groovy` to programmatically create and manage jobs,

the project guarantees a secure, maintainable, and fully automated Jenkins environment.

### Key Components

- **Jenkins** 🤖: The automation server powering your CI/CD.
- **Configuration as Code** 📄: A YAML file (`my_marvin.yml`) that fully configures Jenkins.
- **Job DSL** 🖋️: Groovy scripts (`job_dsl.groovy`) that create and manage jobs.
- **Security & Authorization** 🔒: Role-based permissions ensuring only the required access is granted.
- **Automated Jobs** 🔄: Predefined jobs like **clone-repository** and **SEED** that automate building and testing.

---

## 📂 Project Structure

- **my_marvin.yml**: Jenkins Configuration as Code file defining global settings, security, and users.
- **job_dsl.groovy**: Centralized Job DSL scripts for job creation.
- **docs/**: Documentation related to project setup and usage.
- **jenkins/**: Additional configuration files or scripts related to Jenkins deployment (if any).

---

## 🏆 Evaluation Criteria

- **Functionality** ✅: The Jenkins instance should configure and deploy jobs automatically.
- **Good Practices** 🧹: Clean, maintainable, and well-documented configuration and code.
- **Security** 🔐: All passwords must be managed via environment variables—no hardcoding.
- **Automation** 🤖: Efficient use of Configuration as Code and Job DSL to minimize manual configuration.
