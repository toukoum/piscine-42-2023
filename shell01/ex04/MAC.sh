#!/bin/bash 

ifconfig | awk '/ether/{print $2}'

#$2 pour le deuxieme champs de ether
