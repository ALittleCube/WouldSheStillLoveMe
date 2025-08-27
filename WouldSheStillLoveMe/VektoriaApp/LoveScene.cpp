#include "LoveScene.h"

LoveScene::LoveScene(void) {
}

LoveScene::~LoveScene() {
}


void LoveScene::Init(int i, int j, int k) {
	iPageNumber = i;
	iPageMax = j;
	iBackground = k;
}


void LoveScene::SetFL(int i) {
	iFL = i;
}


void LoveScene::SetNPC1(int i) {
	iNPC1 = i;
}


void LoveScene::SetNPC2(int i) {
	iNPC2 = i;
}


void LoveScene::SetObject1(int i) {
	iObject1 = i;
}


void LoveScene::SetObject2(int i) {
	iObject2 = i;
}


void LoveScene::SetSequence(int i) {
	iSequence = i;
}



int LoveScene::GetPageNumber() {
	return iPageNumber;
}


void LoveScene::IncPageNumber() {
	iPageNumber++;
}

void LoveScene::Story(COverlay Background[5], COverlay FL[5], COverlay NPC1[2], COverlay NPC2[2], COverlay Object1[5], COverlay Object2[5], COverlay Sequence[20],COverlay text, CViewport view, COverlays clickable, COverlay next, CDeviceCursor m_zdc) {

	Background[iBackground].SwitchOn();

	text.SwitchOn();

	while (iPageNumber <= iPageMax) {


		if (iPageNumber == 4 || 6 || 8) {
			NPC1[0].SwitchOn();
			NPC1[1].SwitchOff();
		}
		else if (iPageNumber == 5 || 7) {
			NPC1[1].SwitchOn();
			NPC1[0].SwitchOff();
		}
		else {
			NPC1[0].SwitchOff();
			NPC1[1].SwitchOff();
		}

		if (iPageNumber == 5 || 7) {
			NPC2[0].SwitchOn();
			NPC2[1].SwitchOff();
		}
		else if (iPageNumber == 6 || 8) {
			NPC2[1].SwitchOn();
			NPC1[0].SwitchOff();
		}
		else {
			NPC2[0].SwitchOff();
			NPC2[1].SwitchOff();							//8+4=12, 12+5=17; +4=21, +5=26, +4=30, +5=35; +4=39, +6=45, +4=49
		}
		//1			2				3			4			5
		if (iPageNumber == 13 || 16 || 23 || 26 || 31 || 40) {
			FL[0].SwitchOn();
			FL[1].SwitchOff();
			FL[2].SwitchOff();
			FL[3].SwitchOff();
			FL[4].SwitchOff();
		}
		else if (iPageNumber == 14 || 17 || 22 || 33 || 41 || 43) {
			FL[1].SwitchOn();
			FL[0].SwitchOff();
			FL[2].SwitchOff();
			FL[3].SwitchOff();
			FL[4].SwitchOff();
		}
		else if (iPageNumber == 15 || 25 || 32 || 35 || 42) {
			FL[2].SwitchOn();
			FL[0].SwitchOff();
			FL[1].SwitchOff();
			FL[3].SwitchOff();
			FL[4].SwitchOff();
		}
		else if (iPageNumber == 24 || 34 || 44) {
			FL[3].SwitchOn();
			FL[0].SwitchOff();
			FL[1].SwitchOff();
			FL[2].SwitchOff();
			FL[4].SwitchOff();
		}
		else if (iPageNumber == 45) {
			FL[0].SwitchOn();
			FL[1].SwitchOff();
			FL[2].SwitchOff();
			FL[3].SwitchOff();
			FL[4].SwitchOff();
		}
		else {
			FL[0].SwitchOff();
			FL[1].SwitchOff();
			FL[2].SwitchOff();
			FL[3].SwitchOff();
			FL[4].SwitchOff();
		}

		if (iPageNumber == 9) {
			Object1[0].SwitchOn();
			Object1[1].SwitchOff();
			Object1[2].SwitchOff();
			Object1[3].SwitchOff();
			Object1[4].SwitchOff();
		}
		else if (iPageNumber == 18) {
			Object1[1].SwitchOn();
			Object1[0].SwitchOff();
			Object1[2].SwitchOff();
			Object1[3].SwitchOff();
			Object1[4].SwitchOff();
		}
		else if (iPageNumber == 27) {
			Object1[2].SwitchOn();
			Object1[0].SwitchOff();
			Object1[1].SwitchOff();
			Object1[3].SwitchOff();
			Object1[4].SwitchOff();
		}
		else if (iPageNumber == 36) {
			Object1[3].SwitchOn();
			Object1[0].SwitchOff();
			Object1[1].SwitchOff();
			Object1[2].SwitchOff();
			Object1[4].SwitchOff();
		}
		else if (iPageNumber == 46) {
			Object1[1].SwitchOn();
			Object1[0].SwitchOff();
			Object1[2].SwitchOff();
			Object1[3].SwitchOff();
			Object1[4].SwitchOff();
		}
		else {
			Object1[0].SwitchOff();
			Object1[1].SwitchOff();
			Object1[2].SwitchOff();
			Object1[3].SwitchOff();
			Object1[4].SwitchOff();
		}

		if (iPageNumber == 9) {
			Object2[0].SwitchOn();
			Object2[1].SwitchOff();
			Object2[2].SwitchOff();
			Object2[3].SwitchOff();
			Object2[4].SwitchOff();
		}
		else if (iPageNumber == 18) {
			Object2[1].SwitchOn();
			Object2[0].SwitchOff();
			Object2[2].SwitchOff();
			Object2[3].SwitchOff();
			Object2[4].SwitchOff();
		}
		else if (iPageNumber == 27) {
			Object2[2].SwitchOn();
			Object2[0].SwitchOff();
			Object2[1].SwitchOff();
			Object2[3].SwitchOff();
			Object2[4].SwitchOff();
		}
		else if (iPageNumber == 36) {
			Object2[3].SwitchOn();
			Object2[0].SwitchOff();
			Object2[1].SwitchOff();
			Object2[2].SwitchOff();
			Object2[4].SwitchOff();
		}
		else if (iPageNumber == 46) {
			Object2[1].SwitchOn();
			Object2[0].SwitchOff();
			Object2[2].SwitchOff();
			Object2[3].SwitchOff();
			Object2[4].SwitchOff();
		}
		else {
			Object2[0].SwitchOff();
			Object2[1].SwitchOff();
			Object2[2].SwitchOff();
			Object2[3].SwitchOff();
			Object2[4].SwitchOff();
		}
		switch (iPageNumber) {
		case 10:
			Sequence[0].SwitchOn();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 11:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOn();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 12:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOn();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 19:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOn();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 20:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOn();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 21:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOn();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 28:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOn();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 29:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOn();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 30:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOn();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 37:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOn();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 38:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOn();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 39:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOn();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 47:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOn();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 48:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOn();
			Sequence[18].SwitchOff();
			Sequence[19].SwitchOff();
		case 49:
			Sequence[0].SwitchOff();
			Sequence[1].SwitchOff();
			Sequence[2].SwitchOff();
			Sequence[3].SwitchOff();
			Sequence[4].SwitchOff();
			Sequence[5].SwitchOff();
			Sequence[6].SwitchOff();
			Sequence[7].SwitchOff();
			Sequence[8].SwitchOff();
			Sequence[9].SwitchOff();
			Sequence[10].SwitchOff();
			Sequence[11].SwitchOff();
			Sequence[12].SwitchOff();
			Sequence[13].SwitchOff();
			Sequence[14].SwitchOff();
			Sequence[15].SwitchOff();
			Sequence[16].SwitchOff();
			Sequence[17].SwitchOff();
			Sequence[18].SwitchOn();
			Sequence[19].SwitchOff();

		} 

		//insert Icons for hearts

		/*
		if (iPageNumber = 9 || 18 || 27 || 36 || 46) {
			Hearts[iHalfHearts].SwitchOn();
			if (iHalfHearts > 0) {
				Hearts[iHalfHearts - 1].SwitchOff();
			}
			next.SwitchOn();
		}
		else {
			Hearts[iHalfHearts].SwitchOff();
			next.SwitchOff();
		}
		*/ 
		
		//insert click-page-counter

		if (m_zdc.PickOverlayPreselected(clickable) == &Object1[0]||&Object1[1]||&Object1[2]||&Object1[3]||&Object1[4]|| &Object2[0] || &Object2[1] || &Object2[2] || &Object2[3] || &Object2[4]) {
			iHalfHearts++;
		}

		if (m_zdc.PickOverlayPreselected(clickable) == &text || &next || &Sequence[1] || &Sequence[5] || &Sequence[9] || &Sequence[13] || &Sequence[17]) {
			iPageNumber++;
		} 
		else if (m_zdc.PickOverlayPreselected(clickable) == &Sequence[0] ||&Sequence[2] || &Sequence[4] ||&Sequence[6]|| &Sequence[8] ||&Sequence[10] || &Sequence[12] ||&Sequence[14] || &Sequence[16]||&Sequence[18]) {
			iPageNumber += 2;
		} 

	
			
			
		



	}


	


}

void LoveScene::SetPageNumber(int i) {
	iPageNumber = i;
}



void LoveScene::SetMaxNumber(int i) {
	iPageMax = i;
}



void LoveScene::SetBackground(int i) {
	iBackground = i;
}