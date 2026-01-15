#include "../include/base.h"
#include "../include/lindermayer.h"

char *applyRulesToSentence(char *sentence)
{
	int i = 0;

	/* puts(sentence); */
	/* printf("len: %d\n",strlen(sentence)); */
	while (sentence[i] != '\0') {
		if (sentence[i] == 'F') {
			/* printf("strlenfgrammar: %d\n", strlen(F_GRAMMAR)); */
			char *tmp = realloc(sentence, sizeof(char) * (strlen(sentence) + strlen(F_GRAMMAR) + 100));
			if (tmp != NULL) 
				sentence = tmp;
			else
				puts("error");
			char *f_grammar = strdup(F_GRAMMAR);
			int srclen = strlen(f_grammar);

			/* printf("idx: %d\n", i); */
			/* printf("test: %s\n", &sentence[i + 1]); */
			/* printf("before: %s\n", sentence); */
			memmove(&sentence[i + srclen], &sentence[i + 1], srclen + strlen(&sentence[i + srclen])); // move the i + 1 to the end of the f_grammar in the sentence
			/* printf("middle: %s\n", sentence); */
			memmove(&sentence[i], f_grammar, srclen); // insert f_grammar with the space we made
			/* printf("after: %s\n", sentence); */
			i += srclen;
		} else {
			i++;
		}
		/* printf("%d\n", i); */
	}
	return sentence;
}

int* getRotation(int incr)
{
	static int cursor[4][2] = {
		{0, -1}, // UP 
		{1, 0}, // RIGHT 
		{0, 1}, // DOWN 
		{-1, 0}, // LEFT 
	};
	static int currRotIdx = 0;

	if (incr < 0)
		return cursor[0];
	if (incr)
		currRotIdx = currRotIdx == 3 ? 0 : currRotIdx + 1;
	else
		currRotIdx = currRotIdx == 0 ? 3 : currRotIdx - 1;
	return cursor[currRotIdx];
}

void drawForward(int cursor[2], int currRotation[2])
{
	/* printf("drawing at x:%d, y:%d\n", cursor[0], cursor[1]); */
	/* printf("direction x:%d, y:%d\n", currRotation[0], currRotation[1]); */
	mvprintw(cursor[0] + currRotation[1], cursor[1] + currRotation[0], ".");
}

void processSentence(char *sentence, int (*cursor)[2])
{
	int *currRotation = getRotation(-1);
	
	/* printf("x: %d, y: %d\n", test[0], test[1]); */

	for (int i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] == '+')
			currRotation = getRotation(1);
		if (sentence[i] == '-')
			currRotation = getRotation(1);
		if (sentence[i] == 'F') {
			drawForward((*cursor), currRotation);
			(*cursor)[0] += currRotation[1];
			(*cursor)[1] += currRotation[0];
		}
	}
}
