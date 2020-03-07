#ifndef RULES_H
#define RULES_H

int rulePopulation(int x, int y, int neighbors[], int state);
int ruleLoneliness(int x, int y, int neighbors[], int state);
int ruleRevive(int x, int y, int neighbors[], int state);
int ruleEld(int x, int y, int neighbors[], int state);
int ruleHistoric(int x, int y, int neighbors[], int state);
int ruleTime(int x, int y, int neighbors[], int state);
int ruleDev(int x, int y, int neighbors[], int state);

#endif /* RULES_H */