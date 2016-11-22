#ifndef __FLOOR_H__
#define __FLOOR_H__
#include <vector>
#include "cell.h"
class floor
{
	std::vector<std::vector<cell>> theFloor;
public:
	char gettype(int r, int c) const;
	void init();
	bool isoccupied(int r, int c) const;
	void initpc(int r, int c, npc* p);
	//void setchartype(int r, int c);
	char getchartype(int r, int c) const;
	friend std::ostream &operator<<(std::ostream &out, const floor &f);
};
#endif