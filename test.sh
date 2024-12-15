#!/bin/sh

did=false
HELP_MESSAGE="Variables autorisées : f, c, d, t et --help"

case $1 in *"f"*) make fclean; did=true;;
	*) ;;
esac
case $1 in *"c"*) make; did=true;;
	*) ;;
esac
case $1 in *"d"*) make debug; did=true;;
	*) ;;
esac
case $1 in *"t"*) ./push_swap -5 -4 -3 -2 -1 0 1 2 3 4 5; did=true;;
	*) ;;
esac
case $1 in *"h"*) echo "$HELP_MESSAGE"; did=true;;
	*) ;;
esac
if [ "${1:-}" = "--help" ] || [ "${2:-}" = "--help" ]; then
	echo "$HELP_MESSAGE"; did=true
fi
if ! $did; then
    echo "Aucune condition remplie."
	echo "$HELP_MESSAGE"
fi
