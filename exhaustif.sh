#!/bin/bash
SLEEP_TIME=0
CHECKER_OS=checker
if [ -z "$1" ]; then
	echo "Veuillez saisir une taille"
	read -r taille
  	set -- "$taille"
fi;
if ! [[ "$1" =~ ^-?[0-9]+$ ]];  then
    echo "$1 n'est un nombre."
    exit 1
fi;
if [ -n "$1" ] && [ "$1" -eq 1 ]; then
	ARG="57"; echo $ARG
	./push_swap $ARG | ./$CHECKER_OS $ARG
fi;
if [ -n "$1" ] && [ "$1" -eq 2 ]; then
	ARG="1 2"; echo $ARG  
	./push_swap $ARG | ./$CHECKER_OS $ARG
	ARG="2 1"; echo $ARG
	./push_swap $ARG | ./$CHECKER_OS $ARG
fi;
if [ -n "$1" ] && [ "$1" -eq 3 ]; then
	ARG="1 2 3"; echo $ARG
	./push_swap $ARG | ./$CHECKER_OS $ARG
	ARG="1 3 2"; echo $ARG
	./push_swap $ARG | ./$CHECKER_OS $ARG
	ARG="2 1 3"; echo $ARG
	./push_swap $ARG | ./$CHECKER_OS $ARG
	ARG="2 3 1"; echo $ARG
	./push_swap $ARG | ./$CHECKER_OS $ARG
	ARG="3 1 2"; echo $ARG
	./push_swap $ARG | ./$CHECKER_OS $ARG
	ARG="3 2 1"; echo $ARG
	./push_swap $ARG | ./$CHECKER_OS $ARG
fi;
if [ -n "$1" ] && [ "$1" -eq 4 ]; then
	ARG="1 2 3 4"; echo $ARG
	./push_swap $ARG
	ARG="1 2 4 3"; echo $ARG
	./push_swap $ARG
	ARG="1 3 2 4"; echo $ARG
	./push_swap $ARG
	ARG="1 3 4 2"; echo $ARG
	./push_swap $ARG
	ARG="2 1 3 4"; echo $ARG
	./push_swap $ARG
	ARG="2 1 4 3"; echo $ARG
	./push_swap $ARG
	ARG="2 3 1 4"; echo $ARG
	./push_swap $ARG
	ARG="2 3 4 1"; echo $ARG
	./push_swap $ARG
	ARG="2 4 3 1"; echo $ARG
	./push_swap $ARG
	ARG="2 4 1 3"; echo $ARG
	./push_swap $ARG
	ARG="3 1 2 4"; echo $ARG
	./push_swap $ARG
	ARG="3 1 4 2"; echo $ARG
	./push_swap $ARG
	ARG="3 2 1 4"; echo $ARG
	./push_swap $ARG
	ARG="3 2 4 1"; echo $ARG
	./push_swap $ARG
	ARG="3 4 1 2"; echo $ARG
	./push_swap $ARG
	ARG="3 4 2 1"; echo $ARG
	./push_swap $ARG
	ARG="4 1 2 3"; echo $ARG
	./push_swap $ARG
	ARG="4 1 3 2"; echo $ARG
	./push_swap $ARG
	ARG="4 2 1 3"; echo $ARG
	./push_swap $ARG
	ARG="4 2 3 1"; echo $ARG
	./push_swap $ARG
	ARG="4 3 1 2"; echo $ARG
	./push_swap $ARG
	ARG="4 3 2 1"; echo $ARG
	./push_swap $ARG
fi;
if [ -n "$1" ] && [ "$1" -gt 4 ]; then
	if ! [ -z "$2" ]; then
		./complexity $1 1000 $2 ./checker
		exit 1
	fi;
	if [ -z "$2" ]; then
		echo "Veuillez saisir une taille"
		read -r taille
		set -- "$taille"
	fi;
	if ! [[ "$taille" =~ ^-?[0-9]+$ ]];  then
		echo "$taille n'est un nombre."
		exit 1
	fi
	./complexity $1 1000 $taille ./checker
fi;
