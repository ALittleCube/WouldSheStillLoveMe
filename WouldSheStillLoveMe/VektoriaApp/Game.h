#pragma once
//-----------------------------------------------------------------------
// CGame
// 
// Erklärung : Eine weitestgehend leere Klasse, 
//             sinnfällig in eine Windows-Applikation eingebettet,
//             um ein Spiel bzw. eine 3D-Simulation zu erzeugen
// Autor     : Prof. Dr. Tobias Breiner
// Ort       : Pfungstadt
// Zeit      : seit Aug. 2011 (mit seitdem ständigen Verbesserungs-Updates)
// Copyright : Tobias Breiner  
// Disclaimer: Nutzung auf eigene Gefahr, keine Gewähr, no warranty!
//------------------------------------------------------------------------


#ifdef _WIN64
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug64.lib")
#pragma comment (lib, "VektoriaMath_Debug64.lib")
#else
#pragma comment (lib, "Vektoria_Release64.lib")
#pragma comment (lib, "VektoriaMath_Release64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment (lib, "Vektoria_Debug.lib")
#pragma comment (lib, "VektoriaMath_Debug.lib")
#else
#pragma comment (lib, "Vektoria_Release.lib")
#pragma comment (lib, "VektoriaMath_Release.lib")
#endif
#endif


#include "Vektoria\Root.h"

using namespace Vektoria;

#include "LoveScene.h"


class CGame
{
public:
	// Wird vor Begin einmal aufgerufen (Konstruktor):
	CGame(void);

	// Wird nach Ende einmal aufgerufen (Destruktor):
	~CGame(void);

	// Wird zu Begin einmal aufgerufen:
	void Init(HWND hwnd, void(*procOS)(HWND hwnd, unsigned int uWndFlags), CSplash* psplash);

	// Wird während der Laufzeit bei jedem Bildaufbau aufgerufen:
	void Tick(float fTime, float fTimeDelta);

	// Wird am Ende einmal aufgerufen:
	void Fini();

	// Wird immer dann aufgerufen, wenn der Benutzer die Fenstergröße verändert hat:
	void WindowReSize(int iNewWidth, int iNewHeight);

	// Holt das minimale Zeitdelta zur eventuellen Frame-Rate-Beschränkung:
	float GetTimeDeltaMin();

	// Holt die Versionsnummer:
	float GetVersion();


private:

	// Die Wurzel des Szenengrafen: 
	CRoot m_zr;

	// Hier ist Platz für Deine weiteren Vektoriaobjekte:

	// Sachen sehen ist toll
	CFrame m_zf;
	CViewport m_zv;
	CScene m_zs;
	CPlacement m_zp;
	CCamera m_zc;

	// Start Screen
	COverlay m_zo_Background;
	COverlay m_zo_Start;
	COverlay m_zo_Credits;
	COverlays m_zos;

	// Beginning
	COverlay m_zo_Mirror;
	COverlay m_zo_Textbox;

	//FL all scenes
	COverlay m_zo_CharacterExpression[5];


	//Background
	COverlay m_zo_SceneBackground[5];

	//NPCs first scene specific
	COverlay m_zo_NPC1Expression[2];
	COverlay m_zo_NPC2Expression[2];

	//objects
	COverlay m_zo_ObjectOne[5];
	COverlay m_zo_ObjectTwo[5];

	//sequence 
	COverlay m_zo_Sequence[15];

	//moving on button
	COverlay m_zo_Next;

	// ending
	COverlay m_zo_BadEnding[3];
	COverlay m_zo_NormalEnding[5];
	COverlay m_zo_HappyEnding[9];


	//Cursor
	CDeviceCursor m_zdc;

	//Page
	int iPageNumber;

	//Scenes
	int iScene;

	//HeartCounter
	int iHalfHearts;
	COverlay m_zo_Hearts[11];

	//Timer
	int iTicks;

	//Text
	CWriting m_zw_Speech;
	CWriting m_zw_Speech1;
	CWriting m_zw_Speech2;
	CWriting m_zw_Speech3;
	CWritingFont m_zwf_Speech;



};


