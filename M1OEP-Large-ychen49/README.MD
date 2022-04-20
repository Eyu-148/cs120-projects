# Open-Ended Project -- Module1
# Eyu Chen
This is a large open-ended project created by Eyu Chen for cs120. 

# Summary
This project is a really simple simulator of turn based RPG game. There are 3 classes to represent player, enemy and the combat process.
Player and Enemy classes gian multiple methods and fields to describe them better, and Fight class has function that requires objects from these 2 classes and simulate the combat in one turn.

# Any Known Bugs
By the time of submission, the program runs well. However, since the lack of time to test for every aspect, there might be some bugs inside even though they don't affect the building and running of the project. 
One known bug is that the value of player's damage will be increased by turns, while the damage for player should be a constant, which is 10.
I revised this by reset the damage to 10 before the loop of each turn. 

# Future Work
I hope I can work more on this project in the following modules if possible. As it's the first time to write a game with C++, there are many new things to learn. 
I want to try level-up function and maybe a trading system in this project, which means that I need more classes and methods to work with.

# Citation
To learn how to use enum and print the name directly, this post from stackOverflow https://stackoverflow.com/questions/43023678/setter-and-getter-method-for-enumerator-c

and this one for overloaded function https://stackoverflow.com/questions/47083328/operator-overloading-in-header-files-and-in-the-cpp-files helped me a lot. 

# Grade Justification
I am not sure the grade that I can receive because I am not confident with this project, and I didn't include struct requirement in it because I am still confused with it and need more time to learn about.
I don't have sufficient time working on it, so it might gain some errors that I didn't find. 