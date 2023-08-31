
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<string.h>
#define DEGREES_TO_RADIANS 3.14159/180.0

int mis=0,ds=0,q=0,score=0;
int flag=0,ud=0;
char ans[20],p[20];
char *ans1="windows";
char *ans2="facebook",*ans3="java",*ans4="chrome",*ans5="billgates";
char *alpha1="1abcdefghijklmnopqrstuvwxyz";

void sun(GLfloat radius);
void tree( int x, int y);

void text(int x,int y,char *s)
{
	int len,i;
	glRasterPos2f(x,y);
	len=(int)strlen(s);
	for(i=0;i<len;i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s[i]);
}

void text2(int x,int y,char s)
{
	glRasterPos2f(x,y);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,s);
}

void text1(int x,int y,char *s)
{
	int len,i;
	glRasterPos2f(x,y);
	len=(int)strlen(s);
	for(i=0;i<len;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
}

void text3(int x,int y,char s)
{
	glRasterPos2f(x,y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s);
}
int count=5;

void text4(int x,int y,int count)
{  
	glColor3f(0,0,0);
  glRasterPos2f(x,y);
  glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,count+48);
  glFlush();
	glutSwapBuffers();

}

void text5(int x,int y)
{
	glRasterPos2f(x,y);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,6+48);
}

void starter()
{
	
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);

	text1(100,450," COMPUTER GRAPHICS AND VISUALIZATION MINI PROJECT");
	glColor3f(0.5,0.5,0.5);
	text(100,445,"---------------------------------------------------------- ");
	glColor3f(0.5,0.7,0.7);
	text(240,420,"HANGMAN(WORD MATCHING) GAME ");
	text1(240,410,"-------------------------");


	glColor3f(0.5,0.7,0.5);
	text(250,360,"PROJECT ASSOCIATES");
//	text(250,355,"_____________________");
	
	glColor3f(0.9,0.3,0.7);
	text1(100,320,"ASHWIN SHETTY");
	text1(442,320,"JEEVAN M");
	glColor3f(1.0,1.0,1.0);
	text1(100,300,"(4JK20CS010)");
	text1(442,300,"(4JK20CS019)");
	
	glColor3f(0.5,0.7,0.5);
	text(250,270,"UNDER THE GUIDANCE");
//	text(250,265,"_____________________");

	glColor3f(0.9,0.3,0.7);
	text1(442,220,"MS.SHARON D'SOUZA");
	text1(100,220,"MR.VIJAYKUMAR DUDHANIKAR");
	
	glColor3f(0.0,1.0,0.0);
	text1(100,200,"ASST.PROF");
	text1(100,180,"CSE DEPT.");
	text1(442,200,"ASST.PROF");
	text1(442,180,"CSE DEPT ");
	
	glColor3f(0.0,0.5,0.5);
	text1(180,60,"COMPUTER SCIENCE AND ENGINEERING");

	text1(120,40,"AJ INSTITUTE OF ENGINEERING AND TECHNOLOGY,MANGLORE");
	
	glColor3f(1,1,0);
	text(250,150,"Press SPACE to begin");
	glFlush();
	glutSwapBuffers();
	 
}

void instructions()
{
		glClearColor(0.0,0.0,0.0,0.0);		
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5,0.7,0.3);
	text1(285,430,"HANGMAN");
	glColor3f(0.7,0.3,1.0);
	text(50,350,"1: Guess the word according to the hint and blank spaces provided");
	text(50,300,"2: Select the letters from the keyboard");
	text(50,250,"3: If the guessed letter is correct it will appear at the right spaces");
	text(50,200,"4: If guessed letter is wrong one body part of the man will be hanged");
	text(50,150,"5: There will be 6 chances to guess the word correctly");
	
	glColor3f(0.5,0,0.3);
	text(50,50,"PRESS tab TO GO BACK TO PREVIOUS MENU");
	glFlush();
	glutSwapBuffers();
	 
}
 
void mountains()
{
	glBegin(GL_POLYGON);
	glColor3f(0.5, 0.35, 0.05);
	glVertex2i(0,300);
	glVertex2i(100,455);
	glVertex2i(250,300);
	glVertex2i(500,455);
	glVertex2i(750,300);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.8,0.4);
	glVertex2i(0,300);
	glVertex2i(0,0);	
	glVertex2i(750,0);
	glVertex2i(750,300);
	glEnd();
}

