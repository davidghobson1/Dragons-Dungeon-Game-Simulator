Dragon's Dungeon Game Simulator

(For a summary of the behaviour of the Player and Item classes, please see the MorePlayerAndItemInfo.txt file in the 'documentation' directory.)

This program simulates heroes' travelling through a dungeon in an attempt to try to steal a sacred Emerald from the Dragon's lair at the opposite side of the dungeon. A diagram of the setup is shown below.

|-------------------------|
|                         |  
|B                        =  
|                        D= *  
|G                        =  
|                         |    
|-------------------------|
- diagram of the Dragon's Dungeon, with the lair on the right shown with the ='s, the Emerald (*), the Dragon (D), and the two heroes on the left (H and Q)

On the one side are the heroes, while on the other is the Dragon and the lair. To steal the Emerald, the heroes must traverse the dungeon and and make it inside the lair, all without dying or encountering the Dragon (who will roast them as a nice little snack if anyone happens to be found trying to steal the treasure). 

Along the way, heroes may encounter monsters whom they will have to fight, including Goblins, Orcs, and Dorcs (a Orc/Goblin hybrid), who spawn up around the lair. Scattered around the dungeon are also items to be collected. These include potions which can increase (or even decrease) a heroes health, and also pieces of stray armour that heroes can collect to increase their strength or armour stats. Many items, however, are rather double-edged swords... Since the goblins, orcs, and dorcs can also use many of them to boost their stats as well! 

When the game starts, the user is asked to enter a dimension for the dungeon (the board), as well as to choose a number of heroes to play. For each hero, the user can give them a name, the first letter of which, will serve as the hero's avatar which can be used to track their path through the dungeon. All heroes start out with a health of 15, but with their other stats, including their strength and armour, generated randomly at start-up. Heroes are then placed at random vertical positions at the start of the board, and between 11 and 30 items are then randomly generated and scattered throughout the dungeon. Items can be seen on the board through the '?' mark.

A sample dungeon after creation is given below, in the case of two heroes: Bilbo and Gandalf.

|-------------------------|
|    ?         ??       ? |  
|B??    ?           ?     =  
|               ?        D= *  
|G    ??    ?          ?  =  
|         ?               |    
|-------------------------|
- sample board creation. 'B' represents Bilbo, 'G' is Gandalf, 'D' is the Dragon, and '?' are the items

In each round, the heroes move one position to the right, and either up, down or straight, which is chosen randomly. The dragon (D) paces back and forth in front of the lair, and a monster spawns at the far right side of the dungeon with 60% probability. The monsters are also spawned at a random vertical position, with a random fighter type (either goblin, orc, or dorc), and move through the dungeon one position left at a time, either up, down, or straight (which is randomly selected). For fighters, if they happen to reach the entrance of the dungeon without being killed, they exit the dungeon continuing on their merry way, and never re-enter the dungeon. 

When a player encounters an item, they can collect it or leave it where it is, and when two players collide, they may choose to fight one another. Heroes and monsters/fighters never fight amongst themselves, and nor do dragons ever fight monsters. When heroes and fighters collide however, they deal damage to each other equal to their strength minus the opposing player's armour stat.  When a fighter dies, they are removed from the game, but when one of the heroes dies, their position is then permanently marked with the '+' character to mark the position of their grave. If heroes collide with the Dragon, they die instantly. The dragon, on the other hand, can never be killed.

Sample iterations of the game simulation are included below. The game continues until either one of the heroes makes it into the lair and this claims the Emerald, or until all of the heroes have died. 

|-------------------------|          |-------------------------|
|    ?         ??       ? |          |    ?         ??       ?g|  
|B??    ?           ?     =          | B?    ?           ?    D= 
|              ?         D= *  ->    |              ?          = *
|    ??    ?          ?   =          |    ??    ?          ?   =  
|G        ?               |          | G       ?               |    
|-------------------------|          |-------------------------|
- Bilbo finding an item on his first move!    
- A goblin spawning on the right                 

|-------------------------|          |-------------------------|
|    ?         ??       ?g|          |    ?         ??       g |  
| B?    ?           ?    D=          |  ?   ?           ?      = 
|               ?         = *  ->    |  B           ?         D= *
|     ??    ?         ?   =          |  G ??    ?          ?   =  
| G       ?               |          |         ?              o|    
|-------------------------|          |-------------------------|
- A goblin finding an item
- An orc spawning on the right 

|-------------------------|          |-------------------------|
|    ?         ??       g |          |    ?         ??      g  |  
|  ?    ?           ?     =          | ?    ?            ?    d= 
|  B            ?        D= *  ->    |  B           ?          = *
|  G  ??    ?         ?   =          |  G ??    ?          ?  D=  
|         ?              o|          |         ?             o |    
|-------------------------|          |-------------------------|
- A dorc spawning on the right 
				.
				.
				.
				.
|-------------------------|          |-------------------------|
|    ?            d       |          |    ?            d       |  
|  ?    ?           ?  d D=          |  ?    ?          ?  d  D=  
|            B g          = *  ->    |             +           = *
|               o     ?  g=          |            G  o     ?   =  
|         ?  G       g    |          |        ?              g |    
|-------------------------|          |-------------------------|
- Bilbo dying through a collision with a goblin
				.
				.
				.
				.
|-------------------------|          |-------------------------|
|    ?            d       |          |    ?        o           |  
|  ?    ?           ?  d D=          |  ?  d             d    D=  
|            F g          = *  ->    |g d        g +   o       = *
|               o     ?  g=          |        g                G  
|         ?  S       g    |          | o      ? d     g      g |    
|-------------------------|          |-------------------------|
- Gandalf claiming the Emerald!
