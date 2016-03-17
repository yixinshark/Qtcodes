#ifndef RESOURE_H
#define RESOURE_H

#include <QScopedPointer>
#include <QPixmap>

namespace Resource {

typedef enum{
    Play,
    Stop,
    TimeIn,
    TimeOut
}IndexPixmapType;

class IndexPixmap : public QPixmap
{
public:
    IndexPixmap();
    IndexPixmap(const char *fileName, quint32 cnt = 1);
    ~IndexPixmap() {}

public:
    void setWidth(quint32 w);
    QPixmap getSubPixmap(qint32 index = -1) const;

private:
    class Impl;
    QSharedPointer<Impl> m_pimpl;
};


class PixmapManager
{
public:
    PixmapManager();

public:
    static PixmapManager &inst();

public:
    QPixmap getPixmap(IndexPixmapType t, qint32 idx = -1);

private:
    class Impl;
    QScopedPointer<Impl> m_pImpl;
};

} // namespace Resource

#endif // RESOURE_H
