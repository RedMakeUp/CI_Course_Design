#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>
#include <QDebug>
#include <QLine>

const int CIRCLE_RADIUS = 15;

double nextDouble(double min, double max){
    return min + QRandomGenerator::global()->generateDouble() * (max - min);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setUpScene();
    m_path->draw();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUpScene()
{
    m_cities.push_back(generateCircle("A"));
    m_cities.push_back(generateCircle("B"));
    m_cities.push_back(generateCircle("C"));
    m_cities.push_back(generateCircle("D"));
    m_cities.push_back(generateCircle("E"));

    m_path = std::make_unique<Path>(ui->scene);
    for(size_t i = 0;i < m_cities.size(); i++) m_path->addPoint(m_cities[i]->getCenter());
}

std::unique_ptr<Circle> MainWindow::generateCircle(const char* name)
{
    auto circle = std::make_unique<Circle>(name, CIRCLE_RADIUS, ui->scene);

    double x = nextDouble(0.1 * ui->scene->width(), 0.9 * ui->scene->width());
    double y = nextDouble(0.1 * ui->scene->height(), 0.9 * ui->scene->height());

    while(true){
        bool succeed = true;

        for(size_t i = 0; i < m_cities.size(); i++){
            double dx = m_cities[i]->pos().x() - x;
            double dy = m_cities[i]->pos().y() - y;
            if(std::sqrt(dx * dx + dy *dy) < 2.0 * CIRCLE_RADIUS){
                succeed = false;
                break;
            }
        }

        if(succeed) break;

        x = nextDouble(0.1 * ui->scene->width(), 0.9 * ui->scene->width());
        y = nextDouble(0.1 * ui->scene->height(), 0.9 * ui->scene->height());
    }

    circle->move(x, y);

    return circle;
}



