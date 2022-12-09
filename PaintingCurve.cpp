#include "paintingcurve.h"
#include "QOpenGLFunctions_3_3_Compatibility.h"

static const char* VERTEX_SHADER_CODE =
"#version 330 \n"
"layout(location = 0) in vec3 posVertex;\n"
"layout(location = 1) in vec3 colVertex;\n"
"out vec4 cols;\n"
"void main() {\n"
"  gl_Position = vec4(posVertex, 1.0f);\n"
"  cols = vec4(colVertex, 1.0f);"
"}\n";

static const char* FRAGMENT_SHADER_CODE =
"#version 330\n"
"out vec4 fragColor;\n"
"void main() {\n"
"  fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n";

PaintingCurve::PaintingCurve(QWidget* parent) :
    QOpenGLWidget(parent), m_shader(nullptr) {


   
}
PaintingCurve::~PaintingCurve() {

}


void PaintingCurve::initializeGL()
{
    QOpenGLFunctions* f = this->context()->functions();
    m_shader = new QOpenGLShaderProgram();
    m_shader->addShaderFromSourceCode(QOpenGLShader::Vertex, VERTEX_SHADER_CODE);
    m_shader->addShaderFromSourceCode(QOpenGLShader::Fragment, FRAGMENT_SHADER_CODE);
    if (m_shader->link()) {
        qDebug("Shaders link success.");
    }
    else {
        qDebug("Shaders link failed!");
    }
}

void PaintingCurve::paintGL()
{
    //QOpenGLFunctions* f = this->context()->functions();
    QOpenGLFunctions_3_3_Compatibility* f = this->context()->versionFunctions<QOpenGLFunctions_3_3_Compatibility>();
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    f->glClearColor(0.0f, 0.2f, 0.0f, 1.0f);

    
    //m_shader->bind();

    GLfloat ctrlpoints[7][3] = {
{ 0.0,0.4, 0.0 },
{ -0.8, 0.8, 0.0},
{ -0.8, -0.4, 0.0},
{ 0.0,-1.8, 0.0 },
{ 0.8, -0.4, 0.0},
{ 0.8, 0.8, 0.0},
{ 0.0,0.4, 0.0 },
    };

    f->glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 7, &ctrlpoints[0][0]);
    f->glEnable(GL_MAP1_VERTEX_3);

    f->glColor3f(1.0f, 0.0f, 0.0f);
    f->glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 60; ++i)
    {
        f->glEvalCoord1f((GLfloat)i / 60.f);
    }
    
    f->glEnd();

    //m_shader->release();

}

void PaintingCurve::resizeGL(int w, int h)
{
    Q_UNUSED(w);
    Q_UNUSED(h);
}

