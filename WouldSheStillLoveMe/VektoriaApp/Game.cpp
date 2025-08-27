#include "Game.h"

CGame::CGame(void)
{
}

CGame::~CGame(void)
{
}

void CGame::Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash * psplash)
{
	//---------------------------------
	// Initialisiere die Knotenobjekte:
	//---------------------------------

	// Zuallererst muss die Root mit dem Splash-Screen initialisiert werden, 
	// damit die Engine freigeschaltet wird:
	m_zr.Init(psplash);

	// Hier kommen alle weiteren Initialisierungen hinein: 

	//Sachen sehen ist schön
	m_zf.Init(hwnd, procOS);
	m_zv.InitFull(&m_zc);
	//add
	m_zr.AddFrame(&m_zf);
	m_zf.AddViewport(&m_zv);
	
	m_zr.AddScene(&m_zs);
	m_zs.AddPlacement(&m_zp);
	m_zp.AddCamera(&m_zc);
	
	//cool, das läuft so jetzt erst mal
	
	//Start Screen
	m_zo_Background.InitFull("textures\\Logo_New.jpg");
	m_zv.AddOverlay(&m_zo_Background);
	m_zo_Start.Init("textures\\Single.jpg", C2dRect(0.2, 0.08, 0.42, 0.63), false);
	m_zo_Credits.Init("textures\\Multi.jpg", C2dRect(0.2, 0.08, 0.42, 0.72), false);
	m_zv.AddOverlay(&m_zo_Start);
	m_zv.AddOverlay(&m_zo_Credits);
	m_zo_Background.SetLayer(0.9f);
	m_zo_Start.SetLayer(0.1f);
	m_zo_Credits.SetLayer(0.1f);
	m_zos.Add(&m_zo_Start);
	m_zos.Add(&m_zo_Credits);
	m_zos.Add(&m_zo_Textbox);
	m_zos.Add(m_zo_ObjectOne);
	m_zos.Add(m_zo_ObjectTwo);
	m_zos.Add(&m_zo_Next);
	m_zos.Add(m_zo_Sequence);
	m_zos.Add(m_zo_BadEnding);
	m_zos.Add(m_zo_NormalEnding);
	m_zos.Add(m_zo_HappyEnding);
	


	//beginning
	m_zo_Mirror.InitFull("textures\\red_image.jpg");
	m_zo_Textbox.Init("textures\\blue_image.jpg", C2dRect(1.0, 0.5, 0.0, 0.5), false);
	m_zv.AddOverlay(&m_zo_Mirror);
	m_zv.AddOverlay(&m_zo_Textbox);
	m_zo_Mirror.SetLayer(0.6);
	m_zo_Textbox.SetLayer(0.2);
	//okay, was läuft hier wieder falsch? //okay, hau andere bilder rein //okay, läuft jetzt so, cool
	
	m_zo_Mirror.SwitchOff();
	m_zo_Textbox.SwitchOff();

	//init Overlays
	m_zo_SceneBackground[0].InitFull("textures\\1_B1.jpg");
	m_zo_SceneBackground[1].InitFull("textures\\1_B2.jpg");
	m_zo_SceneBackground[2].InitFull("textures\\1_B3.jpg");
	m_zo_SceneBackground[3].InitFull("textures\\1_B4.jpg");
	m_zo_SceneBackground[4].InitFull("textures\\1_B5.jpg");

	m_zo_NPC1Expression[0].Init("textures\\1_F5.jpg", C2dRect(0.3, 0.6, 0.1, 0.0), false);
	m_zo_NPC1Expression[1].Init("textures\\1_F4.jpg", C2dRect(0.3, 0.6, 0.7, 0.0), false);
	m_zo_NPC2Expression[0].Init("textures\\1_F3.jpg", C2dRect(0.3, 0.6, 0.7, 0.0), false);
	m_zo_NPC2Expression[1].Init("textures\\1_F5.jpg", C2dRect(0.3, 0.6, 0.1, 0.0), false);

	m_zo_ObjectOne[0].Init("textures\\red_image.jpg", C2dRect(0.2, 0.3, 0.4, 0.8), false);
	m_zo_ObjectOne[1].Init("textures\\green_image.jpg", C2dRect(0.2, 0.3, 0.4, 0.8), false);
	m_zo_ObjectOne[2].Init("textures\\green_image.jpg", C2dRect(0.2, 0.3, 0.4, 0.8), false);
	m_zo_ObjectOne[3].Init("textures\\green_image.jpg", C2dRect(0.2, 0.3, 0.4, 0.8), false);
	m_zo_ObjectOne[4].Init("textures\\green_image.jpg", C2dRect(0.2, 0.3, 0.4, 0.8), false);

	m_zo_ObjectTwo[0].Init("textures\\blue_image.jpg", C2dRect(0.2, 0.3, 0.8, 0.4), false);
	m_zo_ObjectTwo[1].Init("textures\\green_image.jpg", C2dRect(0.2, 0.3, 0.8, 0.4), false);
	m_zo_ObjectTwo[2].Init("textures\\green_image.jpg", C2dRect(0.2, 0.3, 0.8, 0.4), false);
	m_zo_ObjectTwo[3].Init("textures\\green_image.jpg", C2dRect(0.2, 0.3, 0.8, 0.4), false);
	m_zo_ObjectTwo[4].Init("textures\\green_image.jpg", C2dRect(0.2, 0.3, 0.8, 0.4), false);

	m_zo_CharacterExpression[0].Init("textures\\1_F1.jpg", C2dRect(0.3, 0.7, 0.4, 0.2), false);
	m_zo_CharacterExpression[1].Init("textures\\1_F2.jpg", C2dRect(0.3, 0.7, 0.4, 0.2), false);
	m_zo_CharacterExpression[2].Init("textures\\1_F3.jpg", C2dRect(0.3, 0.7, 0.4, 0.2), false);
	m_zo_CharacterExpression[3].Init("textures\\1_F4.jpg", C2dRect(0.3, 0.7, 0.4, 0.2), false);
	m_zo_CharacterExpression[4].Init("textures\\1_F5.jpg", C2dRect(0.3, 0.7, 0.4, 0.2), false);

	m_zo_Sequence[0].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[1].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[2].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[3].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[4].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[5].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[6].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[7].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[8].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[9].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[10].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[11].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[12].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[13].InitFull("textures\\green_image.jpg");
	m_zo_Sequence[14].InitFull("textures\\green_image.jpg");
	
	m_zv.AddOverlay(m_zo_Sequence);
	m_zo_Sequence->SwitchOff();

	m_zo_Next.Init("textures\\blue_image.jpg", C2dRect(0.3, 0.7, 0.4, 0.2), false);

	m_zv.AddOverlay(m_zo_ObjectOne);
	m_zv.AddOverlay(m_zo_ObjectTwo);
	m_zo_ObjectOne[0].SwitchOff();
	m_zo_ObjectTwo[0].SwitchOff();

	m_zv.AddOverlay(&m_zo_Next);
	m_zo_Next.SwitchOff();

	//Hearts
	m_zo_Hearts[0].Init("textures\\green_image.jpg", C2dRect(0.3, 0.1, 0.1, 0.1), false);
	m_zo_Hearts[1].Init("textures\\blue_image.jpg", C2dRect(0.3, 0.1, 0.1, 0.1), false);
	m_zo_Hearts[2].Init("textures\\red_image.jpg", C2dRect(0.3, 0.1, 0.1, 0.1), false);


	m_zv.AddOverlay(m_zo_Hearts);
	m_zo_Hearts[0].SwitchOff();
	m_zo_Hearts[1].SwitchOff();
	m_zo_Hearts[2].SwitchOff();
	
	



	//Cursor
	m_zf.AddDeviceCursor(&m_zdc);

	//Page
	iPageNumber = 0;


	//Scenes
	/*
	School.SetBackground(0);
	School.SetMaxNumber(11);
	School.SetPageNumber(4);

	Cafe.SetBackground(0);
	Cafe.SetMaxNumber(11);
	Cafe.SetPageNumber(4);

	Festival.SetBackground(0);
	Festival.SetMaxNumber(11);
	Festival.SetPageNumber(4);

	Shop.SetBackground(0);
	Shop.SetMaxNumber(11);
	Shop.SetPageNumber(4);

	Ice.SetBackground(0);
	Ice.SetMaxNumber(11);
	Ice.SetPageNumber(4);
	*/

	/*
	School.Init(4, 11, 1);
	Cafe.Init(12, 20, 2);
	Festival.Init(21, 29, 3);
	Shop.Init(30, 38, 4);
	Ice.Init(39, 49, 5);
	
	*/


	iScene = 0;
	iTicks = 0;

	iHalfHearts = 0;

	//Text
	m_zwf_Speech.LoadPreset("PrestigeEliteWhite");
	m_zw_Speech.Init(C2dRect(0.9,0.065,0.04,0.63),95, &m_zwf_Speech);
	m_zw_Speech.SetLayer(0.1);
	m_zr.AddMaterial(&m_zwf_Speech);
	m_zv.AddWriting(&m_zw_Speech);
	m_zw_Speech.SwitchOff();
	m_zw_Speech.SetTransparency(0.1);

	m_zw_Speech1.Init(C2dRect(0.9, 0.065, 0.04, 0.7), 95, &m_zwf_Speech);
	m_zw_Speech1.SetLayer(0.1);
	m_zv.AddWriting(&m_zw_Speech1);
	m_zw_Speech1.SwitchOff();
	m_zw_Speech1.SetTransparency(0.1);

	m_zw_Speech2.Init(C2dRect(0.9, 0.065, 0.04, 0.77), 95, &m_zwf_Speech);
	m_zw_Speech2.SetLayer(0.1);
	m_zv.AddWriting(&m_zw_Speech2);
	m_zw_Speech2.SwitchOff();
	m_zw_Speech2.SetTransparency(0.1);
	
	m_zw_Speech3.Init(C2dRect(0.9, 0.065, 0.04, 0.84), 95, &m_zwf_Speech);
	m_zw_Speech3.SetLayer(0.1);
	m_zv.AddWriting(&m_zw_Speech3);
	m_zw_Speech3.SwitchOff();
	m_zw_Speech3.SetTransparency(0.1);



}

