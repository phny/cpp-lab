/*************************************************************************
	> File Name: progress_bar.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年06月01日 星期一 19时55分12秒
 ************************************************************************/

#include <iostream>
#include <unistd.h>

using namespace std;


// 方案1
class pBar {
public:
    void update(double newProgress) {
        currentProgress += newProgress;
        amountOfFiller = (int)((currentProgress / neededProgress)*(double)pBarLength);
    }
    void print() {
        currUpdateVal %= pBarUpdater.length();
        cout << "\r" //Bring cursor to start of line
            << firstPartOfpBar; //Print out first part of pBar
        for (int a = 0; a < amountOfFiller; a++) { //Print out current progress
            cout << pBarFiller;
        }
        cout << pBarUpdater[currUpdateVal];
        for (int b = 0; b < pBarLength - amountOfFiller; b++) { //Print out spaces
            cout << " ";
        }
        cout << lastPartOfpBar //Print out last part of progress bar
            << " (" << (int)(100*(currentProgress/neededProgress)) << "%)" //This just prints out the percent
            << flush;
        currUpdateVal += 1;
    }
    std::string firstPartOfpBar = "[", //Change these at will (that is why I made them public)
        lastPartOfpBar = "]",
        pBarFiller = "|",
        pBarUpdater = "/-\\|";
private:
    int amountOfFiller,
        pBarLength = 50, //I would recommend NOT changing this
        currUpdateVal = 0; //Do not change
    double currentProgress = 0, //Do not change
        neededProgress = 100; //I would recommend NOT changing this
};

// 方案2
#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

void printProgress(double percentage) {
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}

// 方案3


int main() {
     pBar bar;
    for (int i = 0; i < 208; i++) {
		bar.update(1);
		bar.print();
        sleep(1);
    }
    cout << endl;
	return 0;
}
