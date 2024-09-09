#include<windows.h>
#include<mmsystem.h>
#include"resource.h"
#define WAVE_RESOURCE_ID IDR_WAVE1  
#define WAVE_RESOURCE_ID IDR_WAVE2
#pragma comment(lib, "winmm.lib")  
void music(int musicnum)
{
	if (musicnum == 1)
	{
		PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE | SND_ASYNC);
	}
	else if (musicnum == 2)
	{
		PlaySound(MAKEINTRESOURCE(IDR_WAVE2), NULL, SND_RESOURCE | SND_ASYNC);
	}
	else if (musicnum == 3)
	{
		PlaySound(MAKEINTRESOURCE(IDR_WAVE3), NULL, SND_RESOURCE | SND_ASYNC);
	}
}