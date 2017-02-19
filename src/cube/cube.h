#ifndef CUBE_H
#define CUBE_H

/*
           +--+--+--+
           |U0|U1|U2|
           +--+--+--+
           |U3|U4|U5|
           +--+--+--+
           |U6|U7|U8|
  +--+--+--+--+--+--+--+--+--+--+--+--+
  |L0|L1|L2|F0|F1|F2|R0|R1|R2|B0|B1|B2|
  +--+--+--+--+--+--+--+--+--+--+--+--+
  |L3|L4|L5|F3|F4|F5|R3|R4|R5|B3|B4|B5|
  +--+--+--+--+--+--+--+--+--+--+--+--+
  |L6|L7|L8|F6|F7|F8|R6|R7|R8|B6|B7|B8|
  +--+--+--+--+--+--+--+--+--+--+--+--+
           |D0|D1|D2|
           +--+--+--+
           |D3|D4|D5|
           +--+--+--+
           |D6|D7|D8|
           +--+--+--+
 */
typedef struct
{
  char F[9], B[9], U[9], D[9], L[9], R[9];
} cube_t;

extern void cube_init (cube_t *cube);
extern void cube_move_F (cube_t *cube);
extern void cube_move_B (cube_t *cube);
extern void cube_move_U (cube_t *cube);
extern void cube_move_D (cube_t *cube);
extern void cube_move_L (cube_t *cube);
extern void cube_move_R (cube_t *cube);

#endif
