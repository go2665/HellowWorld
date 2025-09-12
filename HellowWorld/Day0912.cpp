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
	Enemy* pGoblin = new Enemy();
	pGoblin->Name = "���2ȣ";
	pGoblin->Health = static_cast<float>(rand() % 100 + 50);	// 50~150
	pGoblin->AttackPower = static_cast<float>(rand() % 10 + 5);	// 5~15
	pGoblin->DropGold = static_cast<int>(pGoblin->Health * pGoblin->AttackPower);
	PrintEnemy(pGoblin);
	delete pGoblin;
	pGoblin = nullptr;
	
	// 2. �ٸ� ����ü ������(ex:������, ����, ��)
	Weapon Sword;
	Sword.Name = "��ö��";
	Sword.Desc = "ưư�ϴ�.";
	Sword.AttackPower = 15.0f;
	Sword.Price = 200;

	//Enemy Goblins[3];
	Enemy* Goblins = nullptr;
	Goblins = new Enemy[3];
	for (int i = 0; i < 3; i++)
	{
		// std::to_string : ���ڿ��� �ƴѰ��� string���� �������ִ� �Լ�
		Goblins[i].Name = "���" + std::to_string(i + 1) + "ȣ";	
		PrintEnemy(&Goblins[i]);
	}
	delete[] Goblins;
	Goblins = nullptr;

	Enemy NamedGoblin("�ǽ� ���");
	PrintEnemy(&NamedGoblin);

	Enemy* pModiGoblin = new Enemy("��� ���", 5.0f);
	PrintEnemy(pModiGoblin);
	delete pModiGoblin;
	pModiGoblin = nullptr;

	Enemy CopyGoblin(NamedGoblin);	// ���� ������
	PrintEnemy(&CopyGoblin);

}

void Day0912_OperatorOverloading()
{
	Enemy Goblin1("���1ȣ");
	Enemy Goblin2("���2ȣ");

	Enemy FusionGoblin = Goblin1 + Goblin2;
	PrintEnemy(&FusionGoblin);
}

void PrintEnemy(const Enemy* pEnemy)
{
	printf("�̸� : %s\n", pEnemy->Name.c_str());
	printf("����� : %.1f\n", pEnemy->Health);
	printf("���ݷ� : %.1f\n", pEnemy->AttackPower);
	printf("���� : %d Gold\n", pEnemy->DropGold);
}
