Dragon's Dungeon Game Simulator

Author: David Hobson 
(Main concept and the random.cc file from Dr. Christine Laurendeau at Carleton University)

Summary:
A basic game program simulating heroes' quests to steal the sacred Emerald from the dangerous Dragon's Dungeon. Can they survive their journey across the dungeon to retrieve the Emerald, with monsters and the Dragon in their path??? Play to find out!! 

List of source and header files:

- main.cc
- Control.cc and Control.h
- View.cc and View.h
- BoardMap.cc and BoardMap.h
- Register.cc and Register.h

- Hero.cc and Hero.h
- Dragon.cc and Dragon.h
- Fighter.cc and Fighter.h
- Goblin.cc and Goblin.h
- Orc.cc and Orc.h
- Dorc.cc and Dorc.h
- Player.cc and Player.h
- Position.cc and Position.h

- Item.cc and Item.h
- Potion.cc and Potion.h
- HealthPotion.cc and HealthPotion.h
- WickedPotion.cc and WickedPotion.h
- Armour.cc and Armour.h
- Shield.cc and Shield.h
- Sword.cc and Sword.h

- Array2D.h
- List.h
- random.cc and random.h

Other files:
- Makefile
- README.txt

Compilation and Launch Instructions:
Run "make" from the command line in the main directory, and the executable will be called "play"
Run the program with "./play", and with any luck, your heros will come out with the Emerald!

Program overview: 
This program simulates heroes' travelling through a dungeon in an attempt to try to steal a sacred Emerald from the Dragon's lair at the opposite side of the dungeon. A diagram of the setup is shown below.

|-------------------------|
|                         |  
|F                        =  
|                        D= *  
|S                        =  
|                         |    
|-------------------------|
* diagram of the Dragon's Dungeon, with the lair on the right shown with the ='s, the Emerald (*), the Dragon (D), and the two heroes on the left (H and Q)

On the one side are the heroes, while on the other is the Dragon and the lair. To steal the Emerald, the heroes must traverse the dungeon and and make it inside the lair, all without dying or encountering the Dragon (who will roast them aa a nice little snack if anyone happens to be found trying to steal the treasure). 

Along the way, heroes may encounter monsters whom they will have to fight, including Goblins, Orcs, and Dorcs (a Orc/Goblin hybrid), who spawn up around the lair. Scattered around the dungeon are also items to be collected. These include potions which can increase (or even decrease) a heroes health, and also pieces of stray armour that heroes can collect to increase their strength or armour stats. May items, however, are rather double-edged swords... Since the goblins, orcs, and dorcs can also use many of them! 

When the game starts, the user is asked to enter a dimension for the dungeon (the board), as well as to choose a number of heroes to play. For each hero, the user can give them a name, the first letter of which, will serve as the hero's avatar which can be used to track their path through the dungeon. All heroes start out with a health of 15, but their other stats, including their strength and armour, are generated randomly at start-up. Heroes are then placed at random vertical positions at the start of the board, and between 11 and 30 items are then randomly generated and scattered throughout the dungeon. Items can be seen on the board through the '?' mark.

A sample dungeon after creation is given below, in the case of two heroes Frodo and Sam.

|-------------------------|
|    ?         ??       ? |  
|F??    ?           ?     =  
|               ?        D= *  
|S    ??    ?          ?  =  
|         ?               |    
|-------------------------|
- sample board creation. 'F' represents Frodo, 'S' is Sam, 'D' is the Dragon, and '?' are the items

In each round, the heroes move one position to the right, and either up, down or straight, which is chosen randomly. The dragon (D) paces back and forth in front of the lair, and a monster spawns at the far right side of the dungeon with 60% probability, and at a random vertical position, with a random fighter type (either goblin, orc, or dorc). Monsters/fighters always move one position to the left each turn, and also either up, down, or straight, which is randomly selected. If fighters happen to reach the entrance of the dungeon without being killed, they exit the dungeon continuing on their merry way, and never re-enter the dungeon. 

If a player encounters an item, they can collect it, and when two players collide, they may choose to fight one another. Heroes and monsters/fighters never fight amongst themselves, and nor do dragons ever fight monsters. Heroes and monsters/fighters, however will choose to fight one another and will deal damage equal to their strength minus the opposing player's armour stat.  When a fighter dies, they are removed from the game, but when one of the heroes dies, their position is then permanently marked with the '+' character to mark the position of their grave. If heroes collide with the Dragon, they die instantly. The dragon, however, can never be killed.

Sample iterations of the game are included below. The game continues until either one of the heroes makes it into the lair and this claims the emerald, or when all of the heroes die. 

