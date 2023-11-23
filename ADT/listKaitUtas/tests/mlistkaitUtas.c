
#include "../listkaitUtas.h"
#include "../../MesinKata/wordmachine.h"

int main(){
	Utas u;
	int x;
	char s1[100]; Word w1; Utas u1;
	char s2[100]; Word w2; Utas u2;
	boolean testUtas;
	Utas_CreateUtas(&u);

	scanf("%s", s1);
	scanf("%s", s2);
	w1 = stringToWord(s1);
	w2 = stringToWord(s2);
	Utas_setUtasFromWord(&u1, w1);
	Utas_setUtasFromWord(&u2, w2);
	

	scanf("%d", &x);
	switch (x)
	{
	case 1:
		Utas_insertFirst(&u, INFO_UTAS(u1));
		Utas_insertLast(&u, INFO_UTAS(u2));
		displayTestUtas(u);
		break;
	
	case 2:
		Utas_insertFirst(&u, INFO_UTAS(u1));
		Utas_deleteFirst(&u, &INFO_UTAS(u1));
		Utas_insertLast(&u, INFO_UTAS(u1));
		displayTestUtas(u);
		break;

	case 3:
		testUtas = Utas_compareUtas(u1, u2);
		if (testUtas) printf("true");
		else printf("false");
		break;
	}
	printf("\n");

	return 0;
}