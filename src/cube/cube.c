#include <string.h>
#include "cube.h"

extern void
cube_init (cube_t *cube)
{
  memset (cube->F, 0, sizeof (cube->F));
  memset (cube->B, 1, sizeof (cube->B));
  memset (cube->U, 2, sizeof (cube->U));
  memset (cube->D, 3, sizeof (cube->D));
  memset (cube->L, 4, sizeof (cube->L));
  memset (cube->R, 5, sizeof (cube->R));
}

/*
  F: (F0 F2 F8 F6)(F1 F5 F7 F3)(U6 R0 D2 L8)(U8 R6 D0 L2)(U7 R3 D1 L5)
*/
extern void
cube_move_F (cube_t *cube)
{
  char tmp;
  // (F0 F2 F8 F6)
  tmp = cube->F[6];
  cube->F[6] = cube->F[8];
  cube->F[8] = cube->F[2];
  cube->F[2] = cube->F[0];
  cube->F[0] = tmp;
  // (F1 F5 F7 F3)
  tmp = cube->F[3];
  cube->F[3] = cube->F[7];
  cube->F[7] = cube->F[5];
  cube->F[5] = cube->F[1];
  cube->F[1] = tmp;
  // (U6 R0 D2 L8)
  tmp = cube->L[8];
  cube->L[8] = cube->D[2];
  cube->D[2] = cube->R[0];
  cube->R[0] = cube->U[6];
  cube->U[6] = tmp;
  // (U8 R6 D0 L2)
  tmp = cube->L[2];
  cube->L[2] = cube->D[0];
  cube->D[0] = cube->R[6];
  cube->R[6] = cube->U[8];
  cube->U[8] = tmp;
  // (U7 R3 D1 L5)
  tmp = cube->L[5];
  cube->L[5] = cube->D[1];
  cube->D[1] = cube->R[3];
  cube->R[3] = cube->U[7];
  cube->U[7] = tmp;
}

/*
  B: (B0 B2 B8 B6)(B1 B5 B7 B3)(U2 L0 D6 R8)(U0 L6 D8 R2)(U1 L3 D7 R5)
*/
extern void
cube_move_B (cube_t *cube)
{
  char tmp;
  // (B0 B2 B8 B6)
  tmp = cube->B[6];
  cube->B[6] = cube->B[8];
  cube->B[8] = cube->B[2];
  cube->B[2] = cube->B[0];
  cube->B[0] = tmp;
  // (B1 B5 B7 B3)
  tmp = cube->B[3];
  cube->B[3] = cube->B[7];
  cube->B[7] = cube->B[5];
  cube->B[5] = cube->B[1];
  cube->B[1] = tmp;
  // (U2 L0 D6 R8)
  tmp = cube->R[8];
  cube->R[8] = cube->D[6];
  cube->D[6] = cube->L[0];
  cube->L[0] = cube->U[2];
  cube->U[2] = tmp;
  // (U0 L6 D8 R2)
  tmp = cube->R[2];
  cube->R[2] = cube->D[8];
  cube->D[8] = cube->L[6];
  cube->L[6] = cube->U[0];
  cube->U[0] = tmp;
  // (U1 L3 D7 R5)
  tmp = cube->R[5];
  cube->R[5] = cube->D[7];
  cube->D[7] = cube->L[3];
  cube->L[3] = cube->U[1];
  cube->U[1] = tmp;
}

/*
  U: (U0 U2 U8 U6)(U1 U5 U7 U3)(F2 L2 B2 R2)(F0 L0 B0 R0)(F1 L1 B1 R1)
*/
extern void
cube_move_U (cube_t *cube)
{
  char tmp;
  // (U0 U2 U8 U6)
  tmp = cube->U[6];
  cube->U[6] = cube->U[8];
  cube->U[8] = cube->U[2];
  cube->U[2] = cube->U[0];
  cube->U[0] = tmp;
  // (U1 U5 U7 U3)
  tmp = cube->U[3];
  cube->U[3] = cube->U[7];
  cube->U[7] = cube->U[5];
  cube->U[5] = cube->U[1];
  cube->U[1] = tmp;
  // (F2 L2 B2 R2)
  tmp = cube->R[2];
  cube->R[2] = cube->B[2];
  cube->B[2] = cube->L[2];
  cube->L[2] = cube->F[2];
  cube->F[2] = tmp;
  // (F0 L0 B0 R0)
  tmp = cube->R[0];
  cube->R[0] = cube->B[0];
  cube->B[0] = cube->L[0];
  cube->L[0] = cube->F[0];
  cube->F[0] = tmp;
  // (F1 L1 B1 R1)
  tmp = cube->R[1];
  cube->R[1] = cube->B[1];
  cube->B[1] = cube->L[1];
  cube->L[1] = cube->F[1];
  cube->F[1] = tmp;
}

