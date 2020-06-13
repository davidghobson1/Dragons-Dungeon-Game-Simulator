VPATH = source source/Collection source/Control source/GameObjects source/GameObjects/Players source/GameObjects/Players/Hero source/GameObjects/Players/Fighters source/GameObjects/Players/Dragon  source/GameObjects/Items  source/GameObjects/Items/Armour  source/GameObjects/Items/Potions source/Other source/UI includes

play: main.o BoardMap.o Register.o Position.o Item.o Armour.o Shield.o Sword.o Potion.o HealthPotion.o WickedPotion.o Control.o View.o Player.o Hero.o Dragon.o Fighter.o Orc.o Goblin.o Dorc.o random.o
	g++ -o $@ $^

main.o: main.cc Control.h random.h List.h Array2D.h
	g++ -c $< -I ./include

Control.o: Control.cc Control.h View.h BoardMap.h List.h Register.h Position.h Item.h Armour.h Shield.h Sword.h Potion.h HealthPotion.h WickedPotion.h Player.h Hero.h Dragon.h Fighter.h Goblin.h Dorc.h Orc.h Array2D.h random.h
	g++ -c $< -I ./include

View.o: View.cc View.h
	g++ -c $< -I ./include

BoardMap.o: BoardMap.cc BoardMap.h
	g++ -c $< -I ./include

Register.o: Register.cc Register.h
	g++ -c $< -I ./include

Sword.o: Sword.cc Sword.h Armour.h Item.h
	g++ -c $< -I ./include

Shield.o: Shield.cc Shield.h Armour.h Item.h
	g++ -c $< -I ./include

Armour.o: Armour.cc Armour.h Item.h
	g++ -c $< -I ./include

WickedPotion.o: WickedPotion.cc WickedPotion.h Potion.h Item.h
	g++ -c $< -I ./include

HealthPotion.o: HealthPotion.cc HealthPotion.h Potion.h Item.h
	g++ -c $< -I ./include

Potion.o: Potion.cc Potion.h
	g++ -c $< -I ./include

Item.o: Item.cc Item.h
	g++ -c $< -I ./include

Goblin.o: Goblin.cc Goblin.h Fighter.h Player.h random.h
	g++ -c $< -I ./include

Dorc.o: Dorc.cc Dorc.h Fighter.h Player.h random.h
	g++ -c $< -I ./include

Orc.o: Orc.cc Orc.h Fighter.h Player.h random.h
	g++ -c $< -I ./include

Fighter.o: Fighter.cc Fighter.h Player.h random.h
	g++ -c $< -I ./include

Dragon.o: Dragon.cc Dragon.h Player.h
	g++ -c $< -I ./include

Hero.o: Hero.cc Hero.h Player.h random.h
	g++ -c $< -I ./include

Player.o: Player.cc Player.h Item.h
	g++ -c $< -I ./include

Position.o: Position.cc Position.h
	g++ -c $< -I ./include

random.o: random.cc random.h
	g++ -c $< -I ./include

clean:
	rm -f *.o play
