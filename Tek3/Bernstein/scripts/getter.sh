#!/bin/bash

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m'

echo "${BLUE}--- Nodes ---${NC}"
kubectl get nodes

echo "\n${BLUE}--- Configmap ---${NC}"
kubectl get configmap

echo "\n${BLUE}--- Services ---${NC}"
kubectl get services

echo "\n${BLUE}--- Pods ---${NC}"
kubectl get pods

echo "\n${BLUE}--- Deployments ---${NC}"
kubectl get deployments

echo "\n${BLUE}--- Ingress ---${NC}"
kubectl get ingress

echo "\n${BLUE}--- Persistent Volume ---${NC}"
kubectl get persistentvolume