void squar(int x,int y)
{
	glBegin(GL_POLYGON);
	glColor3f(0.5,0.35,0.05);
	glVertex2i(x-3,y-5);
	glVertex2i(x-3,y+9);
	glVertex2i(x+8,y+9);
	glVertex2i(x+8,y-5);
	glEnd();
}

void drawpixel(GLint cx,GLint cy)
{ 
	glPointSize(3);
	glColor3f(0.0, 0.0, 0.0); 
	glBegin(GL_POINTS);
	 glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k,GLint x,GLint y)
{
drawpixel(x+h,y+k);
drawpixel(-x+h,y+k);
drawpixel(x+h,-y+k);
drawpixel(-x+h,-y+k);
drawpixel(y+h,x+k);
drawpixel(-y+h,x+k);
drawpixel(y+h,-x+k);
drawpixel(-y+h,-x+k);
}

void circle(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>=x)
	{
		plotpixels(h,k,x,y);
		if(d<0)
		d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}	
		++x;
	}
	plotpixels(h,k,x,y);
}


void drawhead()
{
	glColor3f(0.0,0.0,1.0); 
	circle(140,310,30);
	glColor3f(1.0,1.0,1.0);
	glPointSize(68.0);
	glBegin(GL_POINTS);
	glVertex2i(140,310);
	glEnd();
	glPointSize(30.0);
	glBegin(GL_POINTS);
	glVertex2i(120,310);
	glVertex2i(160,310);
	glVertex2i(140,290);
	glEnd();
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2i(115,322);
	glVertex2i(165,322);
	glVertex2i(117,295);
	glVertex2i(116,298);
	glVertex2i(128,285);
	glVertex2i(150,283);
	glVertex2i(152,285);
	glVertex2i(165,300);
	glVertex2i(164,295);
	glEnd();
	glColor3f(0.0,0.5,0.5);
	glBegin(GL_POLYGON);//draw hat base
	glVertex2i(95,325);
	glVertex2i(115,335);
	glVertex2i(165,335);
	glVertex2i(185,325);
	glEnd();
	glColor3f(0,0,0);
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2i(114,335);
	glVertex2i(164,335);
	glEnd();
	glColor3f(0.8,0.0,0.5);	
	glBegin(GL_POLYGON);//draw hat head
	glVertex2i(115,335);
	glVertex2i(125,365);
	glVertex2i(155,365);
	glVertex2i(165,335);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	text1(122,310,"O");//draw eye
	text1(150,310,"O");
	glPointSize(8.0);
	glBegin(GL_POINTS);//draw eyeball
	glVertex2i(127,313);
	glVertex2i(155,313);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);//draw nose
  	glVertex2i(140,310);
	glVertex2i(145,300);
	glVertex2i(135,300);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glVertex2i(150,290);
	glVertex2i(130,290);
	glEnd();
	
	
	glLineWidth(9.0);
	glColor3f(0.8,0.8,0.0);
	glBegin(GL_LINES);
	glVertex2i(140,280);
	glVertex2i(140,260);
	glEnd();
	glFlush();
	glutSwapBuffers();
}


void drawbody()
{
   // glLineWidth(4.0);
	glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);//draw shirt
	glVertex2f(112.5,150);
	glVertex2f(167.5,150);
	glVertex2f(152.5,270);
	glVertex2f(127.5,270);
	glEnd();
	//draw button
	glColor3f(0.0,0.0,0.4);
	glPointSize(3.0);
	glBegin(GL_POINTS);
	glVertex2i(140,170);
	glVertex2i(140,190);
	glVertex2i(140,210);
	glVertex2i(140,230);
	glVertex2i(140,250);
	glEnd();
	glFlush();
	glutSwapBuffers();
}

