#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QTimer>
#include <iostream>
#include <QListIterator>

#include "util.h"
#include "arm.h"

using namespace glm;
using namespace std;


class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);
    QList<Joint> initializeJoints();
    void drawTarget();
    void rotateJoint(int i);
    void executeAlgorithm();
private:
    QTimer timer;
    Arm arm;
    QList<Joint>::iterator itJoints;
    vec2 target;
    int jointsSize;
    int width;
    int height;
    bool mousePressed;
    bool mouseActive;

signals:

public slots:

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

};

#endif // GLWIDGET_H
