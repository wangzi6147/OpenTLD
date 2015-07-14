#include "windows.h"

void Visca_Left(BYTE *sendbuf,BYTE panseed,BYTE camadd);
void Visca_Right(BYTE *sendbuf,BYTE panseed,BYTE camadd);
void Visca_Up(BYTE *sendbuf,BYTE panseed,BYTE camadd);
void Visca_Down(BYTE *sendbuf,BYTE panseed,BYTE camadd);
void Visca_UpLeft(BYTE *sendbuf,BYTE panseed,BYTE camadd);
void Visca_UpRight(BYTE *sendbuf,BYTE panseed,BYTE camadd);
void Visca_DownLeft(BYTE *sendbuf,BYTE panseed,BYTE camadd);
void Visca_DownRight(BYTE *sendbuf,BYTE panseed,BYTE camadd);
void Visca_PanStop(BYTE *sendbuf,BYTE panseed,BYTE camadd);
void Visca_Home(BYTE *sendbuf,BYTE camadd);
void Visca_ZoomTele(BYTE *sendbuf,BYTE camadd);
void Visca_ZoomWide(BYTE *sendbuf,BYTE camadd);
void Visca_ZoomStop(BYTE *sendbuf,BYTE camadd);
void Visca_FoucsFar(BYTE *sendbuf,BYTE camadd);
void Visca_FoucsNear(BYTE *sendbuf,BYTE camadd);
void Visca_FoucsStop(BYTE *sendbuf,BYTE camadd);
void Visca_IrisUp(BYTE *sendbuf,BYTE camadd);
void Visca_IrisDown(BYTE *sendbuf,BYTE camadd);
void Visca_PreSet(BYTE *sendbuf,BYTE prenum,BYTE camadd);
void Visca_PreCall(BYTE *sendbuf,BYTE prenum,BYTE camadd);
void Visca_PreDel(BYTE *sendbuf,BYTE prenum,BYTE camadd);
void Visca_LensInit(BYTE *sendbuf,BYTE camadd);