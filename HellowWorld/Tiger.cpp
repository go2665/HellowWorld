#include "Tiger.h"

void Tiger::Hunt()
{
	printf("[%s]가 사냥을 합니다.\n", Name.c_str());
	SetEnergy(Energy - 0.5f);
	printf("[%s] : 에너지가 50% 감소합니다.\n", Name.c_str());
}