void drawhand1()
{
    glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);//draw left hand
	glVertex2f(155,250);
	glVertex2f(157,230);
	glVertex2f(205,210);
	glVertex2f(205,220);
	glEnd();
	glColor3f(0.8,0.8,0.0);//draw hey
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2i(205,220);
	glVertex2i(220,235);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(205,216);
	glVertex2i(215,216);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(205,213);
	glVertex2i(220,210);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(205,210);
	glVertex2i(217,205);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(1.0);
	glBegin(GL_LINES);
	glVertex2i(205,220);
	glVertex2i(220,235);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(205,216);
	glVertex2i(215,216);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(205,213);
	glVertex2i(220,210);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(205,210);
	glVertex2i(217,205);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void drawhand2()
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);//draw right hand
	glVertex2f(125,250);
	glVertex2f(75,220);
	glVertex2f(75,210);
	glVertex2f(123,230);
	glEnd();
	glColor3f(0.8,0.8,0.0);//draw hey
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2i(60,205);
	glVertex2i(75,220);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(65,216);
	glVertex2i(75,216);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(60,210);
	glVertex2i(75,213);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(63,205);
	glVertex2i(75,210);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(1.0);
	glBegin(GL_LINES);
	glVertex2i(60,205);
	glVertex2i(75,220);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(65,216);
	glVertex2i(75,216);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(60,210);
	glVertex2i(75,213);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(63,205);
	glVertex2i(75,210);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void drawleg1()
{
	glColor3f(0.0,0.0,0.4);
	glBegin(GL_POLYGON);//draw left leg
	glVertex2f(115,150);
	glVertex2f(135,150);
	glVertex2f(130,90);
	glVertex2f(120,90);
	glEnd();
	glColor3f(0.8,0.8,0.0);//draw hey
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2i(120,90);
	glVertex2i(115,70);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(125,90);
	glVertex2i(121,80);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(130,90);
	glVertex2i(130,70);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(127,90);
	glVertex2i(125,75);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(1.0);
	glBegin(GL_LINES);
	glVertex2i(120,90);
	glVertex2i(115,70);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(125,90);
	glVertex2i(121,80);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(130,90);
	glVertex2i(130,70);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(127,90);
	glVertex2i(125,75);
	glEnd();
	glFlush();
	glutSwapBuffers();
}

void drawleg2()
{
	glColor3f(0.0,0.0,0.4);
	glBegin(GL_POLYGON);//draw right leg
	glVertex2f(165,150);
	glVertex2f(145,150);
	glVertex2f(150,90);
	glVertex2f(160,90);
	glEnd();
	glColor3f(0.8,0.8,0.0);//draw hey
	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex2i(150,90);
	glVertex2i(145,70);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(155,90);
	glVertex2i(151,80);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(160,90);
	glVertex2i(160,70);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(157,90);
	glVertex2i(155,75);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(1.0);
	glBegin(GL_LINES);
	glVertex2i(150,90);
	glVertex2i(145,70);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(155,90);
	glVertex2i(151,80);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(160,90);
	glVertex2i(160,70);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(157,90);
	glVertex2i(155,75);
	glEnd();
	glFlush();
	glutSwapBuffers();
}

void menu()
{	
	
	glClearColor(0.0,0.6,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);

//Sun
	glPushMatrix();
	glTranslatef(360,410,0.0);
	sun(50);
	glPopMatrix();

		mountains();

	tree(600,120);
	tree(420,300);
	drawhead();
	drawbody();
	drawhand1();
	drawhand2();
	drawleg1();
	drawleg2();
	glColor3f(0.0,0.0,0.0);
	text1(250,350,"PRESS!");
	text(250,300,"1:START GAME");
	text(250,250,"2:INSTRUCTIONS");
	text(250,200,"3:BACK TO START PAGE");
	text(250,150,"ESC:TO QUIT ANYTIME");
	glFlush();
	glutSwapBuffers();

}


void delay(int dtime)
{
	float i,j,k;

	for(i=0;i<dtime;i=i+.1)
	for(j=0;j<dtime;j=j+.1)
	for(k=0;k<dtime;k=k+.1);
}

void load()
{	
	glClearColor(0.0,0.0,0,0);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	glColor3f(0.4,0.4,0);
	glRecti(250,170,425,145);   //rect
	glColor3f(0.2,0.1,1);
	glRecti(255,165,269,149);   //inner rec
	glColor3f(0.2,0.6,0.3);
	glRecti(272,165,286,149);   //inner rec
	glColor3f(0.3,0.5,0.1);
	glRecti(289,165,303,149);   //inner rec
	glColor3f(0.4,0.5,0.5);
	glRecti(306,165,320,149);   //inner rec
	glColor3f(0.2,0.6,0.3);
	text(200,180,"READY TO GET HANGED...!!");
	glFlush();
	glutSwapBuffers();
}

