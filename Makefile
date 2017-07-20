CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = cc3k -lncurses
OBJECTS = main.o cell.o dragon.o drow.o dwarf.o elf.o floor.o goblin.o halfling.o human.o merchant.o npc.o pc.o orc.o shade.o troll.o vampire.o bonuscontrol.o BA.o BD.o info.o PH.o potion.o RH.o WA.o WD.o dragonT.o treasure.o smallT.o merchantT.o humanT.o skill.o shadenative.o vampirenative.o deathknight.o saber.o drownative.o goblinnative.o boss.o trollnative.o bloodrage.o handofMidas.o grow.o poisonbody.o luckyseven.o deathknative.o frostmourne.o invisibleair.o excalibur.o print.o control.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