/*
  D: (D0 D2 D8 D6)(D1 D5 D7 D3)(F6 R6 B6 L6)(F8 R8 B8 L8)(F7 R7 B7 L7)
*/
extern void
cube_move_D (cube_t *cube)
{
  char tmp;
  // (D0 D2 D8 D6)
  tmp = cube->D[6];
  cube->D[6] = cube->D[8];
  cube->D[8] = cube->D[2];
  cube->D[2] = cube->D[0];
  cube->D[0] = tmp;
  // (D1 D5 D7 D3)
  tmp = cube->D[3];
  cube->D[3] = cube->D[7];
  cube->D[7] = cube->D[5];
  cube->D[5] = cube->D[1];
  cube->D[1] = tmp;
  // (F6 R6 B6 L6)
  tmp = cube->L[6];
  cube->L[6] = cube->B[6];
  cube->B[6] = cube->R[6];
  cube->R[6] = cube->F[6];
  cube->F[6] = tmp;
  // (F8 R8 B8 L8)
  tmp = cube->L[8];
  cube->L[8] = cube->B[8];
  cube->B[8] = cube->R[8];
  cube->R[8] = cube->F[8];
  cube->F[8] = tmp;
  // (F7 R7 B7 L7)
  tmp = cube->L[7];
  cube->L[7] = cube->B[7];
  cube->B[7] = cube->R[7];
  cube->R[7] = cube->F[7];
  cube->F[7] = tmp;
}

/*
  L: (L0 L2 L8 L6)(L1 L5 L7 L3)(U0 F0 D0 B8)(U6 F6 D6 B2)(U3 F3 D3 B5)
*/
extern void
cube_move_L (cube_t *cube)
{
  char tmp;
  // (L0 L2 L8 L6)
  tmp = cube->L[6];
  cube->L[6] = cube->L[8];
  cube->L[8] = cube->L[2];
  cube->L[2] = cube->L[0];
  cube->L[0] = tmp;
  // (L1 L5 L7 L3)
  tmp = cube->L[3];
  cube->L[3] = cube->L[7];
  cube->L[7] = cube->L[5];
  cube->L[5] = cube->L[1];
  cube->L[1] = tmp;
  // (U0 F0 D0 B8)
  tmp = cube->B[8];
  cube->B[8] = cube->D[0];
  cube->D[0] = cube->F[0];
  cube->F[0] = cube->U[0];
  cube->U[0] = tmp;
  // (U6 F6 D6 B2)
  tmp = cube->B[2];
  cube->B[2] = cube->D[6];
  cube->D[6] = cube->F[6];
  cube->F[6] = cube->U[6];
  cube->U[6] = tmp;
  // (U3 F3 D3 B5)
  tmp = cube->B[5];
  cube->B[5] = cube->D[3];
  cube->D[3] = cube->F[3];
  cube->F[3] = cube->U[3];
  cube->U[3] = tmp;
}

/*
  R: (R0 R2 R8 R6)(R1 R5 R7 R3)(U8 B0 D8 F8)(U2 B6 D2 F2)(U5 B3 D5 F5)
*/
extern void
cube_move_R (cube_t *cube)
{
  char tmp;
  // (R0 R2 R8 R6)
  tmp = cube->R[6];
  cube->R[6] = cube->R[8];
  cube->R[8] = cube->R[2];
  cube->R[2] = cube->R[0];
  cube->R[0] = tmp;
  // (R1 R5 R7 R3)
  tmp = cube->R[3];
  cube->R[3] = cube->R[7];
  cube->R[7] = cube->R[5];
  cube->R[5] = cube->R[1];
  cube->R[1] = tmp;
  // (U8 B0 D8 F8)
  tmp = cube->F[8];
  cube->F[8] = cube->D[8];
  cube->D[8] = cube->B[0];
  cube->B[0] = cube->U[8];
  cube->U[8] = tmp;
  // (U2 B6 D2 F2)
  tmp = cube->F[2];
  cube->F[2] = cube->D[2];
  cube->D[2] = cube->B[6];
  cube->B[6] = cube->U[2];
  cube->U[2] = tmp;
  // (U5 B3 D5 F5)
  tmp = cube->F[5];
  cube->F[5] = cube->D[5];
  cube->D[5] = cube->B[3];
  cube->B[3] = cube->U[5];
  cube->U[5] = tmp;
}