|-------------------------|          |-------------------------|
|    ?         ??       ? |          |    ?         ??       ?g|  
|F??    ?           ?     =          | F?    ?           ?    D= 
|              ?         D= *  ->    |              ?          = *
|    ??    ?          ?   =          |    ??    ?          ?   =  
|S        ?               |          | S       ?               |    
|-------------------------|          |-------------------------|
- Frodo finding an item on his first move!
- A goblin spawning on the right

|-------------------------|          |-------------------------|
|    ?         ??       ?g|          |    ?         ??       g |  
| F?    ?           ?    D=          | ?    ?           ?      = 
|               ?         = *  ->    |  F           ?         D= *
|     ??    ?         ?   =          |  S ??    ?          ?   =  
| S       ?               |          |         ?              o|    
|-------------------------|          |-------------------------|
- A Goblin finding an item
- An orc spawning on the right 

|-------------------------|          |-------------------------|
|    ?         ??       ?g|          |    ?         ??       g |  
| F?    ?           ?    D=          | ?    ?           ?      = 
|               ?         = *  ->    |  F           ?         D= *
|     ??    ?         ?   =          |  S ??    ?          ?   =  
| S       ?               |          |         ?              o|    
|-------------------------|          |-------------------------|
- A Goblin finding an item
- An orc spawning on the right 


More details on Fighters and Items

My feature involves adding items into Dragon's Hollow which Players can collect and interact with
as they move through their quest.
On their journey, there are two different categories of items which Player's can find:
1) Potions, which Player's drink to affect their health
2) Armour, which Player's wear to boost their armour or strength

For Potions, Players can either find a Health Potion or a Wicked Potion. Health Potions help boost a
Hero's (Timmy/Harold's) health, and give them a boost of 1-4 health points (determined at Potion creation)
but only up to a maximum health of 15. Fighters (Borcs/Dorcs/Porcs) can't be bothered with Health Potions,
and so they don't pick them up, and just leave them there.
Wicked Potions are Health Potions in disguise. When a Hero drinks them, their health goes down by 1-2 points
(again, determined at Potion creation), and can kill a Hero if they're not careful! Fighters on the other hand,
love Wicked Potions, and they get a health boost of 1-2 points when they drink them, however only up to a maximum
health level of 10.

Also to be found within Dragon's Hollow are Armour items. Heroes can find Shields which help boost their armour level
by 1-3 points. They have to be careful though, because Fighters can also pick-up Shields which also boost their
armour level too! All Players armour attribute can only be raised to a maximum of 6.
Swords are another armour item found with the Hollow. Heros can pick up a new Sword to boost their strength level by
1-4 points up to a maximum of 10. Fighters, on the other hand, are dumb, and think that swords mean enemies. They
attack the swords and always end up damaging their own weapons, which decreases their strength by half of its
original value.

In general, Dragons are too epic for petty things like items, and so Dragons never touch any item they come across.

In terms of the implementation, all items derive from the Item class (abstract), and branch into the Potion class (abstract) and Armour class (also abstract). Potions are instantiated through the derived HealthPotion and WickedPotion classes of the Potion class, and all Armour is instantiated through the derived Shield and Sword classes of the Armour class.
Items of Dragon's Hollow are stored within the Control object as a 2-dimensional array of Item pointers (called
boardItems) which is analogous to the 2-dimensional array of chars used to display Dragon's Hollow. At each location
(x,y) in this 2D array, there is either an Item pointer pointing to the Item located at position (x,y), or a NULL
pointer indicating no Item is found there.

At startup, the Control object initializes it's collection of items (through its initializeBoardItems() member function) and selects 11-20 random locations in Dragon's Hollow, placing a random Item at each (distinct) location. Each Item has equal probability being a Health Potion, a Wicked Potion, a Sword, or a Shield, and the respective boost of each Item is generated randomly at Item creation.

Whenever a Player moves to a location, the Control object checks if there is an Item at that location. If so, the
Player's collectItem function is called which (polymorphically) determines how the Player wants to interact with the
Item (as described above).


Program architecture, and class overviews:

The program is divided into control, entity, user-interface (UI), and collection classes.

The overall program runs through main.cc, however Control is the class which manages and controls the program flow.

Control is responsible for moderating the different rounds, and keeps track of all current players and items which are each stored using a C++ STL list.

Register objects keep track of the players and items located at each location (Position) on the board. It stores these using two singly linked lists implemented in List.h.

The BoardMap class is responsible for retrieving the correct Register given a specific location (or Position object). It implements a hash map to do this, which uses an adapted hash function created by Matthew Szudnik from Wolfram Research Inc.

The View class handles the UI and the display board, the latter of which is implemented in the Array2D.h class which implements a template collection class representing a 2 dimensional array. The random class simply implements the random number generator function.

The rest of the classes are all entity classes representing the different player, and item types within the game. 
Please see the Players and Items document for more details.