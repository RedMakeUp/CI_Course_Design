#ifndef CIRCLE_H
#define CIRCLE_H

#include <QWidget>
#include <QLabel>

#include <QPaintEvent>
#include <QPainter>

#include <QString>

class Circle: public QLabel{
    Q_OBJECT

public:
    Circle(QWidget* parent = nullptr) : QLabel(parent){};
    Circle(const QString& name, int radius, QWidget* parent = nullptr)
        :QLabel(parent), m_name(name)
    {
        setRadius(radius);
        setText(m_name);
        setAlignment(Qt::AlignCenter);

    }

    void setRadius(int radius) {
        m_radius = radius;

        QString style = "min-width: " + QString::number(2 * m_radius) + "px;"
                        "min-height: " + QString::number(2 * m_radius) + "px;"
                        "background-color: #123456;"
                        "color: #fff;"
                        "border-radius: " + QString::number(m_radius) + "px;";
        setStyleSheet(style);
    }

    inline int getRadius() const { return m_radius;}
    inline QPoint getCenter() const { return pos() += QPoint(m_radius, m_radius); }

private:
    int m_radius = 0;
    QString m_name;
};

#endif // CIRCLE_H
