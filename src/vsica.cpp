#include "visca.h"

void Visca_Left(BYTE *sendbuf,BYTE panseed,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x06;
	*(sendbuf + 3) = 0x01;
	*(sendbuf + 4) = panseed;
	*(sendbuf + 5) = panseed;
	*(sendbuf + 6) = 0x01;
	*(sendbuf + 7) = 0x03;
	*(sendbuf + 8) = 0xff;
}

void Visca_Right(BYTE *sendbuf,BYTE panseed,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x06;
	*(sendbuf + 3) = 0x01;
	*(sendbuf + 4) = panseed;
	*(sendbuf + 5) = panseed;
	*(sendbuf + 6) = 0x02;
	*(sendbuf + 7) = 0x03;
	*(sendbuf + 8) = 0xff;
}

void Visca_Up(BYTE *sendbuf,BYTE panseed,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x06;
	*(sendbuf + 3) = 0x01;
	*(sendbuf + 4) = panseed;
	*(sendbuf + 5) = panseed;
	*(sendbuf + 6) = 0x03;
	*(sendbuf + 7) = 0x01;
	*(sendbuf + 8) = 0xff;
}

void Visca_Down(BYTE *sendbuf,BYTE panseed,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x06;
	*(sendbuf + 3) = 0x01;
	*(sendbuf + 4) = panseed;
	*(sendbuf + 5) = panseed;
	*(sendbuf + 6) = 0x03;
	*(sendbuf + 7) = 0x02;
	*(sendbuf + 8) = 0xff;
}

void Visca_UpLeft(BYTE *sendbuf,BYTE panseed,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x06;
	*(sendbuf + 3) = 0x01;
	*(sendbuf + 4) = panseed;
	*(sendbuf + 5) = panseed;
	*(sendbuf + 6) = 0x01;
	*(sendbuf + 7) = 0x01;
	*(sendbuf + 8) = 0xff;
}

void Visca_UpRight(BYTE *sendbuf,BYTE panseed,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x06;
	*(sendbuf + 3) = 0x01;
	*(sendbuf + 4) = panseed;
	*(sendbuf + 5) = panseed;
	*(sendbuf + 6) = 0x02;
	*(sendbuf + 7) = 0x01;
	*(sendbuf + 8) = 0xff;
}

void Visca_DownLeft(BYTE *sendbuf,BYTE panseed,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x06;
	*(sendbuf + 3) = 0x01;
	*(sendbuf + 4) = panseed;
	*(sendbuf + 5) = panseed;
	*(sendbuf + 6) = 0x01;
	*(sendbuf + 7) = 0x02;
	*(sendbuf + 8) = 0xff;
}

void Visca_DownRight(BYTE *sendbuf,BYTE panseed,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x06;
	*(sendbuf + 3) = 0x01;
	*(sendbuf + 4) = panseed;
	*(sendbuf + 5) = panseed;
	*(sendbuf + 6) = 0x02;
	*(sendbuf + 7) = 0x02;
	*(sendbuf + 8) = 0xff;
}

void Visca_PanStop(BYTE *sendbuf,BYTE panseed,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x06;
	*(sendbuf + 3) = 0x01;
	*(sendbuf + 4) = panseed;
	*(sendbuf + 5) = panseed;
	*(sendbuf + 6) = 0x03;
	*(sendbuf + 7) = 0x03;
	*(sendbuf + 8) = 0xff;
}

void Visca_Home(BYTE *sendbuf,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x06;
	*(sendbuf + 3) = 0x04;
	*(sendbuf + 4) = 0xff;
}

void Visca_ZoomTele(BYTE *sendbuf,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x07;
	*(sendbuf + 4) = 0x24;
	*(sendbuf + 5) = 0xff;
}

void Visca_ZoomWide(BYTE *sendbuf,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x07;
	*(sendbuf + 4) = 0x34;
	*(sendbuf + 5) = 0xff;
}

void Visca_ZoomStop(BYTE *sendbuf,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x07;
	*(sendbuf + 4) = 0x00;
	*(sendbuf + 5) = 0xff;
}

void Visca_FoucsFar(BYTE *sendbuf,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x08;
	*(sendbuf + 4) = 0x24;
	*(sendbuf + 5) = 0xff;
}

void Visca_FoucsNear(BYTE *sendbuf,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x08;
	*(sendbuf + 4) = 0x34;
	*(sendbuf + 5) = 0xff;
}

void Visca_FoucsStop(BYTE *sendbuf,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x08;
	*(sendbuf + 4) = 0x00;
	*(sendbuf + 5) = 0xff;
}

void Visca_IrisUp(BYTE *sendbuf,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x0b;
	*(sendbuf + 4) = 0x02;
	*(sendbuf + 5) = 0xff;
}

void Visca_IrisDown(BYTE *sendbuf,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x0b;
	*(sendbuf + 4) = 0x03;
	*(sendbuf + 5) = 0xff;
}

void Visca_PreSet(BYTE *sendbuf,BYTE prenum,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x3f;
	*(sendbuf + 4) = 0x01;
	*(sendbuf + 5) = prenum - 1;
	*(sendbuf + 6) = 0xff;
}

void Visca_PreCall(BYTE *sendbuf,BYTE prenum,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x3f;
	*(sendbuf + 4) = 0x02;
	*(sendbuf + 5) = prenum - 1;
	*(sendbuf + 6) = 0xff;
}

void Visca_PreDel(BYTE *sendbuf,BYTE prenum,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x3f;
	*(sendbuf + 4) = 0x00;
	*(sendbuf + 5) = prenum - 1;
	*(sendbuf + 6) = 0xff;
}

void Visca_LensInit(BYTE *sendbuf,BYTE camadd)
{
	*(sendbuf + 0) = 0x80 + camadd;
	*(sendbuf + 1) = 0x01;
	*(sendbuf + 2) = 0x04;
	*(sendbuf + 3) = 0x47;
	*(sendbuf + 4) = 0x00;
	*(sendbuf + 5) = 0x00;
	*(sendbuf + 6) = 0x00;
	*(sendbuf + 7) = 0x00;
	*(sendbuf + 8) = 0xff;
}
