#include <QPainter>
#include "skinbutton.h"
#include "resoure.h"
#include <QDebug>

SkinButton::SkinButton(qint32 type, QWidget *parent)
    : QPushButton(parent)
    , m_type(type)
    , m_index(0)
    , m_state(ButtonNormal)
{
    //connect(this, SIGNAL(clicked(bool)), this, SLOT(setIndex(bool)));
}

void SkinButton::setIndex(bool checked)
{
    qDebug() << "OOOOOOOOOOOOOOOOOOOOO " << checked;
    m_index = checked ? 1 : 0;
}

#if 0
void SkinButton::setIndex(qint8 index)
{
    m_index = index;
}
#endif

QSize SkinButton::sizeHint() const
{
    return getStatePixmap().size();
}

void SkinButton::enterEvent(QEvent *event)
{
    m_state = ButtonHovered;
    QPushButton::enterEvent(event);
}

void SkinButton::leaveEvent(QEvent *event)
{
    m_state = ButtonNormal;
    QPushButton::leaveEvent(event);
}

void SkinButton::mousePressEvent(QMouseEvent *event)
{
    m_state = ButtonPressed;
    QPushButton::mousePressEvent(event);
}

void SkinButton::mouseReleaseEvent(QMouseEvent *event)
{
    m_state = ButtonHovered;
    QPushButton::mouseReleaseEvent(event);
}

void SkinButton::paintEvent(QPaintEvent *)
{
    QPainter ptr(this);
    ptr.drawPixmap(0, 0, width(), height(), getStatePixmap());
}

QPixmap SkinButton::getStatePixmap() const
{
    qDebug() << "HHHHHHHHHHHHHHHH m_index , m_state " << m_index << m_state;
    return Resource::PixmapManager::inst().getPixmap(
                (Resource::IndexPixmapType)m_type, /*m_index * 4 + */m_state);
}
