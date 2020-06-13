#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vector>
#include <memory>

#include "Circle.h"
#include "Path.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void setUpScene();
    std::unique_ptr<Circle> generateCircle(const char* name);

private:
    Ui::MainWindow *ui;

    std::vector<std::unique_ptr<Circle>> m_cities;
    std::unique_ptr<Path> m_path = nullptr;

};
#endif // MAINWINDOW_H
