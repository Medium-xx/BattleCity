#include "config.h"
#include "GameConfiguration.h"
#include "Scene.h"



hgeResourceManager	*pResourceManager = NULL;
Scene* pWorld = NULL;
//hgeAnimation		player_anim;

bool FrameFunc()
{
	//	if (GameConfiguration::pHGE->Input_GetKeyState(HGEK_ESCAPE)) return true;
	//	if (GameConfiguration::pHGE->Input_KeyDown(HGEK_UP))
	//	if (GameConfiguration::pHGE->Input_GetKeyState(HGEK_RIGHT));
	//	player_anim->Update(GameConfiguration::pHGE->Timer_GetDelta());
	pWorld->Update(PressedKeys());
	return false;
};

bool RenderFunc()
{
	GameConfiguration::pHGE->Gfx_BeginScene();
	GameConfiguration::pHGE->Gfx_Clear(0);
	

	//	player_anim->Render(static_cast<int>(x),400 - static_cast<int>(y));
	pWorld->Render();
//	hgeSprite* x = pResourceManager->GetSprite("s_tank");
//	x->Render(110,110);
	//hgeSprite(hgeGetTexture)

	GameConfiguration::pHGE->Gfx_EndScene();

	return false;
};

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int  )
{
	GameConfiguration::pHGE = hgeCreate(HGE_VERSION);
	GameConfiguration::pHGE->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	GameConfiguration::pHGE->System_SetState(HGE_RENDERFUNC, RenderFunc);
	GameConfiguration::pHGE->System_SetState(HGE_TITLE, "[:]<><><>[:]");
	GameConfiguration::pHGE->System_SetState(HGE_FPS, 24);
	GameConfiguration::pHGE->System_SetState(HGE_WINDOWED, true);
	GameConfiguration::pHGE->System_SetState(HGE_SCREENWIDTH, GameConfiguration::ScreenWidth);
	GameConfiguration::pHGE->System_SetState(HGE_SCREENHEIGHT, GameConfiguration::ScreenHeight);
	GameConfiguration::pHGE->System_SetState(HGE_SCREENBPP, 32);
	GameConfiguration::pHGE->System_SetState(HGE_SHOWSPLASH, false);

	if (!GameConfiguration::pHGE->System_Initiate())
	{
		MessageBox(NULL, L"This is caption.", L"This is error.", MB_OK | MB_ICONERROR | MB_APPLMODAL);
		GameConfiguration::pHGE->System_Shutdown();
		GameConfiguration::pHGE->Release();
	}

	
	GameConfiguration::pResourceManager = new hgeResourceManager("resource.txt");
	pWorld = new Scene();
	pWorld->LoadMap ("Map1.txt");

	GameConfiguration::pHGE->System_Start();

	delete pResourceManager;
	GameConfiguration::pHGE->System_Shutdown();
	GameConfiguration::pHGE->Release();

	return 0;
};