#include "software_timer.h"

softwareTimer timerPool[MAX_TIMERS];

void timerInit() {
	for (int i = 0; i < MAX_TIMERS; i++) {
		timerPool[i].flag = 0;
		timerPool[i].counter = 0;
	}
}

void setTimer(int index, int duration) {
	timerPool[index].flag = 0;
	timerPool[index].counter = duration / TIME_CYCLE;
}

void clearTimer(int index){
	timerPool[index].counter = 0;
	timerPool[index].flag = 0;
}

int IsTimerExpired(int index) {
	if (timerPool[index].flag == 1) {
		timerPool[index].flag = 0;
		return 1;
	}

	return 0;
}

void timerRun(){
	for (int i = 0; i < MAX_TIMERS; i++){
		if (timerPool[i].counter > 0){
			timerPool[i].counter--;
			if (timerPool[i].counter <= 0){
				timerPool[i].flag = 1;
			}
		}
	}
}
