VPATH = source source/Collection source/Control source/GameObjects source/GameObjects/Players source/GameObjects/Players/Hero source/GameObjects/Players/Fighters source/GameObjects/Players/Dragon  source/GameObjects/Items  source/GameObjects/Items/Armour  source/GameObjects/Items/Potions source/Other source/UI includes

play: main.o BoardMap.o Register.o Position.o Item.o Armour.o Shield.o Sword.o Potion.o HealthPotion.o WickedPotion.o Control.o View.o Player.o Hero.o Dragon.o Fighter.o Orc.o Goblin.o Dorc.o random.o
	g++ -o $@ $^

main.o: main.cc Control.h random.h List.h Array2D.h
	g++ -c $< -I ./includes

Control.o: Control.cc Control.h View.h BoardMap.h List.h Register.h Position.h Item.h Armour.h Shield.h Sword.h Potion.h HealthPotion.h WickedPotion.h Player.h Hero.h Dragon.h Fighter.h Goblin.h Dorc.h Orc.h Array2D.h random.h
	g++ -c $< -I ./includes

View.o: View.cc View.h
	g++ -c $< -I ./includes

BoardMap.o: BoardMap.cc BoardMap.h
	g++ -c $< -I ./includes

Register.o: Register.cc Register.h
	g++ -c $< -I ./includes

Sword.o: Sword.cc Sword.h Armour.h Item.h
	g++ -c $< -I ./includes

Shield.o: Shield.cc Shield.h Armour.h Item.h
	g++ -c $< -I ./includes

Armour.o: Armour.cc Armour.h Item.h
	g++ -c $< -I ./includes

WickedPotion.o: WickedPotion.cc WickedPotion.h Potion.h Item.h
	g++ -c $< -I ./includes

HealthPotion.o: HealthPotion.cc HealthPotion.h Potion.h Item.h
	g++ -c $< -I ./includes

Potion.o: Potion.cc Potion.h
	g++ -c $< -I ./includes

Item.o: Item.cc Item.h
	g++ -c $< -I ./includes

Goblin.o: Goblin.cc Goblin.h Fighter.h Player.h random.h
	g++ -c $< -I ./includes

Dorc.o: Dorc.cc Dorc.h Fighter.h Player.h random.h
	g++ -c $< -I ./includes

Orc.o: Orc.cc Orc.h Fighter.h Player.h random.h
	g++ -c $< -I ./includes

Fighter.o: Fighter.cc Fighter.h Player.h random.h
	g++ -c $< -I ./includes

Dragon.o: Dragon.cc Dragon.h Player.h
	g++ -c $< -I ./includes

Hero.o: Hero.cc Hero.h Player.h random.h
	g++ -c $< -I ./includes

Player.o: Player.cc Player.h Item.h
	g++ -c $< -I ./includes

Position.o: Position.cc Position.h
	g++ -c $< -I ./includes

random.o: random.cc random.h
	g++ -c $< -I ./includes

clean:
	rm -f *.o play
