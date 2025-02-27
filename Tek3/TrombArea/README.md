# 🌐 TrombArea - Automate Your Digital Life

---

## 🚀 Overview

**TrombArea** is an automation platform that empowers you to streamline your digital life by connecting various services in custom workflows—similar to IFTTT or Zapier. This platform consists of an application server, a web client, and a mobile client, which work together to offer a seamless automation experience through a REST API. 🤖🔄


![TrombArea](./README/1_Login.jpg)
![Applets](./README/2_Applets.png)
![Marketplace](./README/3_Marketplace.png)
![History](./README/4_History.png)
![Profile](./README/5_Profile.png)
![Profile Web](./README/6_Profile_Web.png)

---

## 📖 Project Description

### 1. The Project

The goal of TrombArea is to explore and implement a complete software platform by developing a business application. You will create a suite of software that functions similarly to IFTTT/Zapier, divided into three main parts:

- **Application Server**: Implements all the business logic and features.
- **Web Client**: Provides a user interface accessible via a web browser that communicates with the server.
- **Mobile Client**: Offers mobile access to the application via REST API calls.

*Note: No business processes are executed on the web or mobile clients; they serve solely as user interfaces redirecting requests to the application server.*

### 2. Features

TrombArea offers the following functionalities:

- **User Registration**: Users sign up to create an account.
- **Account Confirmation**: Registered users confirm their accounts before using the application.
- **Service Subscription**: Authenticated users subscribe to various services.
- **Components per Service**:
  - **Action Components**: Trigger events (e.g., new email received, file uploaded).
  - **REAction Components**: Define responses (e.g., save attachment, post message).
- **AREA Creation**: Users compose custom workflows by linking an Action with a REAction.
- **Automatic Triggers**: The application automatically triggers workflows based on predefined conditions.

---

## 🔐 Authentication / Identification

To use the application, users must be properly identified. TrombArea supports:

- **Username/Password Authentication**: Clients submit credentials to the server.
- **OAuth2 Identification**: Clients can authenticate via third-party services (e.g., Google, Facebook) and notify the server upon success.

Ensure that third-party accounts are linked to system user accounts.

---

## 🔧 Setup Guide

### 📦 Docker Compose Deployment

TrombArea is containerized using Docker Compose. Ensure Docker and Docker Compose are installed, then execute:

```bash
docker-compose build
docker-compose up
```

**Services Deployed:**

- **Server Service**: Runs the application server on port **8080**.
- **Client_Mobile Service**: Builds the mobile client.
- **Client_Web Service**: Launches the web client on port **8081** (depends on both the server and mobile client).

The server exposes endpoints such as `http://localhost:8080/about.json` for service details, and the web client serves assets like the Android APK at `http://localhost:8081/client.apk`.

---

## 💻 Functions & API

### Core Functions

- **User Management**: Registration, account confirmation, and administration.
- **Service Subscription**: Users link their accounts to external services.
- **Action & REAction Execution**: Custom workflows trigger responses based on events.
- **Real-Time Triggering**: The server continuously monitors for conditions to activate workflows.

### API Example

**GET** `http://localhost:8080/about.json`
_Response:_
```json
{
  "client": { "host": "YOUR_CLIENT_IP" },
  "server": {
    "current_time": 1531680780,
    "services": [
      {
        "name": "facebook",
        "actions": [
          { "name": "new_message_in_group", "description": "A new message is posted in a group" },
          { "name": "new_message_inbox", "description": "A new private message is received" },
          { "name": "new_like", "description": "The user gains a like on a message" }
        ],
        "reactions": [
          { "name": "like_message", "description": "The user likes a message" }
        ]
      }
    ]
  }
}
```

Refer to the full API documentation for further details.

---

## 🏗️ Architecture & Technology Choices

### Architecture Overview

- **Application Server**: Hosts the business logic, provides a REST API, and manages workflows.
- **Web Client**: User interface for desktop access.
- **Mobile Client**: Mobile-friendly interface, sharing common volumes with the web client.

### Technology Choices

#### Backend:
- **NodeJS (TypeScript)**: Chosen for its simplicity, widespread use, and ease of integration.

#### Frontend:
- **Flutter**: Preferred for its cross-platform capabilities and seamless integration with Firebase.

*Other options considered include Rust, Python (FastAPI), and Java, but NodeJS and Flutter best meet our requirements.*

---

## 📝 Project Construction

- **Docker Compose**:
  A `docker-compose.yml` file orchestrates all services.
- **Volume Sharing**:
  The mobile and web clients share a common volume for resource synchronization.
- **Makefile**:
  Use the provided Makefile for building, cleaning, and maintaining the project.

---

## 🏆 Evaluation Criteria

TrombArea will be evaluated based on:

- **Integration & Functionality**: Smooth interaction between server, web, and mobile clients.
- **User Experience**: Intuitive interfaces and adherence to accessibility standards.
- **Automation Efficiency**: Accurate and timely execution of triggers and workflows.
- **Code Quality & Documentation**: Clean, maintainable code with comprehensive documentation.

---

## 🎨 Presentation

*This section is reserved for visual presentations. Add screenshots of the application, website, and Firebase configuration here to showcase the UI and infrastructure.*

---

## 👥 Contributors

- WilliamAndreo
- 0yco
- LunnosMp4
- ?
- ArnauldT
