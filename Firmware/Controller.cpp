#include "Controller.h"
#include "Colors.h"

int colorIndex = 0;


void initController() {
    initColors();
}

void setColorIndex(int index) {
    colorIndex = index;
}

void incrementIndex() {
    if (colorIndex == 5) {
        colorIndex = 0;
    } else {
        colorIndex++;
    }
}

void loopSelectColorByIndex() {
    switch (colorIndex) {

        case 0:
            showColorRed();
            incrementIndex();
            break;

        case 1:
            showColorGreen();
            incrementIndex();
            break;

        case 2:
            showColorBlue();
            incrementIndex();
            break;

        case 3:
            showColorPurple();
            incrementIndex();
            break;

        case 4:
            showColorPurple();
            incrementIndex();
            break;

        case 5:
            showColorWhite();
            incrementIndex();
            break;

        default:
            hideColor();
            break;
    }
}
