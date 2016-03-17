#include "resoure.h"

#define RES_PLAY                        ":/res/play.bmp"
#define RES_STOP                        ":/res/stop.bmp"

#define RES_TIME_IN                     ":/res/timein.bmp"
#define RES_TIME_OUT                    ":/res/timeout.bmp"

namespace Resource {

class IndexPixmap::Impl
{
public:
    qint32 m_width;
    QHash<qint32, QPixmap> m_pixs;
};

IndexPixmap::IndexPixmap()
    : m_pimpl(new Impl())
{
    m_pimpl->m_width = 0;
}

IndexPixmap::IndexPixmap(const char *fileName, quint32 cnt)
    : QPixmap(fileName)
    , m_pimpl(new Impl())
{
    m_pimpl->m_width = width() / cnt;
}

void IndexPixmap::setWidth(quint32 w)
{
    m_pimpl->m_width = w;
}

QPixmap IndexPixmap::getSubPixmap(qint32 index) const
{
    if (index == -1)
        return *this;

    if (!m_pimpl->m_pixs.contains(index))
        m_pimpl->m_pixs.insert(index, copy(index * m_pimpl->m_width, 0, m_pimpl->m_width, height()));

    return m_pimpl->m_pixs.value(index);
}

////////////////////////////////////////////////////////////////////////////////

class PixmapManager::Impl
{
public:
    QPixmap getPixmap(IndexPixmapType t, qint32 idx);

private:
    void loadPixmap(IndexPixmapType t);

private:
    typedef QHash<IndexPixmapType, IndexPixmap> IndexPixmapSet;

    IndexPixmapSet m_indexPixmaps;
};

QPixmap PixmapManager::Impl::getPixmap(IndexPixmapType t, qint32 idx)
{
    if (!m_indexPixmaps.contains(t))
        loadPixmap(t);

    return m_indexPixmaps.value(t).getSubPixmap(idx);
}

void PixmapManager::Impl::loadPixmap(IndexPixmapType t)
{
    IndexPixmap tmp;
    switch (t) {
    case Play:
        tmp = IndexPixmap(RES_PLAY, 4);
        break;
    case Stop:
        tmp = IndexPixmap(RES_STOP, 4);
        break;
    case TimeIn:
        tmp = IndexPixmap(RES_TIME_IN, 4);
        break;
    case TimeOut:
        tmp = IndexPixmap(RES_TIME_OUT, 4);
        break;
    }

    m_indexPixmaps.insert(t, tmp);
}

////////////////////////////////////////////////////////////////////////////////

PixmapManager::PixmapManager()
    : m_pImpl(new PixmapManager::Impl())
{

}

PixmapManager &PixmapManager::inst()
{
    static PixmapManager mgr;
    return mgr;
}

QPixmap PixmapManager::getPixmap(IndexPixmapType t, qint32 idx)
{
    return m_pImpl->getPixmap(t, idx);
}

} // namespace Resource
