#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	int PokemonHitPoints = 0;
	int PlayerHitPoints = 100;
	int PlayerAttack = 20;
	int Choice;
	int PokemonAttack = 0;
	char PlayerDefend;

	printf("Hello, welcome to Pokemon encounters!\n");
	printf("Please select the Pokemon you wish to fight:\n1. Squirtle\n2. Charmander\n3. Arceus\n");
	printf("Choose option: ");
	scanf("%d", &Choice);

	if (Choice == 1)
	{
		PokemonHitPoints = 40;
		PokemonAttack = 4;
	}
	else if (Choice == 2)
	{
		PokemonHitPoints = 150;
		PokemonAttack = 30;
	}
	else if (Choice == 3)
	{
		PokemonHitPoints = 1000;
		PokemonAttack = 50;
	}
	else
	{
		printf("Error! Invalid selection.\n");
		return 1;
	}

	while (PokemonHitPoints > 0 && PlayerHitPoints > 0)
	{
		PlayerDefend = 'N';

		printf("\nChoose your option: \n");
		printf("1. Attack\n2. Defend\n");
		printf("Choose: ");
		scanf("%d", &Choice);

		if (Choice == 1)
		{
			PokemonHitPoints = PokemonHitPoints - PlayerAttack;
			printf("\nYou attacked the pokemon for %d damage! It has %d left.", PlayerAttack, PokemonHitPoints);
		}
		else if (Choice == 2)
		{
			PlayerDefend = 'Y';
		}

		if (PokemonHitPoints > 0)
		{
			printf("\nPokemon attacks!");

			if (PlayerDefend == 'Y')
			{
				int reducedDamage = PokemonAttack / 2;
				PlayerHitPoints = PlayerHitPoints - reducedDamage;
				printf("\nThe pokemon attacked you for %d damage! You have %d left.", reducedDamage, PlayerHitPoints);
			}
			else
			{
				PlayerHitPoints = PlayerHitPoints - PokemonAttack;
				printf("\nThe pokemon attacked you for %d damage! You have %d left.", PokemonAttack, PlayerHitPoints);
			}
		}

		if (PlayerHitPoints <= 0)
		{
			printf("\n\nYou Died!\n");
		}
		else if (PokemonHitPoints <= 0)
		{
			printf("\n\nThe Pokemon Died!\n");
		}
	}

	return 0;
}
