#ifndef SKINBUTTON_H
#define SKINBUTTON_H

#include <QPushButton>

class SkinButton : public QPushButton
{
    Q_OBJECT

public:
    typedef enum{
        ButtonNormal = 0,
        ButtonHovered = 1,
        ButtonPressed = 2,
        ButtonDisabeled = 3,
    }ButtonState;

public:
    explicit SkinButton(qint32 type, QWidget *parent = 0);
    ~SkinButton() {}

public slots:
    void setIndex(bool checked);
    //void setIndex(qint8 index);


protected:

    QSize sizeHint() const;
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

    void paintEvent(QPaintEvent *);

private:
    QPixmap getStatePixmap() const;

private:
    qint32 m_type;
    qint8 m_index;
    ButtonState m_state;
};

#endif // SKINBUTTON_H
