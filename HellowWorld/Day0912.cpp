#include "Day0912.h"

void Day0912_Struct()
{
	Enemy Goblin;
	Goblin.Name = "���1ȣ";
	printf("�̸� : %s\n", Goblin.Name.c_str());
	printf("����� : %.1f\n", Goblin.Health);
	printf("���ݷ� : %.1f\n", Goblin.AttackPower);
	printf("���� : %d Gold\n", Goblin.DropGold);

	// 1. ��� �����Ҵ� �޾ƺ���(�ɹ� ���� 4���� �����ϱ�)
	// 2. �ٸ� ����ü ������(ex:������, ����, ��)
}
