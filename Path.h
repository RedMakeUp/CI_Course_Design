#ifndef PATH_H
#define PATH_H

#include <QWidget>
#include <QPoint>
#include <QPainter>
#include <QPainterPath>

#include <vector>

class Path: public QWidget{
    Q_OBJECT

public:
    Path(QWidget* parent = nullptr)
        :QWidget(parent)
    {
        if(parent){
            setGeometry(0, 0, parent->width(), parent->height());
        }

    }

    void paintEvent(QPaintEvent*) override{
        if(m_points.size() < 2) return;

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);

        QPen pen(QColor(200, 0, 0));
        pen.setWidth(2);
        painter.setPen(pen);

        QPainterPath p;
        p.moveTo(m_points[0]);
        for(size_t i = 1; i < m_points.size(); i++) p.lineTo(m_points[i]);

        painter.drawPath(p);

    }

    inline void addPoint(const QPoint& point){ m_points.push_back(point); }

    inline void draw() { lower(); update(); }

private:
    std::vector<QPoint> m_points;
};

#endif // PATH_H