void hanger()
{
	glClearColor(0.0,0.6,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);

//Sun
	glPushMatrix();
	glTranslatef(360,410,0.0);
	sun(50);
	glPopMatrix();
		mountains();
		
	glColor3f(0.6,0.35,0.05);
	glRecti(10,400,25,10);
	glRecti(25,400,180,385);
	glLineWidth(4);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2d(140,385);
	glVertex2d(140,365);
	glEnd();
	glLineWidth(2);
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2d(10,400);
	glVertex2d(10,10);
	glVertex2d(25,10);
	glVertex2d(25,385);
	glVertex2d(180,385);
	glVertex2d(180,400);
	glEnd();
	glFlush();
	glutSwapBuffers();
}

void gameover()
{
	ds=4;
	q=0;
	mis=0;
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.9,0.0);
	text1(220,400,"YOU LOST!!");
	glColor3f(0.5,0.5,0.0);
	text1(220,300,"GAME OVER...!!");
	text(200,200,"DO YOU WANT TO PLAY AGAIN(Y/N)");
	glFlush();
	glutSwapBuffers();
}


void mismatch(int mis)
{

	switch(mis)
	{
	case 1:drawhead();
		squar(530,420);
		text4(530,420,5);
			   break;
	case 2:drawbody();
		squar(530,420);
			text4(530,420,4);
		
			break;
	case 3:drawhand1();
		squar(530,420);
			text4(530,420,3);
			break;
	case 4:drawhand2();
		squar(530,420);
			text4(530,420,2);
			break;
	case 5:drawleg1();
		squar(530,420);
			text4(530,420,1);
			break;
	case 6:drawleg2();
		squar(530,420);
			text4(530,420,0);
			delay(60);
			ds=4;
			gameover();
			break;
	default:
			break;
	}
}

void alpha()
{
	glColor3f(0,0,0);
	text1(20,450,"a");
	text1(40,450,"b");
	text1(60,450,"c");
	text1(80,450,"d");
	text1(100,450,"e");
	text1(120,450,"f");
	text1(140,450,"g");
	text1(160,450,"h");
	text1(180,450,"i");
	text1(200,450,"j");
	text1(220,450,"k");
	text1(240,450,"l");
	text1(260,450,"m");
	text1(280,450,"n");
	text1(300,450,"o");
	text1(320,450,"p");
	text1(340,450,"q");
	text1(360,450,"r");
	text1(380,450,"s");
	text1(400,450,"t");
	text1(420,450,"u");
	text1(440,450,"v");
	text1(460,450,"w");
	text1(480,450,"x");
	text1(500,450,"y");
	text1(520,450,"z");
}

void ques1()
{
	int i,j;
	q++;
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	hanger();
	tree(600,120);
	tree(500,120);
	tree(400,120);
	tree(300,120);
	tree(200,120);
	alpha();
	text1(400,420,"number of lives left: ");
	text5(530,420);

	//	printf("%d",count);
	for(j=1;j<=mis;j++)
	{
		mismatch(j);
	}
	glColor3f(0,0,0);
	if(q==1)
	{
		text1(400,320,"HINT: operating system");
		text(400,250,"__ __ __ __ __ __  __");
		for(i=0;i<=(int)strlen(ans1);i++)
		{
				ans[i]=ans1[i];
		}
	}
	if(q==2)
	{
		text1(400,320,"HINT: social networking site");
		text(400,250,"__ __ __ __ __ __ __ __");
		for(i=0;i<=(int)strlen(ans2);i++)
		{
				ans[i]=ans2[i];
		}
	}
	if(q==3)
	{
		text1(400,320,"HINT: programing language");
		text(400,250,"__ __ __ __");
		for(i=0;i<=(int)strlen(ans3);i++)
		{
				ans[i]=ans3[i];
		}
	}
	if(q==4)
	{
		text1(400,320,"HINT: web browser ");
		text(400,250,"__ __ __ __ __ __");
		for(i=0;i<=(int)strlen(ans4);i++)
		{
				ans[i]=ans4[i];
		}
	}
	if(q==5)
	{
		text1(400,320,"HINT: microsoft");
		text(400,250,"__ __ __ __ __ __ __ __ __");
		for(i=0;i<=(int)strlen(ans5);i++)
		{
				ans[i]=ans5[i];
		}

	}
	if(q==6)
	{
	ds=4;
	q=0;
	mis=0;
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.9,0.9,0.0);
	text1(250,300,"YOU WON !!");
	glColor3f(0.0,0.5,0.5);
	//text1(200,300,"GAME OVER...!!");
	text(200,200,"DO YOU WANT TO PLAY AGAIN(Y/N)");
	glFlush();
	glutSwapBuffers();
	}
}

