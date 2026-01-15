#ifndef _LINDERMAYER_H_
#define _LINDERMAYER_H_

#define F_GRAMMAR "FF+F-[+-F]"

char *applyRulesToSentence(char *sentence);
void processSentence(char *sentence, int (*cursor)[2]);

#endif
