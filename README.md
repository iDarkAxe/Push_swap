# Push_swap #

Push_Swap is a sorting algorithm that uses two stacks, to sort one. 
It has multiple instructions, that cannot be modified so all algorithms uses the sames.
It works pretty well for 500+ numbers. You can try [Complexity, a Push_Swap tester](https://github.com/SimonCROS/push_swap_tester) for optimal testing.

For array of numbers less than 10, it's using a simple algorithm that search lowest numbers and stores them until there is only 4 numbers. It tidies them and pushes back the number from the second stack in the first. TADAA it WORKS.

For larger arrays, it uses a tweaked Radix Algorithm to work with negatives. It's not the fastest, not the prettiest but it's perfect for repetitive tasks as it performs each time exactly the same. The number of instructions is always the same for a fixed number of elements.

## Usage ##
The array of numbers can be both positive and negative numbers, up to MAX INT and MIN INT of your device (tested from a range of -2147483648 up to 2147483647).
The input should be perfect as any error of typing should be rejected.

"12 54 6 879 -9812 03123 -23545" is valid.

"4189 897- 15-46 notAnumber 47889" is invalid.

It should contain no letters, no special characters or anything that is not a number OR minus and plus character (+ and - is OK).

### Push_Swap ###
You can use $ARG or type directly your stack.
If you want to store the result, you can use
```sh
./push_swap $ARG
```
``$ARG`` can be a string or an array of string
```sh
ARG="1 2 4 3"
```
or 
```sh
ARG=""1" "2" "4" "3""
```
### Checker ###
The checker is used to determine if the result of Push_swap is True or False.
As the checker uses the same functions of push_swap, it's pretty impossible to find a flaw in one and not in the other.
Notes : this checker is performing faster as the one given in the exercise !
Checker needs the same $ARG as Push_Swap but needs a list of instructions in stdin.
```sh
./checker $ARG < PUSH_SWAP_RESULT
```
You can also use a pipe :
```sh
./push_swap $ARG | ./checker $ARG
```
## Compilation ##

Compiled on WSL Kali on Windows 10 but should work with your own compiler.
Use ``make`` for compiling push_swap
```sh
make
```
Use ``make checker`` for compiling checker
```sh
make checker
```

0 leak, 0 bug found at this moment.

---

# Push_swap #

Push_Swap est un algorithme de tri qui utilises des piles, et qui les tries.
Il y a un set d'instructions définies, et qui doivent être utilisées lors du tri.
L'algorithme de tri fonctionne plutôt bien pour les groupes de + de 500 nombres. Vous pouvez essayer sur [Complexity, a Push_Swap tester](https://github.com/SimonCROS/push_swap_tester) pour des tests en profondeur.

Pour les listes de nombres de moins de 10 éléments, on utilise un simple algorithme qui recherche les nombres les plus petits et les rangent dans la seconde pile jusqu'à ce qu'il n'en reste que 4. Ensuite il range les 4 derniers et récupère dans l'ordre les nombres de la seconde pile. TADAA ça marche !

Pour les listes plus longues, on utilise un algorithme Radix amélioré pour fonctionner avec des négatifs. Le Radix n'est pas le plus rapide, ni le plus beau mais il est diablement pratique pour des tâches répétitives où prédire le nombre d'instruction est nécessaire. C'est idéal car le temps d'exécution est constant pour un nombre fixe d'éléments dans la liste.

## Utilisation ##
La liste de nombres peut contenir des nombres positifs et négatifs, jusqu'à la valeur maximale et minimale d'un entier de votre machine (testé avec une intervalle de -2147483648 à 2147483647).
L'entrée doit respecter toutes les règles car tout type d'erreur devrait être rejeté par le programme.

"12 54 6 879 -9812 03123 -23545" est valide.

"4189 897- 15-46 notAnumber 47889" est invalide.

Il ne devrait pas y avoir de lettres, ni de caractères spéciaux ou n'importe lequel autre caractère qui n'est pas un nombre ni le symbole + et -.

### Push_Swap ###
Vous pouvez utiliser une variable ou écrire directement la première pile.
Si vous voulez sauvegarder le résultat, vous pouvez utiliser :
```sh
./push_swap $ARG
```
``$ARG`` peut être une chaîne de caractères ou un assortiement de chaînes.
```sh
ARG="1 2 4 3"
```
ou
```sh
ARG=""1" "2" "4" "3""
```
### Checker ###
Le checker est utilisé pour déterminer si le résultat de Push_swap est bon ou mauvais.
Comme le checker utilises les mêmes fonctions que Push_Swap, il est quasiment impossible de trouver une faille dans l'un des programmes qui ne soit dans l'autre.
Notes : ce checker est plus performant que celui donné dans l'exercise !
Checker a besoin de la même variable $ARG que Push_Swap car il attends la liste des instructions sur l'entrée standard.
```sh
./checker $ARG < PUSH_SWAP_RESULT
```
Vous pouvez aussi utiliser un pipe (tuyau de redirection) :
```sh
./push_swap $ARG | ./checker $ARG
```
## Compilation ##

Compilation testée sur WSL2 Kali-Linux sur Windows 10 et sur Ubuntu (on a intel Mac) mais il devrait fonctionner partout.
Utilisez ``make`` pour compiler Push_Swap
```sh
make
```
Utilisez ``make checker`` pour compiler le checker
```sh
make checker
```

0 leak et 0 bug trouvé à ce jour.
