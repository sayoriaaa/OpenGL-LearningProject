#pragma once

#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

class PaintingCurve : public QOpenGLWidget
{
    Q_OBJECT
public:
    PaintingCurve(QWidget* partent);
    ~PaintingCurve();

    

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
private:
    QOpenGLShaderProgram* m_shader;
};
