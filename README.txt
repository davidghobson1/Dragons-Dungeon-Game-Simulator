Dragon's Dungeon Game Simulator

Author: David Hobson 
(Main concept and the random.cc file from Dr. Christine Laurendeau at Carleton University)

Summary:
A basic game program simulating heroes' quests to steal the sacred Emerald from the dangerous Dragon's Dungeon. Can they survive their journey across the dungeon to retrieve the Emerald, 
with monsters and the Dragon in their path?!? Play to find out!! 

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


About: 
This program simulates heroes' travelling through the dungeon shown below, in an attempt to try to steal the sacred Emerald located inside the Dragon's lair at the opposite side of the dungeon. 

|-------------------------|
|                         |  
|H                        =  
|                        D= *  
|Q                        =  
|                         |    
|-------------------------|
* diagram of the Dragon's Dungeon, with the lair on the right shown with the ='s, the Emerald (*), the Dragon (D), and the two heroes on the left (H and Q)

Guarding the lair is the Dragon, pacing back and forth, guarding the loot. To steal the Emerald, the heroes must traverse the dungeon and enter the lair (shown with the ='s), all without dying, or encountering the Dragon (who will roast them for a nice little snack if anyone happens to be found trying to steal the treasure). 

Along the way, heroes may also encounter monsters including Goblins, Orcs, and Dorcs, who they will have to fight to continue on their mission. Monsters spawn up on the right of the dungeon, with the sole mission to destroy any heroes in their way.

Also along the path however, are useful items including potions, and bits of armour which the heroes can use to aid in their quests. Although these can be useful to the heroes, they can also be used by the monsters, and so they are somewhat of a double-edged sword.

The first few iterations of a sample execution of the program are shown below.

|-------------------------|
|    ?         ??       ? |  
|H ?    ?           ?     =  
|               ?        D= *  
|Q    ??    ?          ?  =  
|         ?               |    
|-------------------------|
- sample board creation

|-------------------------|
|    ?         ??       ?g|  
| H?    ?           ?    D=  
|              ?          = *  
|    ??    ?          ?   =  
| Q       ?               |    
|-------------------------|
- H collecting an item, and a goblin spawning

|-------------------------|
|    ?         ??       g |  
|  H    ?           ?     =  
|              ?         D= *  
|  Q ??    ?          ?   =  
|         ?              o|    
|-------------------------|
- goblin collecting an item
- orc spawning 

|-------------------------|
|    ?         ??      g  |  
|      ?           ?     d=  
|   H           ?         = *  
|    ??    ?          ?  D=  
|   Q     ?             o |    
|-------------------------|
- dorc spawning

|-------------------------|
|    ?         ??    g  d |  
|      ?           ?      =  
|    H          ?        D= *  
|    Q?    ?          ?o  =  
|         ?              g|    
|-------------------------|
- Q collecting an item
- another goblin spawning

and user chooses a number of Heroes to venture forth into the Dungeon to retrieve the Emerald. The user can choose the dungeon dimensions, as well as name their heroes, but the stats of the heroes are up to fate, and the program randomly generates their stats when created. 

The game 











Innovative feature:
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

Also to be found within Dragon's Hollow are Armour items. Heros can find Shields which help boost their armour level
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

All Items within Dragon's Hollow are represented by '?' on the display, and whenever a Player encounters an Item, a message appears describing the interaction (including what Item the Player found, what attribute is being affected, and by how much).
