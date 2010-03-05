#include <hge.h>
#include <hgeresource.h>
#include <hgeanim.h>

HGE					*hge = 0;

hgeResourceManager	*myRes;

//hgeAnimation		player_anim;

bool FrameFunc()
{
	//	if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	//	if (hge->Input_KeyDown(HGEK_UP))
	//	if (hge->Input_GetKeyState(HGEK_RIGHT));
	//	player_anim->Update(hge->Timer_GetDelta());
	return false;
};

bool RenderFunc()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);

	//	player_anim->Render(static_cast<int>(x),400 - static_cast<int>(y));

	hge->Gfx_EndScene();

	return false;
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "Accordion City");
	hge->System_SetState(HGE_FPS, 24);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);
	hge->System_SetState(HGE_SHOWSPLASH, false);

	if (!hge->System_Initiate())
	{
		MessageBox(NULL, L"This is caption.", L"This is error.", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		delete myRes;
		hge->System_Shutdown();
		hge->Release();
	}

	//		myRes = new hgeResourceManager("resource.txt");
	//		anim_player_forward = myRes->GetAnimation("player_tank_forward");
	//		anim_player_forward->Play();

	hge->System_Start();

	delete myRes;
	hge->System_Shutdown();
	hge->Release();

	return 0;
};