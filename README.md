# Welcome to My Mastermind
***my_mastermind is a game where you have to guess a secret 4 digit code, you have 10 attempts to guess the correct order of numbers
if you run out of attempts its game over! (wa-wa-wa). If you can guess before the 10 attempts is up, congrats youve won! YAY!
let the game begin.

## Task
Recreate a version of My Mastermind game.
Where you work with a secret code 4 digits long, as well as the ability to choose your own 4 digit secret code.
Player has 10 attempts to guess the order of digits in the secret code
If attempts has reached capacity without guessing the game ends.
If the player guesses the correct order of secret code they Win and game ends.


## Description
I wanted to organize my project to have easy readability and make it easier to debug, this though i wanted to organize all the functionality of my code 
into functions, each function would handle a "step" that happens in the game.(although there is a learning curve with this) 
I organized my code in a way where you could almost envision what was happening with my game when it was being played. 

Handling of ctrl+D : ctrl+d was handled in the get_user_input function, using bool values, oef is assumed false, once player calls eof
(using ctrl+D) eof is changed to true and exits function, ending player input. 

Handling -t flag(custom number of attempts) : checked if -t flag was detected in argv, stored the attempts as integer by converting from string input to
integer, converted integer is stored inside attempts variable, if no -t flag is detected, attempts in standard 10

Handling -c flag(custom secret code) : when -c is detected i iterate through my string, and then iterate through each char of the string, each char input
is converted to a digit and stored in secret_code array. If no -c flag is detected, computer generates secret_code.

The biggest challenges I had were handling ctrl+D, and wrapping my mind around the logic for comparing my userguess to the secretcode, as well as
the game flow, where i needed to put prompts and updates rounds/ attempts.





## Installation
TODO - in terminal >$ make 

You should see this message: 
gcc -Wall -Wextra -Werror -c my_mastermind.c 
gcc -Wall -Wextra -Werror -o my_mastermind my_mastermind.o 

your ready to play.



## Usage
To play with computer generated secret code: $>./my_mastermind
To play with your own code: $>./my_mastermind -c "your secret code"
To set custom number of attempts: $>./my_mastermind -t "custom number of attempts"
```
./my_mastermind 
./my_mastermind -c "1234"
./my_mastermind -t "12"

```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
