#include <stdio.h>
#include <conio.h>

struct SinhVien
{
	char FullName[100];
	char IDSV[10];
	float DTB;
	float DTCK;
	float DQT;
};
struct SinhVien CLCMorningMonday[10];
void main(void)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		printf("Enter your full name [%d]: ", i + 1);
		gets_s(CLCMorningMonday[i].FullName);

		printf("Enter your student ID [%d]: ", i + 1);
		gets_s(CLCMorningMonday[i].IDSV);



		do
		{
			printf("Enter Mid-term scores student [%d]: ", i + 1);
			scanf_s("%f", &CLCMorningMonday[i].DQT);

		} while (CLCMorningMonday[i].DQT < 0 || CLCMorningMonday[i].DQT > 10);

		do
		{
			printf("Enter Final score student [%d]:  ", i + 1);
			scanf_s("%f", &CLCMorningMonday[i].DTCK);
		} while (CLCMorningMonday[i].DTCK < 0 || CLCMorningMonday[i].DTCK > 10);
		fflush(stdin);
		printf("-----------------------------------\n");

	}
	for (i = 0; i < 5; i++)
	{
		CLCMorningMonday[i].DTB = float(CLCMorningMonday[i].DTB);
		CLCMorningMonday[i].DTB = (CLCMorningMonday[i].DQT *0.5 + CLCMorningMonday[i].DTCK *0.5);
		printf("\n Info student ");
		printf("\n  -FullName: %s ", CLCMorningMonday[i].FullName);
		printf("\n  -IDSV: %s ", CLCMorningMonday[i].IDSV);
		printf("\n  -Averger Score : %f ", CLCMorningMonday[i].DTB);

		if (CLCMorningMonday[i].DTB < 5)
		{
			printf("\n  -Rating: Average, Final Score: %f ", CLCMorningMonday[i].DTB);
		}
		if ((CLCMorningMonday[i].DTB >= 5) && (CLCMorningMonday[i].DTB < 8))
		{
			printf("\n  -Rating: Good, Final Score: %f ", CLCMorningMonday[i].DTB);
		}

		if (CLCMorningMonday[i].DTB >= 8)
		{
			printf("\n  -Rating: Very Good, Final Score: %f ", CLCMorningMonday[i].DTB);
		}

		printf("\n-----------------------------------");
	}
	printf("\n List of students who failed the exam:");
	for (i = 0; i < 5; i++)
	{
		if (CLCMorningMonday[i].DTCK < 3)
		{
			printf("\n  -Full Name: %s -- Reason: Insufficient Score ( Mid-term Scores ) ", CLCMorningMonday[i].FullName);
		}

		else if (CLCMorningMonday[i].DTB < 5)
		{
			printf("\n  -Full Name: %s -- Reason: The average score does not reach the prescribed level ", CLCMorningMonday[i].FullName);
		}
	}
	printf("\n-----------------------------------");
	printf("\n List of students who passed the exam:");
	for (i = 0; i < 5; i++)
	{
		if (CLCMorningMonday[i].DTCK >= 3)
		{
			if (CLCMorningMonday[i].DTB >= 5)
			{
				printf("\n  -Full Name: %s", CLCMorningMonday[i].FullName);
			}
		}
	}
	_getch();
}
