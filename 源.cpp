#include "stdafx.h"
#include "glut.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "data.h"
#include <string>
using namespace std;

GLfloat yRot = 0;
GLfloat t1 = 0;
GLfloat t2 = 0;
GLfloat t3 = 0;
GLfloat r1 = 0;
vector<TriAngle> TrangleVector1, TrangleVector2, TrangleVector3, TrangleVector4;
void ReadStlModel1()
{
	//ifstream infile("E:\\Tarloy支架\\三维建模\\STL\\zongASCII.STL");
	ifstream infile("zhijiapan1.STL");
	if (!infile.is_open())
	{
		return;
	}
	string temp, modelname;

	char dump[256];
	int trinumber = 0;
	TriAngle tempTriAngle;
	infile >> temp;
	int test = temp.compare("solid");
	if (test != 0)
	{
		return;
	}

	infile.getline(dump, 25);
	infile >> temp;
	while (temp.compare("facet") == 0)
	{
		trinumber++;//三角形数目
		infile >> temp;//get rid of "normal "
		infile >> tempTriAngle.NormDir.x;
		infile >> tempTriAngle.NormDir.y;
		infile >> tempTriAngle.NormDir.z;

		infile.getline(dump, 256);infile.getline(dump, 256);//get rid of "outer loop"
		for (int i = 0; i<3; i++)
		{
			infile >> temp;
			infile >> tempTriAngle.vertex[i].x;
			infile >> tempTriAngle.vertex[i].y;
			infile >> tempTriAngle.vertex[i].z;
			//tempTriAngle.push_back(temppoint[i]);
		}
		TrangleVector1.push_back(tempTriAngle);
		infile >> temp;
		infile >> temp;
		infile >> temp;
	}//while()
}
void ReadStlModel2()
{
	ifstream infile("zhijiapan2.STL");
	if (!infile.is_open())
	{
		return;
	}
	string temp, modelname;

	char dump[256];
	int trinumber = 0;
	TriAngle tempTriAngle;
	infile >> temp;
	int test = temp.compare("solid");
	if (test != 0)
	{
		return;
	}

	infile.getline(dump, 25);
	infile >> temp;
	while (temp.compare("facet") == 0)
	{
		trinumber++;//三角形数目
		infile >> temp;//get rid of "normal "
		infile >> tempTriAngle.NormDir.x;
		infile >> tempTriAngle.NormDir.y;
		infile >> tempTriAngle.NormDir.z;

		infile.getline(dump, 256); infile.getline(dump, 256);//get rid of "outer loop"
		for (int i = 0; i<3; i++)
		{
			infile >> temp;
			infile >> tempTriAngle.vertex[i].x;
			infile >> tempTriAngle.vertex[i].y;
			infile >> tempTriAngle.vertex[i].z;
			//tempTriAngle.push_back(temppoint[i]);
		}
		TrangleVector2.push_back(tempTriAngle);
		infile >> temp;
		infile >> temp;
		infile >> temp;
	}//while()
}
void ReadStlModel3()
{
	ifstream infile("lianganup.STL");
	if (!infile.is_open())
	{
		return;
	}
	string temp, modelname;

	char dump[256];
	int trinumber = 0;
	TriAngle tempTriAngle;
	infile >> temp;
	int test = temp.compare("solid");
	if (test != 0)
	{
		return;
	}

	infile.getline(dump, 25);
	infile >> temp;
	while (temp.compare("facet") == 0)
	{
		trinumber++;//三角形数目
		infile >> temp;//get rid of "normal "
		infile >> tempTriAngle.NormDir.x;
		infile >> tempTriAngle.NormDir.y;
		infile >> tempTriAngle.NormDir.z;

		infile.getline(dump, 256); infile.getline(dump, 256);//get rid of "outer loop"
		for (int i = 0; i<3; i++)
		{
			infile >> temp;
			infile >> tempTriAngle.vertex[i].x;
			infile >> tempTriAngle.vertex[i].y;
			infile >> tempTriAngle.vertex[i].z;
			//tempTriAngle.push_back(temppoint[i]);
		}
		TrangleVector3.push_back(tempTriAngle);
		infile >> temp;
		infile >> temp;
		infile >> temp;
	}//while()
}
void ReadStlModel4()
{
	ifstream infile("liangandown.STL");
	if (!infile.is_open())
	{
		return;
	}
	string temp, modelname;

	char dump[256];
	int trinumber = 0;
	TriAngle tempTriAngle;
	infile >> temp;
	int test = temp.compare("solid");
	if (test != 0)
	{
		return;
	}

	infile.getline(dump, 25);
	infile >> temp;
	while (temp.compare("facet") == 0)
	{
		trinumber++;//三角形数目
		infile >> temp;//get rid of "normal "
		infile >> tempTriAngle.NormDir.x;
		infile >> tempTriAngle.NormDir.y;
		infile >> tempTriAngle.NormDir.z;

		infile.getline(dump, 256); infile.getline(dump, 256);//get rid of "outer loop"
		for (int i = 0; i<3; i++)
		{
			infile >> temp;
			infile >> tempTriAngle.vertex[i].x;
			infile >> tempTriAngle.vertex[i].y;
			infile >> tempTriAngle.vertex[i].z;
			//tempTriAngle.push_back(temppoint[i]);
		}
		TrangleVector4.push_back(tempTriAngle);
		infile >> temp;
		infile >> temp;
		infile >> temp;
	}//while()
}
//用来画一个坐标轴的函数
void axis(double length)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, 0.0, length);
	glEnd();
	//将当前操作点移到指定位置
	glTranslated(0.0, 0.0, length - 0.2);
	glColor3f(1.0, 0.0, 0.0);
	//glutWireCone(0.04, 0.3, 8, 8);
	glPopMatrix();
}
void paint(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);//设置投影模式
	glLoadIdentity();
	glOrtho(-300.0, 300.0, -300.0, 300.0, -300, 300);
	glPointSize(1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 1.5, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//画坐标系
	axis(2);

	//glPushMatrix();
	//glRotated(90.0, 0, 1.0, 0);//绕y轴正方向旋转90度
	//axis(2);
	//glPopMatrix();

	//glPushMatrix();
	//glRotated(-90.0, 1.0, 0.0, 0.0);//绕x轴负方向旋转
	//axis(2);
	//glPopMatrix();

	glPushMatrix();//旋转除坐标轴之外的物体
	glRotated(yRot, 0.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 1.0f);

	///////////////////////stl model////////////////////////////
	//glPushMatrix();
	//glRotated(30.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	vector<TriAngle>::iterator it2; //模型在上面
	for (it2 = TrangleVector1.begin(); it2 != TrangleVector1.end(); it2++)
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it2->NormDir.x, it2->NormDir.y, it2->NormDir.z);
		glVertex3f(it2->vertex[0].x, it2->vertex[0].y, it2->vertex[0].z);
		glVertex3f(it2->vertex[1].x, it2->vertex[1].y, it2->vertex[1].z);
		glVertex3f(it2->vertex[2].x, it2->vertex[2].y, it2->vertex[2].z);
		glEnd();
	}
	//glPopMatrix();
	glPopMatrix();
	glPushMatrix();//移动下平台至上下两平台铅笔头重合
	glTranslated(t1, t2, t3);
	glPushMatrix();//旋转下平台至上下平台轴在一条直线上
	glRotated(r1, -1.66, -44.08, 3.16);
	glPushMatrix();
	glRotated(30.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(0, -180, 0);
	glPushMatrix();
	glRotated(180.0, 1.0, 0.0, 0.0);
	glPushMatrix();
	glRotated(180.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	vector<TriAngle>::iterator it3;
	for (it3 = TrangleVector2.begin(); it3 != TrangleVector2.end(); it3++)
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it3->NormDir.x, it3->NormDir.y, it3->NormDir.z);
		glVertex3f(it3->vertex[0].x, it3->vertex[0].y, it3->vertex[0].z);
		glVertex3f(it3->vertex[1].x, it3->vertex[1].y, it3->vertex[1].z);
		glVertex3f(it3->vertex[2].x, it3->vertex[2].y, it3->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(-30.0, 0.0, 1.0, 0.0);//整体顺时针旋转30°
	glPushMatrix();
	glRotated(30.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, 37.5);
	vector<TriAngle>::iterator it4;//上连杆1
	for (it4 = TrangleVector3.begin(); it4 != TrangleVector3.end(); it4++)
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it4->NormDir.x, it4->NormDir.y, it4->NormDir.z);
		glVertex3f(it4->vertex[0].x, it4->vertex[0].y, it4->vertex[0].z);
		glVertex3f(it4->vertex[1].x, it4->vertex[1].y, it4->vertex[1].z);
		glVertex3f(it4->vertex[2].x, it4->vertex[2].y, it4->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(-30.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, -37.5);
	for (it4 = TrangleVector3.begin(); it4 != TrangleVector3.end(); it4++)//上连杆2
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it4->NormDir.x, it4->NormDir.y, it4->NormDir.z);
		glVertex3f(it4->vertex[0].x, it4->vertex[0].y, it4->vertex[0].z);
		glVertex3f(it4->vertex[1].x, it4->vertex[1].y, it4->vertex[1].z);
		glVertex3f(it4->vertex[2].x, it4->vertex[2].y, it4->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(90.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, -37.5);
	for (it4 = TrangleVector3.begin(); it4 != TrangleVector3.end(); it4++)//上连杆3
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it4->NormDir.x, it4->NormDir.y, it4->NormDir.z);
		glVertex3f(it4->vertex[0].x, it4->vertex[0].y, it4->vertex[0].z);
		glVertex3f(it4->vertex[1].x, it4->vertex[1].y, it4->vertex[1].z);
		glVertex3f(it4->vertex[2].x, it4->vertex[2].y, it4->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(150.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, 37.5);
	for (it4 = TrangleVector3.begin(); it4 != TrangleVector3.end(); it4++)//上连杆4
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it4->NormDir.x, it4->NormDir.y, it4->NormDir.z);
		glVertex3f(it4->vertex[0].x, it4->vertex[0].y, it4->vertex[0].z);
		glVertex3f(it4->vertex[1].x, it4->vertex[1].y, it4->vertex[1].z);
		glVertex3f(it4->vertex[2].x, it4->vertex[2].y, it4->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, 37.5);
	for (it4 = TrangleVector3.begin(); it4 != TrangleVector3.end(); it4++)//上连杆5
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it4->NormDir.x, it4->NormDir.y, it4->NormDir.z);
		glVertex3f(it4->vertex[0].x, it4->vertex[0].y, it4->vertex[0].z);
		glVertex3f(it4->vertex[1].x, it4->vertex[1].y, it4->vertex[1].z);
		glVertex3f(it4->vertex[2].x, it4->vertex[2].y, it4->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(-150.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, -37.5);
	for (it4 = TrangleVector3.begin(); it4 != TrangleVector3.end(); it4++)//上连杆6
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it4->NormDir.x, it4->NormDir.y, it4->NormDir.z);
		glVertex3f(it4->vertex[0].x, it4->vertex[0].y, it4->vertex[0].z);
		glVertex3f(it4->vertex[1].x, it4->vertex[1].y, it4->vertex[1].z);
		glVertex3f(it4->vertex[2].x, it4->vertex[2].y, it4->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();//整体顺时针旋转30°
	glPushMatrix();//移动下平台至上下两平台铅笔头重合
	glTranslated(t1, t2, t3);
	glPushMatrix();//旋转下平台至上下平台轴在一条直线上
	glRotated(r1, -1.66, -44.08, 3.16);
	glPushMatrix();
	glTranslated(0, -180, 0);//整体下降180
	glPushMatrix();
	glRotated(30.0, 0.0, 1.0, 0.0);//整体顺时针旋转30°
	glPushMatrix();
	glRotated(30.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, 37.5);
	vector<TriAngle>::iterator it5; 
	for (it5 = TrangleVector4.begin(); it5 != TrangleVector4.end(); it5++)//下连杆一
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it5->NormDir.x, it5->NormDir.y, it5->NormDir.z);
		glVertex3f(it5->vertex[0].x, it5->vertex[0].y, it5->vertex[0].z);
		glVertex3f(it5->vertex[1].x, it5->vertex[1].y, it5->vertex[1].z);
		glVertex3f(it5->vertex[2].x, it5->vertex[2].y, it5->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(-30.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, -37.5);
	for (it5 = TrangleVector4.begin(); it5 != TrangleVector4.end(); it5++)//下连杆二
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it5->NormDir.x, it5->NormDir.y, it5->NormDir.z);
		glVertex3f(it5->vertex[0].x, it5->vertex[0].y, it5->vertex[0].z);
		glVertex3f(it5->vertex[1].x, it5->vertex[1].y, it5->vertex[1].z);
		glVertex3f(it5->vertex[2].x, it5->vertex[2].y, it5->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(90.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, -37.5);
	for (it5 = TrangleVector4.begin(); it5 != TrangleVector4.end(); it5++)//下连杆三
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it5->NormDir.x, it5->NormDir.y, it5->NormDir.z);
		glVertex3f(it5->vertex[0].x, it5->vertex[0].y, it5->vertex[0].z);
		glVertex3f(it5->vertex[1].x, it5->vertex[1].y, it5->vertex[1].z);
		glVertex3f(it5->vertex[2].x, it5->vertex[2].y, it5->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(150.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, 37.5);
	for (it5 = TrangleVector4.begin(); it5 != TrangleVector4.end(); it5++)//下连杆四
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it5->NormDir.x, it5->NormDir.y, it5->NormDir.z);
		glVertex3f(it5->vertex[0].x, it5->vertex[0].y, it5->vertex[0].z);
		glVertex3f(it5->vertex[1].x, it5->vertex[1].y, it5->vertex[1].z);
		glVertex3f(it5->vertex[2].x, it5->vertex[2].y, it5->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(-90.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, 37.5);
	for (it5 = TrangleVector4.begin(); it5 != TrangleVector4.end(); it5++)//下连杆五
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it5->NormDir.x, it5->NormDir.y, it5->NormDir.z);
		glVertex3f(it5->vertex[0].x, it5->vertex[0].y, it5->vertex[0].z);
		glVertex3f(it5->vertex[1].x, it5->vertex[1].y, it5->vertex[1].z);
		glVertex3f(it5->vertex[2].x, it5->vertex[2].y, it5->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	glRotated(-150.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslated(90, -4.5, -37.5);
	for (it5 = TrangleVector4.begin(); it5 != TrangleVector4.end(); it5++)//下连杆六
	{
		glBegin(GL_TRIANGLES);
		glNormal3f(it5->NormDir.x, it5->NormDir.y, it5->NormDir.z);
		glVertex3f(it5->vertex[0].x, it5->vertex[0].y, it5->vertex[0].z);
		glVertex3f(it5->vertex[1].x, it5->vertex[1].y, it5->vertex[1].z);
		glVertex3f(it5->vertex[2].x, it5->vertex[2].y, it5->vertex[2].z);
		glEnd();
	}
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();//整体顺时针旋转30°
	glPopMatrix();//真题下降180
	glPopMatrix();//移动下平台至上下两平台铅笔头重合
	glPopMatrix();//旋转下平台至上下平台轴在一条直线上
	///////////////////////stl end////////////////////////////

	glPopMatrix();//用来整体绕y轴旋转
	glutSwapBuffers();
}
void Init()
{
	glClearColor(0.8, 0.8, 0.8, 1.0);


	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 90.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);


	GLfloat lmodel_ambient[] = { 0.8, 0.8, 0.7, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, 8.0 / 6.0, 1.0f, 800.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.3, 0.5, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
void SpecialKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
		yRot += 5.0f;

	else if (key == GLUT_KEY_RIGHT)
		yRot -= 5.0f;


	glutPostRedisplay();
}
void NormalKeys(unsigned char key, int x, int y)
{

	if (key == 'r')//下平台旋转对接
		r1=0;
	else if (key == 't') //下平台平移对接
	{
		t1 = 0.94;
		t2 = 91.88;
		t3 = -0.81;
	}
	glutPostRedisplay();
}
int main(int argv, char *argc[])
{
	ReadStlModel1();
	ReadStlModel2();
	ReadStlModel3();
	ReadStlModel4();
	glutInit(&argv, argc);//初始化GLUT库
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//设置图形显示模式
	glutInitWindowSize(800, 600);//产生的窗口的大小
	glutInitWindowPosition(100, 100);// 产生的窗口的位置（左上角）
	glutCreateWindow("STL文件的显示");//产生一个顶层的窗口。形参作为窗口的名字
	Init();
	glutDisplayFunc(paint);//为当前窗口设置显示回调函数 
	//glutReshapeFunc(reshape);
	glutKeyboardFunc(NormalKeys);
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();//让 glut 程序进入事件循环。在一个glut程序中最多只能调用一次。一旦调用，会直到程序结束才返回。
}