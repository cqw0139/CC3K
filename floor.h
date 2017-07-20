#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <vector>
#include <string>
#include "cell.h"
class floor
{
	std::vector<std::vector<cell>> theFloor;
	pc* person = nullptr;
    boss* bos = nullptr;
	int maxnpc = 0;
	int numnpc = 0;
	int maxpotion = 0;
	int numpotion = 0;
	int maxtreasure = 0;
	int numtreasure = 0;
	int merchanthostile = 0;
public:
//   boss* bos = nullptr;
    
    std::string action;
	// destructor for the class
	~floor();

	// clear the current floor
	void clearFloor();

	// get the type for the cell in r and c
	char gettype(int r, int c) const;

	// check the cell in r and c is occupied or not
	int isoccupied(int r, int c) const;

	// void setchartype(int r, int c);
	char getchartype(int r, int c) const;

	// get the room # for cell at row and column
	int getroom(int r, int c) const;

	// get the max num of npc
	int getmaxnpc() const;

	// get the current of npc
	int getnpc() const;

	// get the max num of potion
	int getmaxpotion() const;

	// get the current of potion
	int getpotion() const;

	// get the max num of potion
	int getmaxtreasure() const;

	// get the current of potion
	int gettreasure() const;

	// get the info at row r and col c
	info* getinfo(int r, int c) const;

	// get the move state of the cell at row r and column c
	bool getmove(int r, int c) const;

	// check the neighbour's type.
	void checkneighbour(int r, int c, int direction, char& ch, int& occ) const;

	// get the current pc position
	void getpcpos(int& x, int& y) const;

	// return the pc at the current floor
	pc* getpc() const;

	// initial a floor
	void init();

	void setpc(int r, int c, pc* p);

	// init a pc at r anc c with pointer p
	void initpc(int r, int c, pc* p);

	// add npc to row r and column c
	void addinfo(int r, int c, info* newinfo);

	// add stair
	void initstair(int r, int c);

	void changemhost();

	void resetmove(int r, int c);
    
    void MerchantStartAttack();

	// move the character to the given direction
	bool movechar(int direction);

	// randomly move npc to one of the 4 directions
	void movenpc(int r, int c, int direction);

	// move npc from the row r and col c
	void removeinfo(int r, int c);

	// change the move state of row r and column c
	void changemove(int r, int c);

	// person attack the npc
	void attacknpc(int r, int c);
    
    // npc attack the person
	void npcattack(int r, int c);

	// person use potion
	void usepotion(int r, int c);

	// person pick gold
	void pickgold(int r, int c);

	// record the current floor
	static int curFloor;
    
    void resetaction();
    
    void settype(int r, int c, char type);
    
    void setroom(int r, int c, int num);
    
    void initBasicMap();
    
    void setboss(boss* b);
    
	friend std::ostream &operator<<(std::ostream &out, floor &f);
    
};
#endif
