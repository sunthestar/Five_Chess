#pragma once

#define XLen 128
#define YLen 33

typedef struct {
    unsigned char x;
    unsigned char y;
} Point;

extern Point p;
extern Point* focus;
extern char Map[YLen][XLen];
extern char Chess_Flag;
extern char Decide[17][17];
extern char Message[128];