void CGame::Tick(float fTime, float fTimeDelta)
{
	//-------------------------------------------
	// Veränderungen während der Simulationszeit:
	//-------------------------------------------

	// Hier kommen die Veränderungen pro Renderschritt hinein: 
	if (m_zdc.ButtonDownLeft()) {
		if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Start)
		{
			m_zo_Background.SwitchOff();
			m_zo_Start.SwitchOff();
			m_zo_Credits.SwitchOff();
			m_zo_Mirror.SwitchOn();
			m_zo_Textbox.SwitchOn();
			m_zw_Speech.SwitchOn();
			m_zw_Speech1.SwitchOn();
			m_zw_Speech2.SwitchOn();
			m_zw_Speech.PrintF("It was valentine’s day again. The most dreaded day of the year.");
			m_zw_Speech1.PrintF("Usually because with it came the awkwardness of watching couples acting all lovey - dovey");
			m_zw_Speech2.PrintF("while I walk home from school by myself.It turned being alone into being lonely." );
			iPageNumber = 1;
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Credits)
		{
			m_zo_Background.SwitchOff();
			m_zo_Start.SwitchOff();
			m_zo_Credits.SwitchOff();
			m_zo_Mirror.SwitchOn(); //edit later
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Textbox)
		{
			switch (iScene) {
			case 0:
				switch (iPageNumber) {
				case 1:
					m_zw_Speech.PrintF("But not this year.This year it was something different, that got me nervously");
					m_zw_Speech1.PrintF("staring onto my mirror and wondering if I would ever be good enough for someone.I had");
					m_zw_Speech2.PrintF("collected all my courage and asked the girl I liked out.");
					  
					break;
				case 2:
					m_zw_Speech.PrintF("Bella was the prettiest girl in our school and a kindhearted angel. And we have");
					m_zw_Speech1.PrintF("become friends since a group project in our chemistry class. I honestly don’t know");
					m_zw_Speech2.PrintF("how this happened, but she agreed to spend the day with me, and I was over the moon.");
					  

					break;
				case 3:
					m_zw_Speech.PrintF("But the scariest part was to come.I had to make sure this day went well. I have to listen and");
					m_zw_Speech1.PrintF("make sure I get her everything she wants. Only then do I stand a chance at turning this into");
					m_zw_Speech2.PrintF("a full - blown relationship and the possibility of never spending valentine’s day alone.");
					m_zw_Speech3.PrintF("It was time.");
					m_zw_Speech3.SwitchOn();

					iScene++;
					iPageNumber = 0;
					break;
				}
				break;

			case 1: 
				m_zo_Mirror.SwitchOff();
				m_zo_SceneBackground[0].SwitchOn();
				
				switch (iPageNumber) {
				case 1: 
					m_zo_NPC1Expression[1].SwitchOn();
					m_zw_Speech.PrintF("Best Friend:");
					m_zw_Speech1.PrintF("Hey, bro, how’s it going? You ready for your date?");
					m_zw_Speech2.SwitchOff();
					m_zw_Speech3.SwitchOff();

					break;
				case 2:
					m_zo_NPC1Expression[0].SwitchOn();
					m_zo_NPC1Expression[1].SwitchOff();
					m_zw_Speech.PrintF("You:");
					m_zw_Speech1.PrintF("I haven’t slept for half the night because I was so nervous.Have you seen Bella already?");
					m_zw_Speech2.PrintF("Do I still have time to get her something? Oh god, what do I even do?");
					m_zw_Speech2.SwitchOn();

					break;
				case 3:
					m_zo_NPC1Expression[1].SwitchOn();
					m_zo_NPC1Expression[0].SwitchOff();
					m_zw_Speech.PrintF("Best Friend:");
					m_zw_Speech1.PrintF("I haven’t seen her yet. Her teacher probably decided to continue the class for a few extra");
					m_zw_Speech2.PrintF("minutes. Wouldn’t be the first time.You should take a breath and calm down a little for now.");
					m_zw_Speech3.PrintF("It’s not like you asked a compete stranger.She’s your friend. You’ll be fine.");
					m_zw_Speech3.SwitchOn();
					
					break;
				case 4:
					m_zo_NPC1Expression[0].SwitchOn();
					m_zo_NPC1Expression[1].SwitchOff();
					m_zo_NPC2Expression[1].SwitchOn();
					m_zw_Speech.PrintF("Friend:");
					m_zw_Speech1.PrintF("Wow, you really got yourself that date? Didn’t think I’d see that day happen.");
					m_zw_Speech2.PrintF("You brought her any flowers?");
					m_zw_Speech3.SwitchOff();

					break;
				case 5:
					m_zo_NPC1Expression[1].SwitchOn();
					m_zo_NPC1Expression[0].SwitchOff();
					m_zo_NPC2Expression[0].SwitchOn();
					m_zo_NPC2Expression[1].SwitchOff();
					m_zw_Speech.PrintF("Best Friend:");
					m_zw_Speech1.PrintF("Flowers? I guess girls do like getting flowers.They die so quickly though. My girlfriend");
					m_zw_Speech2.PrintF("prefers getting chocolate. Speaking of, I still need to get her some. I’ll be off. Good");
					m_zw_Speech3.PrintF("luck, dude.");
					m_zw_Speech3.SwitchOn();

					break;
				case 6:
					m_zo_NPC1Expression[1].SwitchOff();
					m_zo_NPC2Expression[1].SwitchOn();
					m_zo_NPC2Expression[0].SwitchOff();
					m_zw_Speech.PrintF("Friend:");
					m_zw_Speech1.PrintF("Bye. Since when does he have a girlfriend? Well, anyway, it’s probably best to just get both");
					m_zw_Speech2.PrintF("flowers and chocolate, if you don’t know for sure what she would prefer. I need to go to");
					m_zw_Speech3.PrintF("basketball practice. See you later. We believe in you, so don’t mess this up.");
				
					break;
				case 7:
					m_zo_NPC2Expression[1].SwitchOff();
					m_zw_Speech.PrintF("Off they go, and I’m alone again. Well, maybe this is a good time to get Bella");
					m_zw_Speech1.PrintF("some Valentine gifts. It sure is a good idea to go for both. And once we meet,");
					m_zw_Speech2.PrintF("we can go to that café close by. I sure hope she doesn’t ditch me.");
					m_zw_Speech3.SwitchOff();
 
					break;
				case 8:
					m_zo_Textbox.SwitchOff();
					iScene++;
					iPageNumber = 0;
					m_zo_ObjectOne[0].SwitchOn();
					m_zo_ObjectTwo[0].SwitchOn();
					m_zw_Speech.SwitchOff();
					m_zw_Speech1.SwitchOff();
					m_zw_Speech2.SwitchOff();
					m_zo_Next.SwitchOn();
					m_zo_Hearts[iHalfHearts].SwitchOn();
					break;
				}
				break;

			case 2:
				m_zo_Background.SwitchOff();
				m_zo_SceneBackground[0].SwitchOn();

				switch (iPageNumber) {
				case 1:
					m_zo_NPC1Expression[0].SwitchOn();
					m_zo_NPC1Expression[1].SwitchOff();
					break;
				case 2:
					m_zo_NPC1Expression[1].SwitchOn();
					m_zo_NPC1Expression[0].SwitchOff();
					m_zo_NPC2Expression[0].SwitchOn();
					m_zo_NPC2Expression[1].SwitchOff();
					break;
				case 3:
					m_zo_NPC2Expression[1].SwitchOn();
					m_zo_NPC2Expression[0].SwitchOff();
					break;
				case 4:
					m_zo_NPC1Expression[0].SwitchOn();
					m_zo_NPC1Expression[1].SwitchOff();
					break;
				case 5:
					m_zo_NPC2Expression[0].SwitchOn();
					m_zo_NPC2Expression[1].SwitchOff();
					break;
				case 6:
					m_zo_NPC1Expression[0].SwitchOff();
					m_zo_NPC2Expression[0].SwitchOff();
					m_zo_Textbox.SwitchOff();
					iScene++;
					iPageNumber = 0;
					m_zo_ObjectOne[iScene - 1].SwitchOn();
					m_zo_ObjectTwo[iScene - 1].SwitchOn();
					break;
				}
				break;


			case 3:
				m_zo_Background.SwitchOff();
				m_zo_SceneBackground[0].SwitchOn();

				switch (iPageNumber) {
				case 1:
					m_zo_NPC1Expression[0].SwitchOn();
					m_zo_NPC1Expression[1].SwitchOff();
					break;
				case 2:
					m_zo_NPC1Expression[1].SwitchOn();
					m_zo_NPC1Expression[0].SwitchOff();
					m_zo_NPC2Expression[0].SwitchOn();
					m_zo_NPC2Expression[1].SwitchOff();
					break;
				case 3:
					m_zo_NPC2Expression[1].SwitchOn();
					m_zo_NPC2Expression[0].SwitchOff();
					break;
				case 4:
					m_zo_NPC1Expression[0].SwitchOn();
					m_zo_NPC1Expression[1].SwitchOff();
					break;
				case 5:
					m_zo_NPC2Expression[0].SwitchOn();
					m_zo_NPC2Expression[1].SwitchOff();
					break;
				case 6:
					m_zo_NPC1Expression[0].SwitchOff();
					m_zo_NPC2Expression[0].SwitchOff();
					m_zo_Textbox.SwitchOff();
					iScene++;
					iPageNumber = 0;
					m_zo_ObjectOne[iScene - 1].SwitchOn();
					m_zo_ObjectTwo[iScene - 1].SwitchOn();
					break;
				}
				break;


			case 4:
				m_zo_Background.SwitchOff();
				m_zo_SceneBackground[0].SwitchOn();

				switch (iPageNumber) {
				case 1:
					m_zo_NPC1Expression[0].SwitchOn();
					m_zo_NPC1Expression[1].SwitchOff();
					break;
				case 2:
					m_zo_NPC1Expression[1].SwitchOn();
					m_zo_NPC1Expression[0].SwitchOff();
					m_zo_NPC2Expression[0].SwitchOn();
					m_zo_NPC2Expression[1].SwitchOff();
					break;
				case 3:
					m_zo_NPC2Expression[1].SwitchOn();
					m_zo_NPC2Expression[0].SwitchOff();
					break;
				case 4:
					m_zo_NPC1Expression[0].SwitchOn();
					m_zo_NPC1Expression[1].SwitchOff();
					break;
				case 5:
					m_zo_NPC2Expression[0].SwitchOn();
					m_zo_NPC2Expression[1].SwitchOff();
					break;
				case 6:
					m_zo_NPC1Expression[0].SwitchOff();
					m_zo_NPC2Expression[0].SwitchOff();
					m_zo_Textbox.SwitchOff();
					iScene++;
					iPageNumber = 0;
					m_zo_ObjectOne[iScene - 1].SwitchOn();
					m_zo_ObjectTwo[iScene - 1].SwitchOn();
					break;
				}
				break;


			case 5:
				m_zo_Background.SwitchOff();
				m_zo_SceneBackground[0].SwitchOn();

				switch (iPageNumber) {
				case 1:
					m_zo_NPC1Expression[0].SwitchOn();
					m_zo_NPC1Expression[1].SwitchOff();
					break;
				case 2:
					m_zo_NPC1Expression[1].SwitchOn();
					m_zo_NPC1Expression[0].SwitchOff();
					m_zo_NPC2Expression[0].SwitchOn();
					m_zo_NPC2Expression[1].SwitchOff();
					break;
				case 3:
					m_zo_NPC2Expression[1].SwitchOn();
					m_zo_NPC2Expression[0].SwitchOff();
					break;
				case 4:
					m_zo_NPC1Expression[0].SwitchOn();
					m_zo_NPC1Expression[1].SwitchOff();
					break;
				case 5:
					m_zo_NPC2Expression[0].SwitchOn();
					m_zo_NPC2Expression[1].SwitchOff();
					break;
				case 6:
					m_zo_NPC1Expression[0].SwitchOff();
					m_zo_NPC2Expression[0].SwitchOff();
					m_zo_Textbox.SwitchOff();
					iScene++;
					iPageNumber = 0;
					m_zo_ObjectOne[iScene - 1].SwitchOn();
					m_zo_ObjectTwo[iScene - 1].SwitchOn();
					m_zo_Hearts[iHalfHearts].SwitchOn();
					break;
				}
				break;

			}

			iPageNumber++;
		} 
		else if (m_zdc.PickOverlayPreselected(m_zos) == m_zo_ObjectOne||m_zo_ObjectTwo) {
			m_zdc.PickOverlayPreselected(m_zos)->SwitchOff();
			iHalfHearts++;
			m_zo_Hearts[iHalfHearts].SwitchOn();
			m_zo_Hearts[iHalfHearts - 1].SwitchOff();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Next) {
			m_zo_ObjectOne->SwitchOff();
			m_zo_ObjectTwo->SwitchOff();

			switch (iScene) {
			case 2:
				m_zo_Sequence[0].SwitchOn();
				break;
			case 3:
				m_zo_Sequence[3].SwitchOn();
				break;
			case 4:
				m_zo_Sequence[6].SwitchOn();
				break;
			case 5:
				m_zo_Sequence[9].SwitchOn();
				break;
			case 6:
				m_zo_Sequence[12].SwitchOn();
				break;
			}
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[0]) {	
			m_zo_Sequence[0].SwitchOff();
			m_zo_Sequence[1].SwitchOn();
		}	
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[1]) {
			m_zo_Sequence[1].SwitchOff();
			m_zo_Sequence[2].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[2]) {
			m_zo_Sequence[2].SwitchOff();
			m_zo_SceneBackground[iScene-2].SwitchOn();
			m_zo_Textbox.SwitchOn();
			m_zo_CharacterExpression[0].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[3]) {
			m_zo_Sequence[3].SwitchOff();
			m_zo_Sequence[4].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[4]) {
			m_zo_Sequence[4].SwitchOff();
			m_zo_Sequence[5].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[5]) {
			m_zo_Sequence[5].SwitchOff();
			m_zo_SceneBackground[iScene-2].SwitchOn();
			m_zo_Textbox.SwitchOn();
			m_zo_CharacterExpression[0].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[6]) {
			m_zo_Sequence[6].SwitchOff();
			m_zo_Sequence[7].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[7]) {
			m_zo_Sequence[7].SwitchOff();
			m_zo_Sequence[8].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[8]) {
			m_zo_Sequence[8].SwitchOff();
			m_zo_SceneBackground[iScene-2].SwitchOn();
			m_zo_Textbox.SwitchOn();
			m_zo_CharacterExpression[0].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[9]) {
			m_zo_Sequence[9].SwitchOff();
			m_zo_Sequence[10].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[10]) {
			m_zo_Sequence[10].SwitchOff();
			m_zo_Sequence[11].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[11]) {
			m_zo_Sequence[11].SwitchOff();
			m_zo_SceneBackground[iScene-2].SwitchOn();
			m_zo_Textbox.SwitchOn();
			m_zo_CharacterExpression[0].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[12]) {
			m_zo_Sequence[12].SwitchOff();
			m_zo_Sequence[13].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[13]) {
			m_zo_Sequence[13].SwitchOff();
			m_zo_Sequence[14].SwitchOn();
		}
		else if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_Sequence[14]) {
			m_zo_Sequence[14].SwitchOff();
			m_zo_Textbox.SwitchOn();
			if (iHalfHearts < 6) {
				m_zo_BadEnding[0].SwitchOn();
				if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_BadEnding[0]) {
					m_zo_BadEnding[1].SwitchOn();
					m_zo_BadEnding[0].SwitchOff();
					if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_BadEnding[1]) {
						m_zo_BadEnding[2].SwitchOn();
						m_zo_BadEnding[1].SwitchOff();
					}
				}
			}
			else if (iHalfHearts < 10) {
				m_zo_NormalEnding[0].SwitchOff();
				if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_NormalEnding[0]) {
					m_zo_NormalEnding[1].SwitchOn();
					m_zo_NormalEnding[0].SwitchOff();
					if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_NormalEnding[1]) {
						m_zo_NormalEnding[2].SwitchOn();
						m_zo_NormalEnding[1].SwitchOff();
					}
				}
			}
			else {
				m_zo_HappyEnding[0].SwitchOff();
				if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_HappyEnding[0]) {
					m_zo_HappyEnding[1].SwitchOn();
					m_zo_HappyEnding[0].SwitchOff();
					if (m_zdc.PickOverlayPreselected(m_zos) == &m_zo_HappyEnding[1]) {
						m_zo_HappyEnding[2].SwitchOn();
						m_zo_HappyEnding[1].SwitchOff();
					}
				}
			}

		}
		




	}


	// Traversiere am Schluss den Szenengraf und rendere:
	m_zr.Tick(fTimeDelta);
}

void CGame::Fini()
{
	//-------------------------------
	// Finalisiere die Knotenobjekte:
	//-------------------------------

	// Hier die Finalisierung Deiner Vektoria-Objekte einfügen:

	// Auch die Root sollte finalisiert werden:   
	m_zr.Fini();
}

void CGame::WindowReSize(int iNewWidth, int iNewHeight)
{
	// Windows ReSize wird immer automatisch aufgerufen, wenn die Fenstergröße verändert wurde.
	// Hier kannst Du dann die Auflösung des Viewports neu einstellen:
	// z.B. mittels: m_zf.ReSize(iNewWidth, iNewHeight);
}

float CGame::GetTimeDeltaMin()
{
	return m_zr.GetTimeDeltaMin();
}

float CGame::GetVersion()
{
	return m_zr.GetVersion();
}


