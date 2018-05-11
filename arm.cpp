#include "arm.h"

Arm::Arm()
{
}

Arm::Arm(QList<Joint> jointList){
    this->jointList = jointList;
}

void Arm::setJointList(QList<Joint> jointList){
    this->jointList = jointList;
}

QList<Joint> *Arm::getJointList(){
    return &this->jointList;
}


void Arm::draw(){
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    for(int i = 0; i < jointList.size(); i++){
        glVertex2f(jointList[i].getPos().x,jointList[i].getPos().y);
    }
    glEnd();

    glBegin(GL_LINES);
    for(int i = 0; i < jointList.size()-1; i++){
        glVertex2f(jointList[i].getPos().x,  jointList[i].getPos().y);
        glVertex2f(jointList[i+1].getPos().x,jointList[i+1].getPos().y);
    }
    glEnd();
}
