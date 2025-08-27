#pragma once

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


class LoveScene
{
public:
	//consturctor and destructor
	LoveScene(void);
	~LoveScene(void);

	//Init weil pain
	void Init(int i, int j, int k);

	//Things
	void SetFL(int i);
	void SetNPC1(int i);
	void SetNPC2(int i);
	void SetObject1(int i);
	void SetObject2(int i);
	void SetSequence(int i);
	int GetPageNumber();
	void IncPageNumber();
	void Story(COverlay Background[5], COverlay FL[5], COverlay NPC1[2], COverlay NPC2[2], COverlay Object1[5], COverlay Object2[5], COverlay Sequence[20], COverlay text, CViewport view, COverlays clickable, COverlay next, CDeviceCursor m_zdc);
	void SetPageNumber(int i);
	void SetMaxNumber(int i);
	void SetBackground(int i);


private:
	int iBackground;
	int iPageNumber;
	int iPageMax;
	int iHalfHearts;
	int iFL;
	int iNPC1;
	int iNPC2;
	int iObject1;
	int iObject2;
	int iSequence;


};

