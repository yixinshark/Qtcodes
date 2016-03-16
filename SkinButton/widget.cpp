#include "widget.h"

#include <QDebug>
#include "resoure.h"
#include <QHBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , m_button(0)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    m_button = new SkinButton(Resource::Play);

    SkinButton *stopBtn = new SkinButton(Resource::Stop);
    SkinButton *timeInBtn = new SkinButton(Resource::TimeIn);
    SkinButton *timeOutBtn = new SkinButton(Resource::TimeOut);
    //SkinButton button(Resource::Play, this);
    layout->addWidget(m_button);
    layout->addWidget(stopBtn);
    layout->addWidget(timeInBtn);
    layout->addWidget(timeOutBtn);
}

Widget::~Widget()
{

}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "HHHHHHHHHHHHHHHHHHH";
    QWidget::keyPressEvent(event);

}
