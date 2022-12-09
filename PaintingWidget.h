#pragma once

#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>

class PaintingWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    PaintingWidget(QWidget* partent);
    ~PaintingWidget();
    void setColor(GLfloat r, GLfloat g, GLfloat b);
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void fillColorBuffer();
private:
    QOpenGLBuffer* m_vbo, * m_cbo;
    QOpenGLVertexArrayObject* m_vao;
    QOpenGLShaderProgram* m_shader;
    GLfloat colorBuffer[3];
    GLfloat vertexData[3 * 3];
};



