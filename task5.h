#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_task5.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QComboBox>
#include "PaintingWidget.h"
#include "paintingrectangle.h"
#include "paintingcurve.h"
#include <QstackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class task5Class; };
QT_END_NAMESPACE

class task5 : public QWidget
{
    Q_OBJECT

public:
    task5(QWidget *parent = 0);
    ~task5();

private slots:
    void onComboBoxSelected(const QString& text);

private:
    QVBoxLayout* m_layout;
    QComboBox* m_combo_box;
    PaintingWidget* m_painting;
    QStackedWidget* stackWidget;

    PaintingRectangle* m_rec;//create one first, then if clicked, new one and append it to stackWidget
    PaintingCurve* m_curve;
};
