#include "task5.h"
#include "paintingrectangle.h"
#include "paintingcurve.h"

task5::task5(QWidget* parent)
    : QWidget(parent)
{
    m_layout = new QVBoxLayout(this);
    setLayout(m_layout);
    m_combo_box = new QComboBox(this);
    m_painting = new PaintingWidget(this);

    stackWidget = new QStackedWidget(this);
    //m_layout->addWidget(m_painting);
    m_layout->addWidget(m_combo_box);
    m_combo_box->addItem("triangle");
    m_combo_box->addItem("curve");
    m_combo_box->addItem("Yellow");
    m_combo_box->addItem("rectangle");
    //m_layout->addWidget(m_painting);
    m_layout->addWidget(stackWidget);
    stackWidget->addWidget(m_painting);
    stackWidget->setCurrentIndex(0);

    connect(m_combo_box,
        SIGNAL(currentIndexChanged(const QString&)),
        this,
        SLOT(onComboBoxSelected(const QString&)));
}

task5::~task5()
{

}

void task5::onComboBoxSelected(const QString& text)
{
    if (text == "triangle") {
        
        //this->m_painting->setColor(1.0f, 0.0f, 0.0f);
        //PaintingWidget *c_widget = qobject_cast<PaintingWidget*>(stackWidget->widget(0));
        //c_widget->setColor(1.0f, 0.0f, 0.0f);

        int this_index = stackWidget->indexOf(m_painting);
        if (this_index == -1) {
            m_painting = new PaintingWidget(this);
            stackWidget->addWidget(m_painting);
            this_index = stackWidget->indexOf(m_painting);
        }
        m_painting->setColor(0.0f, 0.0f, 1.0f);
        stackWidget->setCurrentIndex(this_index);
    }
    if (text == "curve") {
        int this_index = stackWidget->indexOf(m_curve);
        if (this_index == -1) {
            m_curve = new PaintingCurve(this);
            stackWidget->addWidget(m_curve);
            this_index = stackWidget->indexOf(m_curve);
        }
        //m_rec->setColor(0.0f, 0.0f, 1.0f);
        stackWidget->setCurrentIndex(this_index);
    }
    if (text == "Yellow") {
        this->m_painting->setColor(1.0f, 1.0f, 0.0f);
        m_rec->setColor(0.0f, 0.0f, 1.0f);
    }
    if (text == "rectangle") {
        int this_index = stackWidget->indexOf(m_rec);
        if (this_index == -1) {
            m_rec = new PaintingRectangle(this);
            stackWidget->addWidget(m_rec);
            this_index = stackWidget->indexOf(m_rec);
        }
        //m_rec->setColor(0.0f, 0.0f, 1.0f);
        stackWidget->setCurrentIndex(this_index);
        

        

       



    }
}
