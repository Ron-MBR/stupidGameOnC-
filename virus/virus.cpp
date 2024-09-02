#include<graphics.h>
#include<windows.h>
//#include <mmsystem.h>//sndPlaySound
//#pragma comment(lib,"winmm.lib")//sndPlaySound
#include<iostream>
#include<cstdlib>
#include<math.h>
#include <ctime>

#define IDC_MY_EDIT_ONE 10

#define NumWall 500
#define NumEn 4
#define NumKey 6

using namespace std;
void game();

int curKey;

HWND hwnd; 

 time_t t[NumEn];
//time for random
//t=time(0);

int ColKey=NumKey;
 
 bool work=0;
 bool pricel=0;
 int colWal=NumWall;
 bool red=0;
 bool con=0;	
 int ver=0;
 
 int moveX;
 int moveY;
 
 int current;
 long teleport[NumEn];
 
 HWND COP;
 WPARAM cwp;
 LPARAM clp;
 HINSTANCE g_hinst;
 
 struct pointy{
 	int eqX;
 	int eqY;
 	int col;
 };
 
 struct wall{
 	long x;
 	long y;
 	long hWidth;
 	long hHigh;
 	int ySpeed;
 	int xSpeed;
 	bool exist;
 
 };
 
 struct key{
 	long x;
 	long y;
 	bool exist;
 };
 
 struct gamer{
 	long x;
 	long y;
 	int radX;
 	int radY;
 	int ySpeed;
 	int xSpeed;
 	int currentSpeedX;
 	int currentSpeedY;
 	int LcurrentSpeedX;
 	int LcurrentSpeedY;
 	int action;
	int coffHeat;
	int kind;
	bool exist;
 	
 };
 
 int sign(int a) {
  if (a > 0) {
    return -1;
  } else if (a == 0) {
    return 0;
  } else {
    return 1;
  }
  };
 
 gamer player;

 
 wall Wall[NumWall];
 pointy PG[20];
 pointy EG[20];
 pointy KEY[5];
 
 key Key[NumKey];
 gamer enemy[NumEn];
 int colEn=NumEn-1;
 gamer look;

LRESULT CALLBACK WndProc(  HWND hownd, UINT Message, WPARAM  wParam, LPARAM lParam);