void stringmatch(char key,char *ans)
{
	int i,len,pos,flag=1,len1;
	len=(int)strlen(ans);
	for(i=0;i<len;i++)
	{
		
		if(key==ans[i])
		{
			pos=i;
			p[i]=key;
			glColor3f(0,0,0);
			text3((i*17)+400,250,key);
			flag=0;
		}
	}
		
	if(flag)
	{
			mis++;
			mismatch(mis);
			//ohno();
	}
	len1=(int)strlen(p);
	if(len1==len && mis<6)
	{
		for(i=0;i<len1;i++)
			p[i]=NULL;
		text1(250,100,"GrEaT jOb...!!");
		glFlush();
		glutSwapBuffers();
		delay(50);
		ques1();
	}
}

void key(unsigned char k, int x, int y)
{
	int len,i;
	//ds=0 start; ds=1 menu; ds=2 game; ds=3 instructions
		
	if(k==' '&&ds==0)
	{	
		ds=1;
		menu();
	}
	if(ds==1&&k=='1')
	{
		ds=2;
		load();
		delay(50);
		ques1();
	}
		
	if(ds==1&&k=='2')
	{
		ds=3;
		delay(50);
		instructions();
	}
	if(ds==3&&k=='	')
	{
		ds=1;
		menu();
	}
	if(ds==1&&k=='3')
	{  

		ds=5;
		delay(25);
		starter();
	}
	if(ds==5&&k==' ')
	{
		ds=1;
		menu();
	}
		

	if(k==27)
	{
		exit(0);
	}
	if(ds==4&&k=='y')
	{
		ds=1;
		menu();
	}
	if(ds==4&&k=='n')
	{
		exit(0);
	}
	if(ds==2&&((k=='a')||(k=='b')||(k=='c')||(k=='d')||(k=='e')||(k=='f')||(k=='g')||(k=='h')||(k=='i')||(k=='j')||(k=='k')||(k=='l')||(k=='m')||(k=='n')||(k=='o')||(k=='p')||(k=='q')||(k=='r')||(k=='s')||(k=='t')||(k=='u')||(k=='v')||(k=='w')||(k=='x')||(k=='y')||(k=='z')))
	{
		len=(int)strlen(alpha1);
		glColor3f(0.0,0.6,1.0);
		for(i=1;i<len;i++)
		{
			if(k==alpha1[i])
			{
				text3(20*i,450,k);
			}
		}
		stringmatch(k,ans);

	}
	glFlush();
	glutSwapBuffers();
}
void tree( int x, int y)
{
	glColor3f(1.0,0.0,0.0);
	
	glBegin(GL_TRIANGLES);
	glVertex2f(x,y);
	glVertex2f(x-10,y-15);
	glVertex2f(x+10,y-15);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2f(x,y-15);
	glVertex2f(x-20,y-30);
	glVertex2f(x+20,y-30);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(x,y-30);
	glVertex2f(x-30,y-45);
	glVertex2f(x+30,y-45);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex2f(x,y-45);
	glVertex2f(x-40,y-60);
	glVertex2f(x+40,y-60);
	glEnd();
	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x-10,y-60);
	glVertex2f(x-5,y-65);
	glVertex2f(x+5,y-65);
	glVertex2f(x+10,y-60);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x-5,y-65);
	glVertex2f(x-5,y-95);
	glVertex2f(x+5,y-95);
	glVertex2f(x+5,y-65);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x-5,y-95);
	glVertex2f(x-10,y-100);
	glVertex2f(x+10,y-100);
	glVertex2f(x+5,y-95);;
	
	glEnd();

	glFlush();
}

void init()
{
	glClearColor(0,0,0,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
}

void display(void)
{
	if(ds==0)
		starter();
	glFlush();
	glutSwapBuffers();
}
void sun(GLfloat radius)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0f,1.f,1.0f);
	glVertex2f(0,0);
	for (int i=0; i<361; i++)
	{
		glColor3f(.9f,0.8f,.0f);
		float degInRad = i * DEGREES_TO_RADIANS;
		glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
	}
	glEnd();
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("hangman");
	init();
	glutKeyboardFunc(key);
	glutDisplayFunc(display);
 	glutMainLoop();
	return 0;
}


