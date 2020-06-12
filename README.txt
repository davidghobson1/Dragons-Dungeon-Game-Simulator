COMP2404 B - Take-Home Final Exam

Author: David Hobson (with concept and the random.cc file from Dr. Christine Laurendeau)
Student Number: 100853733

Purpose:
A game program simulating the journey of heros across the dangerous Dragon's Dungeon
as they seek to steal the sacred Emerald from the Dragon's cave. (Even as the Dragon and
many fighters and monsters stand in there way!)

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
Please run "make" from the command line in this directory and everything should compile nicely
The executable will be called "play"
Please run the program with the "./play" command, and with any luck, our heros will come out
with the Emerald!

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