int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {


setlocale(LC_ALL, "Russian");



/////////////////
PG[0].eqX=-3;
PG[0].eqY=-3;
PG[0].col=12;

PG[1].eqX=-4;
PG[1].eqY=-3;
PG[1].col=12;

PG[2].eqX=-3;
PG[2].eqY=-4;
PG[2].col=12;

PG[3].eqX=-4;
PG[3].eqY=-4;
PG[3].col=12;

PG[4].eqX=3;
PG[4].eqY=-3;
PG[4].col=12;

PG[5].eqX=4;
PG[5].eqY=-3;
PG[5].col=12;

PG[6].eqX=3;
PG[6].eqY=-4;
PG[6].col=12;

PG[7].eqX=4;
PG[7].eqY=-4;
PG[7].col=12;

PG[8].eqX=0;
PG[8].eqY=4;
PG[8].col=12;

PG[9].eqX=0;
PG[9].eqY=3;
PG[9].col=12;

PG[10].eqX=1;
PG[10].eqY=3;
PG[10].col=12;

PG[11].eqX=1;
PG[11].eqY=4;
PG[11].col=12;

PG[12].eqX=-1;
PG[12].eqY=3;
PG[12].col=12;

PG[13].eqX=-1;
PG[13].eqY=4;
PG[13].col=12;

PG[14].eqX=2;
PG[14].eqY=3;
PG[14].col=12;

PG[15].eqX=-2;
PG[15].eqY=3;
PG[15].col=12;

PG[16].eqX=-3;
PG[16].eqY=2;
PG[16].col=12;

PG[17].eqX=3;
PG[17].eqY=2;
PG[17].col=12;


EG[0].eqX=2;
EG[0].eqY=-3;
EG[0].col=10;

EG[1].eqX=2;
EG[1].eqY=-2;
EG[1].col=10;

EG[2].eqX=-2;
EG[2].eqY=-3;
EG[2].col=10;

EG[3].eqX=-2;
EG[3].eqY=-2;
EG[3].col=10;

EG[4].eqX=-2;
EG[4].eqY=-1;
EG[4].col=10;

EG[5].eqX=3;
EG[5].eqY=2;
EG[5].col=10;

EG[6].eqX=3;
EG[6].eqY=1;
EG[6].col=10;

EG[7].eqX=2;
EG[7].eqY=3;
EG[7].col=10;

EG[9].eqX=1;
EG[9].eqY=4;
EG[9].col=10;

EG[10].eqX=0;
EG[10].eqY=4;
EG[10].col=10;
///////////////////
 player.radX=4*3;
 player.radY=4*3;
 player.x=3+player.radX;
 player.y=3+player.radY;
 player.ySpeed=3;
 player.xSpeed=3;
 player.coffHeat=1;
 
 t[0]=time(0);
 cout<<t[0]<<"\n";
 current=t[0]%3000;
 cout<<current<<"\n";
 
 enemy[0].radX=4*3;
 enemy[0].radY=4*3;
 enemy[0].x=current;
 enemy[0].y=3000-current;
 enemy[0].ySpeed=4;
 enemy[0].xSpeed=3;
 
 enemy[1].radX=4*3;
 enemy[1].radY=4*3;
 enemy[1].x=current*-1;
 enemy[1].y=(3000-current)*-1;
 enemy[1].ySpeed=4;
 enemy[1].xSpeed=3;
 
 enemy[2].radX=4*3;
 enemy[2].radY=4*3;
 enemy[2].x=100;
 enemy[2].y=700;
 enemy[2].ySpeed=7;
 enemy[2].xSpeed=7;
 enemy[2].kind=1;

 enemy[3].radX=4*3;
 enemy[3].radY=4*3;
 enemy[3].x=200;
 enemy[3].y=-200;
 enemy[3].ySpeed=7;
 enemy[3].xSpeed=7;
 enemy[3].kind=1;



////////wall

Wall[0].x=284;
Wall[0].y=318;
Wall[0].hHigh=10;
Wall[0].hWidth=260;
 
Wall[1].x=36;
Wall[1].y=571;
Wall[1].hHigh=160;
Wall[1].hWidth=10;
 
Wall[2].x=287;
Wall[2].y=474;
Wall[2].hHigh=150;
Wall[2].hWidth=10;
 
Wall[3].x=289;
Wall[3].y=507;
Wall[3].hHigh=10;
Wall[3].hWidth=150;
 
Wall[4].x=341;
Wall[4].y=720;
Wall[4].hHigh=10;
Wall[4].hWidth=200;
 
Wall[5].x=532;
Wall[5].y=560;
Wall[5].hHigh=170;
Wall[5].hWidth=10;
 
Wall[6].x=204;
Wall[6].y=467;
Wall[6].hHigh=50;
Wall[6].hWidth=10;
 
Wall[7].x=120;
Wall[7].y=374;
Wall[7].hHigh=50;
Wall[7].hWidth=10;
 
Wall[8].x=188;
Wall[8].y=669;
Wall[8].hHigh=50;
Wall[8].hWidth=10;
 
Wall[9].x=158;
Wall[9].y=623;
Wall[9].hHigh=10;
Wall[9].hWidth=40;
 
Wall[10].x=463;
Wall[10].y=417;
Wall[10].hHigh=10;
Wall[10].hWidth=60;
 
Wall[11].x=408;
Wall[11].y=610;
Wall[11].hHigh=10;
Wall[11].hWidth=40;
 
Wall[12].x=-284;
Wall[12].y=535;
Wall[12].hHigh=450;
Wall[12].hWidth=10;
 
Wall[13].x=309;
Wall[13].y=99;
Wall[13].hHigh=10;
Wall[13].hWidth=420;
 
Wall[14].x=738;
Wall[14].y=289;
Wall[14].hHigh=200;
Wall[14].hWidth=10;
 
Wall[15].x=-175;
Wall[15].y=-65;
Wall[15].hHigh=0;
Wall[15].hWidth=0;
 
Wall[16].x=741;
Wall[16].y=777;
Wall[16].hHigh=198;
Wall[16].hWidth=10;
 
Wall[17].x=298;
Wall[17].y=971;
Wall[17].hHigh=10;
Wall[17].hWidth=453;
 
Wall[18].x=945;
Wall[18].y=479;
Wall[18].hHigh=10;
Wall[18].hWidth=215;
 
Wall[19].x=836;
Wall[19].y=589;
Wall[19].hHigh=10;
Wall[19].hWidth=103;
 
Wall[20].x=1049;
Wall[20].y=637;
Wall[20].hHigh=62;
Wall[20].hWidth=10;
 
Wall[21].x=896;
Wall[21].y=689;
Wall[21].hHigh=10;
Wall[21].hWidth=58;
 
Wall[22].x=1144;
Wall[22].y=639;
Wall[22].hHigh=63;
Wall[22].hWidth=10;
 
Wall[23].x=959;
Wall[23].y=779;
Wall[23].hHigh=100;
Wall[23].hWidth=10;
 
Wall[24].x=851;
Wall[24].y=994;
Wall[24].hHigh=200;
Wall[24].hWidth=10;
 
Wall[25].x=944;
Wall[25].y=965;
Wall[25].hHigh=10;
Wall[25].hWidth=100;
 
Wall[26].x=1095;
Wall[26].y=869;
Wall[26].hHigh=10;
Wall[26].hWidth=128;
 
Wall[27].x=1135;
Wall[27].y=1075;
Wall[27].hHigh=116;
Wall[27].hWidth=10;
 
Wall[28].x=1045;
Wall[28].y=1189;
Wall[28].hHigh=10;
Wall[28].hWidth=100;
 
Wall[29].x=1232;
Wall[29].y=931;
Wall[29].hHigh=72;
Wall[29].hWidth=10;
 
Wall[30].x=1233;
Wall[30].y=1184;
Wall[30].hHigh=99;
Wall[30].hWidth=10;
 
Wall[31].x=-175;
Wall[31].y=-65;
Wall[31].hHigh=0;
Wall[31].hWidth=0;
 
Wall[32].x=955;
Wall[32].y=1232;
Wall[32].hHigh=53;
Wall[32].hWidth=10;
 
Wall[33].x=865;
Wall[33].y=1275;
Wall[33].hHigh=10;
Wall[33].hWidth=100;
 
Wall[34].x=1091;
Wall[34].y=1349;
Wall[34].hHigh=59;
Wall[34].hWidth=10;
 
Wall[35].x=1101;
Wall[35].y=1398;
Wall[35].hHigh=10;
Wall[35].hWidth=259;
 
Wall[36].x=1341;
Wall[36].y=1273;
Wall[36].hHigh=10;
Wall[36].hWidth=100;
 
Wall[37].x=1447;
Wall[37].y=1562;
Wall[37].hHigh=299;
Wall[37].hWidth=10;
 
Wall[38].x=559;
Wall[38].y=1269;
Wall[38].hHigh=10;
Wall[38].hWidth=403;
 
Wall[39].x=1099;
Wall[39].y=1851;
Wall[39].hHigh=10;
Wall[39].hWidth=344;
 
Wall[40].x=852;
Wall[40].y=1544;
Wall[40].hHigh=142;
Wall[40].hWidth=10;
 
Wall[41].x=1349;
Wall[41].y=1619;
Wall[41].hHigh=142;
Wall[41].hWidth=10;
 
Wall[42].x=1100;
Wall[42].y=1765;
Wall[42].hHigh=10;
Wall[42].hWidth=259;
 
Wall[43].x=1010;
Wall[43].y=1673;
Wall[43].hHigh=100;
Wall[43].hWidth=10;
 
Wall[44].x=1032;
Wall[44].y=1569;
Wall[44].hHigh=10;
Wall[44].hWidth=100;
 
Wall[45].x=943;
Wall[45].y=1448;
Wall[45].hHigh=42;
Wall[45].hWidth=10;
 
Wall[46].x=1063;
Wall[46].y=1525;
Wall[46].hHigh=54;
Wall[46].hWidth=10;
 
Wall[47].x=1216;
Wall[47].y=1523;
Wall[47].hHigh=135;
Wall[47].hWidth=10;
 
Wall[48].x=1164;
Wall[48].y=1661;
Wall[48].hHigh=10;
Wall[48].hWidth=62;
 
Wall[49].x=-180;
Wall[49].y=-65;
Wall[49].hHigh=0;
Wall[49].hWidth=0;
 
Wall[50].x=757;
Wall[50].y=1207;
Wall[50].hHigh=100;
Wall[50].hWidth=10;
 
Wall[51].x=800;
Wall[51].y=1116;
Wall[51].hHigh=10;
Wall[51].hWidth=43;
 
Wall[52].x=757;
Wall[52].y=1558;
Wall[52].hHigh=303;
Wall[52].hWidth=10;
 
Wall[53].x=570;
Wall[53].y=1070;
Wall[53].hHigh=100;
Wall[53].hWidth=10;
 
Wall[54].x=613;
Wall[54].y=1160;
Wall[54].hHigh=10;
Wall[54].hWidth=34;
 
Wall[55].x=457;
Wall[55].y=1214;
Wall[55].hHigh=55;
Wall[55].hWidth=10;
 
Wall[56].x=454;
Wall[56].y=1020;
Wall[56].hHigh=49;
Wall[56].hWidth=10;
 
Wall[57].x=414;
Wall[57].y=1060;
Wall[57].hHigh=10;
Wall[57].hWidth=50;
 
Wall[58].x=358;
Wall[58].y=1110;
Wall[58].hHigh=60;
Wall[58].hWidth=10;
 
Wall[59].x=167;
Wall[59].y=1173;
Wall[59].hHigh=100;
Wall[59].hWidth=11;
 
Wall[60].x=318;
Wall[60].y=1172;
Wall[60].hHigh=10;
Wall[60].hWidth=50;
 
Wall[61].x=108;
Wall[61].y=1063;
Wall[61].hHigh=10;
Wall[61].hWidth=167;
 
Wall[62].x=-146;
Wall[62].y=1111;
Wall[62].hHigh=150;
Wall[62].hWidth=10;
 
Wall[63].x=-41;
Wall[63].y=1271;
Wall[63].hHigh=10;
Wall[63].hWidth=115;
 
Wall[64].x=-49;
Wall[64].y=1127;
Wall[64].hHigh=59;
Wall[64].hWidth=10;
 
Wall[65].x=-180;
Wall[65].y=-65;
Wall[65].hHigh=0;
Wall[65].hWidth=0;
 
Wall[66].x=-283;
Wall[66].y=1181;
Wall[66].hHigh=100;
Wall[66].hWidth=10;
 
Wall[67].x=64;
Wall[67].y=1311;
Wall[67].hHigh=50;
Wall[67].hWidth=10;
 
Wall[68].x=268;
Wall[68].y=1350;
Wall[68].hHigh=10;
Wall[68].hWidth=210;
 
Wall[69].x=658;
Wall[69].y=1599;
Wall[69].hHigh=257;
Wall[69].hWidth=10;
 
Wall[70].x=455;
Wall[70].y=1567;
Wall[70].hHigh=215;
Wall[70].hWidth=10;
 
Wall[71].x=514;
Wall[71].y=1418;
Wall[71].hHigh=10;
Wall[71].hWidth=68;
 
Wall[72].x=596;
Wall[72].y=1498;
Wall[72].hHigh=10;
Wall[72].hWidth=68;
 
Wall[73].x=515;
Wall[73].y=1579;
Wall[73].hHigh=10;
Wall[73].hWidth=68;
 
Wall[74].x=596;
Wall[74].y=1657;
Wall[74].hHigh=10;
Wall[74].hWidth=68;
 
Wall[75].x=513;
Wall[75].y=1740;
Wall[75].hHigh=10;
Wall[75].hWidth=68;
 
Wall[76].x=264;
Wall[76].y=1851;
Wall[76].hHigh=10;
Wall[76].hWidth=404;
 
Wall[77].x=244;
Wall[77].y=1656;
Wall[77].hHigh=200;
Wall[77].hWidth=11;
 
Wall[78].x=397;
Wall[78].y=1773;
Wall[78].hHigh=10;
Wall[78].hWidth=68;
 
Wall[79].x=316;
Wall[79].y=1692;
Wall[79].hHigh=10;
Wall[79].hWidth=68;
 
Wall[80].x=392;
Wall[80].y=1617;
Wall[80].hHigh=10;
Wall[80].hWidth=68;
 
Wall[81].x=312;
Wall[81].y=1538;
Wall[81].hHigh=10;
Wall[81].hWidth=68;
 
Wall[82].x=396;
Wall[82].y=1454;
Wall[82].hHigh=10;
Wall[82].hWidth=68;
 
Wall[83].x=64;
Wall[83].y=1546;
Wall[83].hHigh=221;
Wall[83].hWidth=10;
 
Wall[84].x=192;
Wall[84].y=1501;
Wall[84].hHigh=10;
Wall[84].hWidth=44;
 
Wall[85].x=110;
Wall[85].y=1580;
Wall[85].hHigh=10;
Wall[85].hWidth=44;
 
Wall[86].x=189;
Wall[86].y=1656;
Wall[86].hHigh=10;
Wall[86].hWidth=44;
 
Wall[87].x=112;
Wall[87].y=1734;
Wall[87].hHigh=10;
Wall[87].hWidth=44;
 
Wall[88].x=-180;
Wall[88].y=-65;
Wall[88].hHigh=0;
Wall[88].hWidth=0;
 
Wall[89].x=-143;
Wall[89].y=1634;
Wall[89].hHigh=227;
Wall[89].hWidth=10;
 
Wall[90].x=-461;
Wall[90].y=975;
Wall[90].hHigh=10;
Wall[90].hWidth=170;
 
Wall[91].x=-422;
Wall[91].y=1091;
Wall[91].hHigh=10;
Wall[91].hWidth=130;
 
Wall[92].x=-542;
Wall[92].y=1340;
Wall[92].hHigh=240;
Wall[92].hWidth=10;
 
Wall[93].x=-629;
Wall[93].y=1242;
Wall[93].hHigh=277;
Wall[93].hWidth=10;
 
Wall[94].x=-908;
Wall[94].y=1509;
Wall[94].hHigh=10;
Wall[94].hWidth=277;
 
Wall[95].x=-894;
Wall[95].y=1587;
Wall[95].hHigh=10;
Wall[95].hWidth=362;
 
Wall[96].x=-1266;
Wall[96].y=1320;
Wall[96].hHigh=277;
Wall[96].hWidth=10;
 
Wall[97].x=-1362;
Wall[97].y=1205;
Wall[97].hHigh=240;
Wall[97].hWidth=10;
 
Wall[98].x=-1000;
Wall[98].y=975;
Wall[98].hHigh=10;
Wall[98].hWidth=362;
 
Wall[99].x=-989;
Wall[99].y=1053;
Wall[99].hHigh=10;
Wall[99].hWidth=277;
 
Wall[100].x=-1175;
Wall[100].y=1319;
Wall[100].hHigh=190;
Wall[100].hWidth=10;
 
Wall[101].x=-722;
Wall[101].y=1243;
Wall[101].hHigh=190;
Wall[101].hWidth=10;
 
Wall[102].x=-993;
Wall[102].y=1139;
Wall[102].hHigh=10;
Wall[102].hWidth=184;
 
Wall[103].x=-901;
Wall[103].y=1423;
Wall[103].hHigh=10;
Wall[103].hWidth=184;
 
Wall[104].x=-1075;
Wall[104].y=1321;
Wall[104].hHigh=100;
Wall[104].hWidth=10;
 
Wall[105].x=-819;
Wall[105].y=1246;
Wall[105].hHigh=100;
Wall[105].hWidth=10;
 
Wall[106].x=-330;
Wall[106].y=1271;
Wall[106].hHigh=10;
Wall[106].hWidth=40;
 
Wall[107].x=-497;
Wall[107].y=1273;
Wall[107].hHigh=10;
Wall[107].hWidth=40;
 
Wall[108].x=-414;
Wall[108].y=1187;
Wall[108].hHigh=10;
Wall[108].hWidth=40;
 

////////wall

//////////key
srand(time(0));
for(int rer=0;rer<NumKey;rer++){
 Key[rer].x=rand()%2000;
 Key[rer].y=rand()%2000;
 cout<<Key[rer].x<<endl;
 cout<<Key[rer].y<<endl;
 cout<<" "<<endl;
 bool ss=1;
 while(ss==1){
   bool s=0;
   for(int ror=0;ror<rer;ror++){
   	 if((abs(Key[rer].x-Key[ror].x)<300)&&(abs(Key[rer].y-Key[ror].y)<300)){
   	 	s=1;
		}
   };
   if(s){
   	 Key[rer].x=rand()%2000;
     Key[rer].y=rand()%2000;
   }else{
   	ss=0;
   }	
 };
 bool sss=1;
 while(sss==1){
  sss=0;
 	for(int rra=0;rra<colWal;rra++){
 	  if(abs(Key[rer].x-Wall[rra].x)<=(5+Wall[rra].hWidth)&&abs(Key[rer].y-Wall[rra].y)<=(5+Wall[rra].hHigh)){
 	  	Key[rer].x++;
 	  	Key[rer].y++;
 	  	sss=1;
	   };	
	 };
 };
 
};

 
//////////key




initwindow(1200,800);

	WNDCLASSEX wc;
	
	MSG msg;

    
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; 
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(	WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 
		CW_USEDEFAULT, 
		100, 
		100	, 
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	
	g_hinst = hInstance;

	while(red==0/*GetMessage(&msg, NULL, 0, 0) > 0*/) {
	
		GetMessage(&msg, NULL, 0, 0) ;
		TranslateMessage(&msg); 
		DispatchMessage(&msg);
	    if(con==1){
		PostMessageW(COP, 84,cwp ,clp);};}
	return msg.wParam;
}

///////////////////////////////////////


LRESULT CALLBACK WndProc(  HWND hownd, UINT Message, WPARAM  wParam, LPARAM lParam) {
	switch(Message) {
		case WM_DESTROY: {
			red=1;
			break;
		}
	
		case 84:{
		    //cout<<"Hello";
		    
		    if(work==0){
			game();};
			
			delay(5);
			break;
		}
		case WM_KEYDOWN: {
			
	        con=1;
			COP=hownd;
			cwp=wParam;
			clp=lParam;
			
			
			
			switch(wParam){
				case VK_RIGHT:{
					player.currentSpeedX=player.xSpeed;
					player.currentSpeedY=0;
					break;
				}
				case VK_LEFT:{
					player.currentSpeedX=-1*player.xSpeed;
					player.currentSpeedY=0;
					break;
				}
				case VK_DOWN:{
					player.currentSpeedX=0;
					player.currentSpeedY=player.ySpeed;
					break;
				}
				case VK_UP:{
					player.currentSpeedX=0;
					player.currentSpeedY=-1*player.ySpeed;
					break;
				}
			}
			break;
		}
		
		case WM_CREATE: {
			
	
            
			break;
		}
		default:
			return DefWindowProc(hownd, Message, wParam, lParam);
	}
	return 0;
}

void stickPaint(int drX,int drY,int address){
	switch(address){
	 case 0:{
	 	for(int tet=0;tet<=17;tet++){
	 	  putpixel(drX+PG[tet].eqX*3,drY+PG[tet].eqY*3,PG[tet].col);
		  putpixel(drX+PG[tet].eqX*3,drY+1+PG[tet].eqY*3,PG[tet].col);
		  putpixel(drX+PG[tet].eqX*3,drY-1+PG[tet].eqY*3,PG[tet].col);	
		  
		  putpixel(drX+1+PG[tet].eqX*3,drY+PG[tet].eqY*3,PG[tet].col);
		  putpixel(drX+1+PG[tet].eqX*3,drY+1+PG[tet].eqY*3,PG[tet].col);
		  putpixel(drX+1+PG[tet].eqX*3,drY-1+PG[tet].eqY*3,PG[tet].col);
		  
		  putpixel(drX-1+PG[tet].eqX*3,drY+PG[tet].eqY*3,PG[tet].col);
		  putpixel(drX-1+PG[tet].eqX*3,drY+1+PG[tet].eqY*3,PG[tet].col);
		  putpixel(drX-1+PG[tet].eqX*3,drY-1+PG[tet].eqY*3,PG[tet].col);
		 };
		break;
	 }
	 case 1:{
	 	for(int tet=0;tet<=17;tet++){
	 	  putpixel(drX+EG[tet].eqX*3,drY+EG[tet].eqY*3,EG[tet].col);
		  putpixel(drX+EG[tet].eqX*3,drY+1+EG[tet].eqY*3,EG[tet].col);
		  putpixel(drX+EG[tet].eqX*3,drY-1+EG[tet].eqY*3,EG[tet].col);	
		  
		  putpixel(drX+1+EG[tet].eqX*3,drY+EG[tet].eqY*3,EG[tet].col);
		  putpixel(drX+1+EG[tet].eqX*3,drY+1+EG[tet].eqY*3,EG[tet].col);
		  putpixel(drX+1+EG[tet].eqX*3,drY-1+EG[tet].eqY*3,EG[tet].col);
		  
		  putpixel(drX-1+EG[tet].eqX*3,drY+EG[tet].eqY*3,EG[tet].col);
		  putpixel(drX-1+EG[tet].eqX*3,drY+1+EG[tet].eqY*3,EG[tet].col);
		  putpixel(drX-1+EG[tet].eqX*3,drY-1+EG[tet].eqY*3,EG[tet].col);
		 };
		break;
	 }		
	};
	
}

void windowMove(){
	moveX=round((600-player.x)/30);
	moveY=round((400-player.y)/30);
	
	player.x=player.x+moveX;
	player.y=player.y+moveY;
	
	for(int rar=0;rar<=colEn;rar++){
	enemy[rar].x=enemy[rar].x+moveX;
	enemy[rar].y=enemy[rar].y+moveY;};
	
	for(int ara=0;ara<=colWal;ara++){
	 Wall[ara].x=Wall[ara].x+moveX;
	 Wall[ara].y=Wall[ara].y+moveY;
	}
	
	for(int ara=0;ara<=ColKey;ara++){
	 Key[ara].x=Key[ara].x+moveX;
	 Key[ara].y=Key[ara].y+moveY;
	}
}

void _paint()
{
 setfillstyle(1,0);
 bar(0,0,1200,800);
 setfillstyle(1,7);
 stickPaint(player.x,player.y,1);
 
 for(int aar=0;aar<=colEn;aar++){
 stickPaint(enemy[aar].x,enemy[aar].y,0);};
 setfillstyle(1,1);
 for(int ara=0;ara<=colWal;ara++){
 	bar(Wall[ara].x-Wall[ara].hWidth,Wall[ara].y-Wall[ara].hHigh,Wall[ara].x+Wall[ara].hWidth,Wall[ara].y+Wall[ara].hHigh);
 };
 
 setfillstyle(1,7);
 for(int ara=0;ara<=ColKey;ara++){
 	if(Key[ara].exist==0){
 	bar(Key[ara].x-5,Key[ara].y-5,Key[ara].x+5,Key[ara].y+5);}
 };
}

void physics()
{
	
 windowMove();
 
 if(!(GetKeyState(VK_LEFT) & 0x8000)&&!(GetKeyState(VK_RIGHT) & 0x8000)&&!(GetKeyState(VK_UP) & 0x8000)&&!(GetKeyState(VK_DOWN) & 0x8000))
{
  
 	player.currentSpeedX=0;
 	player.currentSpeedY=0;
 
}
 

 for(int ar=0;ar<=colWal;ar++){
 if((player.x+player.radX>=Wall[ar].x-Wall[ar].hWidth-player.xSpeed)&&(player.x+player.radX<=Wall[ar].x-Wall[ar].hWidth)&&(abs(player.y-Wall[ar].y)<=player.radY+Wall[ar].hHigh)){
 	player.x=player.x-player.xSpeed;
 };
 
 if((player.x-player.radX<=Wall[ar].x+Wall[ar].hWidth+player.xSpeed)&&(player.x-player.radX>=Wall[ar].x+Wall[ar].hWidth)&&(abs(player.y-Wall[ar].y)<=player.radY+Wall[ar].hHigh)){
 	player.x=player.x+player.xSpeed;
 };
 
 if((player.y+player.radY>=Wall[ar].y-Wall[ar].hHigh-player.ySpeed)&&(player.y+player.radY<=Wall[ar].y-Wall[ar].hHigh)&&(abs(player.x-Wall[ar].x)<=player.radX+Wall[ar].hWidth)){
 	player.y=player.y-player.ySpeed;
 };
 
 if((player.y-player.radY<=Wall[ar].y+Wall[ar].hHigh+player.ySpeed)&&(player.y-player.radY>=Wall[ar].y+Wall[ar].hHigh)&&(abs(player.x-Wall[ar].x)<=player.radX+Wall[ar].hWidth)){
 	player.y=player.y+player.ySpeed;
 };};							
 
 player.x=player.x+player.currentSpeedX;
 player.y=player.y+player.currentSpeedY;
 
 ///////////////enemy
 for(int rra=0;rra<=colEn;rra++){
 	
 if(enemy[rra].kind==0){
  if(player.x-enemy[rra].x>0){
 	enemy[rra].currentSpeedX=enemy[rra].xSpeed;
 }else if(player.x-enemy[rra].x<0){
 	enemy[rra].currentSpeedX=-1*enemy[rra].xSpeed;
 }else if(player.x-enemy[rra].x==0){
 	enemy[rra].currentSpeedX=0;
 };
 
 if(player.y-enemy[rra].y>0){
 	enemy[rra].currentSpeedY=enemy[rra].ySpeed;
 }else if(player.y-enemy[rra].y<0){
 	enemy[rra].currentSpeedY=-1*enemy[rra].ySpeed;
 }else if(player.y-enemy[rra].y==0){
 	enemy[rra].currentSpeedY=0;
 };}
 
 else if(enemy[rra].kind==1){///////////////////another kind 
   if(time(0)-t[rra]>1){t[rra]=time(0);
  /*if(abs(enemy[rra].x-player.x)<=abs(enemy[rra].y-player.y)){ 
  	if(enemy[rra].x-player.x>=0){
	  enemy[rra].currentSpeedX=-2;}else{
	  	enemy[rra].currentSpeedX=2;
	  };
	  
	  if(enemy[rra].y-player.y>=0){
  	enemy[rra].currentSpeedY=-1*(abs(enemy[rra].currentSpeedX)*(abs(enemy[rra].y-player.y)/(1+abs(enemy[rra].x-player.x))));}
  	else{
  	enemy[rra].currentSpeedY=1*(abs(enemy[rra].currentSpeedX)*(abs(enemy[rra].y-player.y)/(1+abs(enemy[rra].x-player.x))));	
	  };
  }else{
  	
  	if(enemy[rra].y-player.y>=0){
	  enemy[rra].currentSpeedY=-2;}else{
	  	enemy[rra].currentSpeedY=2;
	  };
	  
	  if(enemy[rra].x-player.x>=0){
  	enemy[rra].currentSpeedX=-1*(abs(enemy[rra].currentSpeedY)*(abs(enemy[rra].x-player.x)/(1+abs(enemy[rra].y-player.y))));}
  	else{
  	enemy[rra].currentSpeedX=1*(abs(enemy[rra].currentSpeedY)*(abs(enemy[rra].x-player.x)/(1+abs(enemy[rra].y-player.y))));	
	  };
  };*/
  


	int currenten=round((sqrt(abs(enemy[rra].x-player.x)*abs(enemy[rra].x-player.x)+abs(enemy[rra].y-player.y)*abs(enemy[rra].y-player.y)))/5);
 enemy[rra].currentSpeedX=round(abs(enemy[rra].x-player.x)/currenten)*sign(enemy[rra].x-player.x);
 enemy[rra].currentSpeedY=round(abs(enemy[rra].y-player.y)/currenten)*sign(enemy[rra].y-player.y);
  
  enemy[rra].xSpeed=enemy[rra].currentSpeedX;
  enemy[rra].ySpeed=enemy[rra].currentSpeedY;
  bool end=0;
  current=0;
  enemy[rra].LcurrentSpeedX=enemy[rra].x;
  enemy[rra].LcurrentSpeedY=enemy[rra].y;
	
  while(end==0){
  	current++;
  	 enemy[rra].x=enemy[rra].x+enemy[rra].currentSpeedX;
     enemy[rra].y=enemy[rra].y+enemy[rra].currentSpeedY;
     if(current>100){
     	enemy[rra].currentSpeedX=0;
     	enemy[rra].currentSpeedY=0;
     	enemy[rra].x=enemy[rra].LcurrentSpeedX;
     	enemy[rra].y=enemy[rra].LcurrentSpeedY;
     	end=1;
     	break;
	 };
	 for(int rer=0;rer<=colWal;rer++){
	  if(abs(enemy[rra].x-Wall[rer].x)<=(enemy[rra].radX+Wall[rer].hWidth)&&abs(enemy[rra].y-Wall[rer].y)<=(enemy[rra].radY+Wall[rer].hHigh)){
	  	enemy[rra].currentSpeedX=0;
     	enemy[rra].currentSpeedY=0;
     	enemy[rra].x=enemy[rra].LcurrentSpeedX;
     	enemy[rra].y=enemy[rra].LcurrentSpeedY;
     	end=1;
     	break;
	  };	
	 };
	 if(abs(enemy[rra].x-player.x)<=(enemy[rra].radX+player.radX)&&abs(enemy[rra].y-player.y)<=(enemy[rra].radY+player.radY)){
	  enemy[rra].x=enemy[rra].LcurrentSpeedX;
      enemy[rra].y=enemy[rra].LcurrentSpeedY;	
      break;
	 };
  	
  };};
  	
 };
 
 for(int ar=0;ar<=colWal;ar++){
 if((enemy[rra].x+enemy[rra].radX>=Wall[ar].x-Wall[ar].hWidth-enemy[rra].xSpeed)&&(enemy[rra].x+enemy[rra].radX<=Wall[ar].x-Wall[ar].hWidth)&&(abs(enemy[rra].y-Wall[ar].y)<=enemy[rra].radY+Wall[ar].hHigh)){
 	enemy[rra].x=enemy[rra].x-enemy[rra].xSpeed;
 	teleport[rra]++;
 	if(teleport[rra]>1000){
 		teleport[rra]=0;
 		enemy[rra].x=enemy[rra].x+enemy[rra].currentSpeedX;
 		enemy[rra].y=enemy[rra].y+enemy[rra].currentSpeedY;
	 };
 };
 
 if((enemy[rra].x-enemy[rra].radX<=Wall[ar].x+Wall[ar].hWidth+enemy[rra].xSpeed)&&(enemy[rra].x-enemy[rra].radX>=Wall[ar].x+Wall[ar].hWidth)&&(abs(enemy[rra].y-Wall[ar].y)<=enemy[rra].radY+Wall[ar].hHigh)){
 	enemy[rra].x=enemy[rra].x+enemy[rra].xSpeed;
 	teleport[rra]++;
 	if(teleport[rra]>1000){
 		teleport[rra]=0;
 		enemy[rra].x=enemy[rra].x+enemy[rra].currentSpeedX;
 		enemy[rra].y=enemy[rra].y+enemy[rra].currentSpeedY;
	 };
 };
 
 if((enemy[rra].y+enemy[rra].radY>=Wall[ar].y-Wall[ar].hHigh-enemy[rra].ySpeed)&&(enemy[rra].y+enemy[rra].radY<=Wall[ar].y-Wall[ar].hHigh)&&(abs(enemy[rra].x-Wall[ar].x)<=enemy[rra].radX+Wall[ar].hWidth)){
 	enemy[rra].y=enemy[rra].y-enemy[rra].ySpeed;
 	teleport[rra]++;
 	if(teleport[rra]>1000){
 		teleport[rra]=0;
 		enemy[rra].x=enemy[rra].x+enemy[rra].currentSpeedX;
 		enemy[rra].y=enemy[rra].y+enemy[rra].currentSpeedY;
	 };
 };
 
 if((enemy[rra].y-enemy[rra].radY<=Wall[ar].y+Wall[ar].hHigh+enemy[rra].ySpeed)&&(enemy[rra].y-enemy[rra].radY>=Wall[ar].y+Wall[ar].hHigh)&&(abs(enemy[rra].x-Wall[ar].x)<=enemy[rra].radX+Wall[ar].hWidth)){
 	enemy[rra].y=enemy[rra].y+enemy[rra].ySpeed;
 	teleport[rra]++;
 	if(teleport[rra]>1000){
 		teleport[rra]=0;
 		enemy[rra].x=enemy[rra].x+enemy[rra].currentSpeedX;
 		enemy[rra].y=enemy[rra].y+enemy[rra].currentSpeedY;
	 };
 };};	
 
 if(abs(enemy[rra].x-player.x)<=(enemy[rra].radX+player.radX)&&abs(enemy[rra].y-player.y)<=(enemy[rra].radY+player.radY)){
 bool opo=0;
 current=0;
 while(opo==0){
  setfillstyle(1,0);
  bar(0,0,1200,800);
  current++;
  switch(current){
  	case 1:{
  		stickPaint(player.x,player.y,1);
		break;
	  }
	case 2:{
EG[0].eqX=2;
EG[0].eqY=-3;
EG[0].col=10;

EG[1].eqX=2;
EG[1].eqY=-2;
EG[1].col=10;

EG[2].eqX=-2;
EG[2].eqY=-3;
EG[2].col=10;

EG[3].eqX=-2;
EG[3].eqY=-2;
EG[3].col=10;

EG[4].eqX=-2;
EG[4].eqY=-1;
EG[4].col=10;

EG[5].eqX=3;
EG[5].eqY=2;
EG[5].col=10;

EG[6].eqX=-1;
EG[6].eqY=4;
EG[6].col=10;

EG[7].eqX=2;
EG[7].eqY=3;
EG[7].col=10;

EG[9].eqX=1;
EG[9].eqY=4;
EG[9].col=10;

EG[10].eqX=0;
EG[10].eqY=4;
EG[10].col=10;

stickPaint(player.x,player.y,1);
	break;
	}
case 3:{

EG[5].eqX=-2;
EG[5].eqY=4;
EG[5].col=10;

stickPaint(player.x,player.y,1);
	break;
}
case 4:{

EG[8].eqX=2;
EG[8].eqY=-1;
EG[8].col=10;

EG[5].eqX=-2;
EG[5].eqY=4;
EG[5].col=10;

EG[7].eqX=2;
EG[7].eqY=4;
EG[7].col=10;

stickPaint(player.x,player.y,1);
	break;
}

case 5:{

EG[9].eqX=1;
EG[9].eqY=4;
EG[9].col=10;

EG[10].eqX=0;
EG[10].eqY=4;
EG[10].col=10;

EG[11].eqX=-3;
EG[11].eqY=5;
EG[11].col=10;

EG[12].eqX=3;
EG[12].eqY=5;
EG[12].col=10;

stickPaint(player.x,player.y,1);
	break;
}
case 6:{
	stickPaint(player.x,player.y,1);
	for(int lend=0;lend<500;lend++){
	  for(int een=0;een<=3;een++){
	  	putpixel(player.x-7+een,player.y-10+lend,12);
	  }
	  for(int een=0;een<=3;een++){
	  	putpixel(player.x+5+een,player.y-10+lend,12);
	  }
	  for(int lond=0;lond<21;lond++){
	  	putpixel(player.x-10+lond,player.y+13+lend,10);
	  };
	  
	}
	break;
}

  };
  delay(1000);	
 	//MessageBox(hwnd, "You died!","Error!",MB_ICONEXCLAMATION|MB_OK|MB_TASKMODAL);
 };};			
 
 enemy[rra].x=enemy[rra].x+enemy[rra].currentSpeedX;
 enemy[rra].y=enemy[rra].y+enemy[rra].currentSpeedY;
};
 
 //key
 for(int rra=0;rra<=ColKey;rra++){
if(Key[rra].exist==0){
 if(abs(Key[rra].x-player.x)<=(5+player.radX)&&abs(Key[rra].y-player.y)<=(5+player.radY)){
  Key[rra].exist=1;	
  curKey++;
 }
}
};

if(curKey>ColKey)red=1;
}

void game()
{
 
 physics();
 _paint();	
}
