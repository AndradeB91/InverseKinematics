#include "glwidget.h"

#define POINT_SIZE 20

QList<Joint> GLWidget::initializeJoints(){
    QList<Joint> joints;

    joints << Joint(vec2(-1.0,1.0));
    joints << Joint(vec2(0.0,0.4));
    joints << Joint(vec2(0.6,0.2));
    joints << Joint(vec2(0.3,-0.2));

//    joints << Joint(vec2(0,0));
//    joints << Joint(vec2(0.0,-0.2));
//    joints << Joint(vec2(0.0,-0.4));
//    joints << Joint(vec2(0.0,-0.9));
//    joints << Joint(vec2(0.0,-1.1));
//    joints << Joint(vec2(0.0,-1.3));



    jointsSize = joints.size();
    return joints;
}

void GLWidget::drawTarget(){
    glColor3f(0,1,0);
    glBegin(GL_POINTS);
    glVertex2f(target.x,target.y);
    glEnd();
}

void GLWidget::rotateJoint(int i){
    vec2 toTip = itJoints[jointsSize-1].getPos() - itJoints[i].getPos();
    vec2 toTarget = target - itJoints[jointsSize-1].getPos() ;

    vec3 movementVector = cross(vec3(0,0,1),vec3(toTip.x,toTip.y,0));
    float gradient = dot(vec2(movementVector.x,movementVector.y),toTarget);

    int k = i+1;
    vec2 previousPos = itJoints[i].getPos();
    while(k < jointsSize){
        vec2 bone = itJoints[k].getPos() - previousPos;
        previousPos = itJoints[k].getPos();
        bone = Util::rotation(bone, 10*gradient);
        itJoints[k].setPos(bone + itJoints[k-1].getPos());
        k++;
    }
}

void GLWidget::executeAlgorithm(){
    for(int i=jointsSize-1; i>=0; i--){
        rotateJoint(i);
    }
}

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    mousePressed = false;
    timer.start();
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));

    arm.setJointList(initializeJoints());
    target = vec2(0.6,0.5);
    itJoints = arm.getJointList()->begin();
}

void GLWidget::initializeGL(){
    glClearColor(0.23,0.23,0.23,1);
    glEnable( GL_POINT_SMOOTH );
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glPointSize(POINT_SIZE);
    glLineWidth(4);
}

void GLWidget::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);
    executeAlgorithm();

    arm.draw();
    drawTarget();
}

void GLWidget::resizeGL(int w, int h){
    width = w;
    height = h;
    glViewport(0,0,w,h);
}

void GLWidget::mouseMoveEvent(QMouseEvent *event){
    vec2 v;
    v.x = ((float)event->x()/ ((float)width/2)) -1;
    v.y = 1-((float)event->y()/((float)height/2));
    if(mousePressed){
        target = v;
    }
}

void GLWidget::mousePressEvent(QMouseEvent *event){
    vec2 v;
    v.x = ((float)event->x()/ ((float)width/2)) -1;
    v.y = 1-((float)event->y()/((float)height/2));

    if (glm::distance(v,target)<= POINT_SIZE/((float)width/2)){
        mousePressed = true;
    }
}

void GLWidget::mouseReleaseEvent(QMouseEvent *event){
    mousePressed = false;
}
