#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define COL 4
#define FRAMES 10
#define SPEED 20
#define INVALID_DELAY 1000

#define clean() system("cls")

char* gun[4] = {
	"__________",
    "|  ______0",
	"|@|",
	"|_|"
};
char* gun_shoot[2][FRAMES] = {
	{
		"|  ______0 |",
		"|  ______0   ]",
		"|  ______0     ]]",
		"|  ______0        ]]]",
		"|  ______0           -]]]",
		"|  ______0               -]]]D",
		"|  ______0                --]]DD>>",
		"|  ______0                    --]]DDD>>>",
		"|  ______0                      ---]]]DDD>>>",
		"|  ______0                    -----]]]DDD>>>"
	},
	{
		"|  ______0 >",
		"|  ______0  -]>",
		"|  ______0   -]]>>",
		"|  ______0    --]]]]>>",
		"|  ______0   ==]]]]]]]>>>",
		"|  ______0         ===]]]]]]>>>>",
		"|  ______0           ===]]]DDD>>>",
		"|  ______0             ===]]]]DDDD>>>>>",
		"|  ______0            |====]]]]DDD)))>>>>",
		"|  ______0            --=====]]]]))))DDDII>>>-)"
	}
};

void shoot(int power) {
	int i,j;
	for(i=0;i<FRAMES;i++) {
		clean();
		for(j=0;j<COL;j++) {
			if(j==1) printf("%s\n",gun_shoot[power][i]);
			else printf("%s\n",gun[j]);
		}
		Sleep(SPEED);
	}
}

int main(int argc, char* argv[]) {
	int p,i;
	for(;;) {
		for(i=0;i<COL;i++)
			printf("%s\n",gun[i]);
		printf("Press 0 to Default power, 1 to Strong power, 2 to Quit:\n>");
		scanf("%d",&p);
		if(p<0 || p>2) {
			clean();
			puts("Invalid Command.");
			Sleep(INVALID_DELAY);
			break;
		} else if(p==2) break;
		else if(p==0 || p==1) shoot(p);
		clean();
	} clean();
	puts("Exiting...");
	return 0;
}
