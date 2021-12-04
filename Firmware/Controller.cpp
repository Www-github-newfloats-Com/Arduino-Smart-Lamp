#include "Controller.h"
#include "Colors.h"
#include <Arduino.h>

#define SHOW_COLOR_RED 0
#define SHOW_COLOR_GREEN 1
#define SHOW_COLOR_BLUE 2
#define SHOW_COLOR_PURPLE 3
#define SHOW_COLOR_YELLOW 4
#define HIDE_COLORS 5

int colorIndex = SHOW_COLOR_RED;
int i;

void initController()
{
    initColors();
}

void incrementIndex()
{
    if (colorIndex == HIDE_COLORS)
    {
        colorIndex = 0;
    }
    else
    {
        colorIndex++;
    }
}

void selectColorByIndexMode()
{
    switch (colorIndex)
    {
    case SHOW_COLOR_RED:
        showColorRed();
        break;
    case SHOW_COLOR_GREEN:
        showColorGreen();
        break;
    case SHOW_COLOR_BLUE:
        showColorBlue();
        break;
    case SHOW_COLOR_PURPLE:
        showColorPurple();
        break;
    case SHOW_COLOR_YELLOW:
        showColorYellow();
        break;
    case HIDE_COLORS:
        hideColor();
        break;
    default:
        hideColor();
        break;
    }
}

void blinkColor(int delayValue, int color)
{
    colorIndex = color;
    for (i = 0; i < 20; i++)
    {
        selectColorByIndexMode();
        delay(delayValue);
        hideColor();
        delay(delayValue);
    }
}

void christmasTreeMode()
{
    blinkColor(
        random(50, 100), // delay
        random(0, 5)     // color
    );
}