# 421
This program is an CLI implementation of the french game 421. It's a game played with 3 dice and tokens between 2-4 players.
At the beginning, everyone rolls a single dice to decide who will play first. Then the game is played in two parts : the charging and the discharging.
During the charging, each player rolls the dice. It gives combinations that indicate how many tokens the player gets. The goal in this part is to get as little as possible tokens.
The tokens are from the pot. Once the pot is empty, the discharging starts. This part is the same as the previous one.
But in this case, the tokens are exchanged between the player with the worst combination and the one with the best.
The winner is the first player with no more tokens.
The detailled rules are available [here](https://www.regles-de-jeux.com/regle-du-421/).

## In case of equality
If during the game many players got equivalent combinations, the last to roll the dice is considered either as the best or as the worst.
It means that, if for instance, 2 two players got the combinations 421, the last to roll the dice will be considered as the best.
By the way, if everybody got equivalent combinations, nobody loses or gets tokens.

## Prerequisites
Any C compiler.

## Install
  ### Clone the repository
  You can also download the .zip file. The goal is to make you get all the files.
  ### Compile the 421.c file
  Unix users
  ````bash
  gcc 421.c -o 421
  ````
  Windows users
  
  Run the corresponding command on your device.
## Usage
  ### Just run the file generated on the last step
  Unix users
  ````bash
  ./421
  ````
  Windows users
  
  Run the corresponding command on your device.

## License
  [MIT](https://choosealicense.com/licenses/mit/#)

## Copyright
Copyright © 2021 Jean-Wilfrid TOGNIBO
  
  
