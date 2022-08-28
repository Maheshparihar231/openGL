#include <GL/glut.h>

float angle=0,xpos=-1,speed=0.01,ypos=0.0;

void button(unsigned char key, int x, int y)
{
	switch(key)//reacts to inputs
	{
		case 114://+
			angle=5;xpos=-1;speed=0.01;
			break;
		case 45://-
			speed-=0.01;
			break;
		case 43://r
			speed+=0.01;
			break;
		case 113://q
			exit(0);
			break;
	}

}

void idle(){
        angle-=5;//5 degrees anti-clockwise
        if(xpos<=1)
                xpos+=speed;//propagates to right
        else
                xpos=xpos-2;//resets wheel to left upon reaching right end

        glutPostRedisplay();
}

void display(){
        glClearColor(1, 1, 1, 1.0);//white bg
        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix();//Used to perform operations
        glTranslatef(xpos,ypos,0);
        glRotatef(angle,0,0,1);

        glColor3f(0,0,0);//black foreground
        glScalef(0.1,0.1,0.1);
        
        //TORUS
        glutWireTorus(0.5, 2.0, 30, 30);
        
	//SPOKES
	glBegin(GL_LINES);
	glVertex2f(-1.5, 0.0); 
  	glVertex2f(1.5, 0.0);
  	glVertex2f(0.0, -1.5);
  	glVertex2f(0.0, 1.5);
  	glVertex2f(1.06, 1.06); 
  	glVertex2f(-1.06, -1.06);
  	glVertex2f(-1.06, 1.06); 
  	glVertex2f(1.06, -1.06);  
	glEnd();
	
	glPopMatrix();//No operations further
	
        glutSwapBuffers();

}

int main(int argc, char** argv)
{
        glutInit(&argc,argv);
        glutInitWindowSize(640,480);//window size
        glutInitWindowPosition(10,10);//window position
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutCreateWindow("Wheel");//window name
        
        glutDisplayFunc(display);
        glutIdleFunc(idle);
        
        glutKeyboardFunc(button);//send keyboard and mouse input to function
        
        glutMainLoop();
}

