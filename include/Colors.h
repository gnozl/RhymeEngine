//
// Created by Gerardo Gonzalez on 11/16/25.
//

#ifndef RHYMEENGINE_COLORS_H
#define RHYMEENGINE_COLORS_H

/* ANSI Escape codes for foreground and background colors in terminal
 *
 *
Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107
*/

enum COLOR {
    NONE = -1,
    RED = 31,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE = 37,
    BLACK_BRIGHT = 90,
    RED_BRIGHT,
    GREEN_BRIGHT,
    YELLOW_BRIGHT,
    BLUE_BRIGHT,
    MAGENTA_BRIGHT,
    CYAN_BRIGHT,
    WHITE_BRIGHT = 97,
};


#endif //RHYMEENGINE_COLORS_H