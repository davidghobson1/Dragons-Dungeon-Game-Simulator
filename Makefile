CXX = g++
CXXFLAGS = -I ./include

VPATH = source include source/CollectionClasses source/Control source/GameObjects source/GameObjects/Players source/GameObjects/Players/Hero source/GameObjects/Players/Fighters source/GameObjects/Players/Dragon  source/GameObjects/Items  source/GameObjects/Items/Armour  source/GameObjects/Items/Potions source/Other source/UI

play: main.o BoardMap.o Register.o Position.o Item.o Armour.o Shield.o Sword.o Potion.o HealthPotion.o WickedPotion.o Control.o View.o Player.o Hero.o Dragon.o Fighter.o Orc.o Goblin.o Dorc.o random.o
	$(CXX) -o $@ $^

main.o: main.cc Control.h random.h List.h Array2D.h
	$(CXX) -c $< $(CXXFLAGS)

Control.o: Control.cc Control.h View.h BoardMap.h List.h Register.h Position.h Item.h Armour.h Shield.h Sword.h Potion.h HealthPotion.h WickedPotion.h Player.h Hero.h Dragon.h Fighter.h Goblin.h Dorc.h Orc.h Array2D.h random.h
	$(CXX) -c $< $(CXXFLAGS)

View.o: View.cc View.h
	$(CXX) -c $< $(CXXFLAGS)

BoardMap.o: BoardMap.cc BoardMap.h
	$(CXX) -c $< $(CXXFLAGS)

Register.o: Register.cc Register.h
	$(CXX) -c $< $(CXXFLAGS)

Sword.o: Sword.cc Sword.h Armour.h Item.h
	$(CXX) -c $< $(CXXFLAGS)

Shield.o: Shield.cc Shield.h Armour.h Item.h
	$(CXX) -c $< $(CXXFLAGS)

Armour.o: Armour.cc Armour.h Item.h
	$(CXX) -c $< $(CXXFLAGS)

WickedPotion.o: WickedPotion.cc WickedPotion.h Potion.h Item.h
	$(CXX) -c $< $(CXXFLAGS)

HealthPotion.o: HealthPotion.cc HealthPotion.h Potion.h Item.h
	$(CXX) -c $< $(CXXFLAGS)

Potion.o: Potion.cc Potion.h
	$(CXX) -c $< $(CXXFLAGS)

Item.o: Item.cc Item.h
	$(CXX) -c $< $(CXXFLAGS)

Goblin.o: Goblin.cc Goblin.h Fighter.h Player.h random.h
	$(CXX) -c $< $(CXXFLAGS)

Dorc.o: Dorc.cc Dorc.h Fighter.h Player.h random.h
	$(CXX) -c $< $(CXXFLAGS)

Orc.o: Orc.cc Orc.h Fighter.h Player.h random.h
	$(CXX) -c $< $(CXXFLAGS)

Fighter.o: Fighter.cc Fighter.h Player.h random.h
	$(CXX) -c $< $(CXXFLAGS)

Dragon.o: Dragon.cc Dragon.h Player.h
	$(CXX) -c $< $(CXXFLAGS)

Hero.o: Hero.cc Hero.h Player.h random.h
	$(CXX) -c $< $(CXXFLAGS)

Player.o: Player.cc Player.h Item.h
	$(CXX) -c $< $(CXXFLAGS)

Position.o: Position.cc Position.h
	$(CXX) -c $< $(CXXFLAGS)

random.o: random.cc random.h
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f *.o play
