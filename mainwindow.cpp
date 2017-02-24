#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "waveanaldatamodel.h"

#include <QVBoxLayout>
#include <QTabWidget>
#include <QQuickWidget>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    setupContent();
    setupContent2();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupContent()
{ // 从文件创建QML对象
    QWidget *centralWidget = this->centralWidget();
    QVBoxLayout *verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(6);

    // 波形图
    QQuickWidget *qwWaveAnal = new QQuickWidget(centralWidget);
    qwWaveAnal->setObjectName(QStringLiteral("qwWaveAnal"));
    qwWaveAnal->setResizeMode(QQuickWidget::SizeRootObjectToView );
    qwWaveAnal->setSource(QUrl(QStringLiteral("../../views/WaveAnalDemo.qml")));
    WaveAnalDataModel *wave = new WaveAnalDataModel();
    wave->setTest(QStringLiteral("Append"));
    qwWaveAnal->rootContext()->setContextProperty("waveModel", wave);

    verticalLayout->addWidget(qwWaveAnal);

    QTabWidget *tabWidget = new QTabWidget(centralWidget);
    tabWidget->setObjectName(QStringLiteral("tableWidget"));
    tabWidget->setTabPosition(QTabWidget::South);

    QQuickWidget *qwTimeDisper = new QQuickWidget(centralWidget);
    qwTimeDisper->setResizeMode(QQuickWidget::SizeRootObjectToView );
    qwTimeDisper->setSource(QUrl(QStringLiteral("../../views/TimeDisperAnalDemo.qml")));
    tabWidget->addTab(qwTimeDisper, QString("Time Disper Anal"));

    QQuickWidget *qwHarmonicAnal = new QQuickWidget(centralWidget);
    qwHarmonicAnal->setResizeMode(QQuickWidget::SizeRootObjectToView );
    qwHarmonicAnal->setSource(QUrl(QStringLiteral("../../views/HarmonicAnalDemo.qml")));
    tabWidget->addTab(qwHarmonicAnal, QString("Harmonic Anal"));

    QQuickWidget *qwVectorChartAnal = new QQuickWidget(centralWidget);
    qwVectorChartAnal->setResizeMode(QQuickWidget::SizeRootObjectToView );
    qwVectorChartAnal->setSource(QUrl(QStringLiteral("../../views/VectorChartDemo.qml")));
    tabWidget->addTab(qwVectorChartAnal, QString("Vector Chart Anal"));

    verticalLayout->addWidget(tabWidget);

    verticalLayout->setStretch(0, 3);
    verticalLayout->setStretch(1, 2);

    centralWidget->setLayout(verticalLayout);
}

void MainWindow::setupContent2()
{ // 从QML插件中，以代码方式创建QML对象
    QWidget *centralWidget = this->centralWidget();
    QVBoxLayout *verticalLayout = new QVBoxLayout();
    verticalLayout->setSpacing(6);

    QQmlComponent *component = 0;

    // 波形图
    QQuickWidget *qwWaveAnal = new QQuickWidget(centralWidget);
    qwWaveAnal->setObjectName(QStringLiteral("qwWaveAnal"));
    qwWaveAnal->setResizeMode(QQuickWidget::SizeRootObjectToView );
    component = new QQmlComponent(qwWaveAnal->engine());
    component->setData("import QtQuick 2.4\n import XjQmlUi 1.0 \n WaveAnalDemo{}", QUrl());
    qwWaveAnal->setContent(QUrl(), component, component->create());

    WaveAnalDataModel *wave = new WaveAnalDataModel();
    wave->setTest(QStringLiteral("Append"));
    qwWaveAnal->rootContext()->setContextProperty("waveModel", wave);

    verticalLayout->addWidget(qwWaveAnal);

    QTabWidget *tabWidget = new QTabWidget(centralWidget);
    tabWidget->setObjectName(QStringLiteral("tableWidget"));
    tabWidget->setTabPosition(QTabWidget::South);

    QQuickWidget *qwTimeDisper = new QQuickWidget(centralWidget);
    qwTimeDisper->setResizeMode(QQuickWidget::SizeRootObjectToView );
    component = new QQmlComponent(qwTimeDisper->engine());
    component->setData("import QtQuick 2.4\n import XjQmlUi 1.0 \n TimeDisperAnalDemo{}", QUrl());
    qwTimeDisper->setContent(QUrl(), component, component->create());
    tabWidget->addTab(qwTimeDisper, QString("Time Disper Anal"));

    QQuickWidget *qwHarmonicAnal = new QQuickWidget(centralWidget);
    qwHarmonicAnal->setResizeMode(QQuickWidget::SizeRootObjectToView );
    component = new QQmlComponent(qwHarmonicAnal->engine());
    component->setData("import QtQuick 2.4\n import XjQmlUi 1.0 \n HarmonicAnalDemo{}", QUrl());
    qwHarmonicAnal->setContent(QUrl(), component, component->create());
    tabWidget->addTab(qwHarmonicAnal, QString("Harmonic Anal"));

    QQuickWidget *qwVectorChartAnal = new QQuickWidget(centralWidget);
    qwVectorChartAnal->setResizeMode(QQuickWidget::SizeRootObjectToView );
    component = new QQmlComponent(qwVectorChartAnal->engine());
    component->setData("import QtQuick 2.4\n import XjQmlUi 1.0 \n VectorChartDemo{}", QUrl());
    qwVectorChartAnal->setContent(QUrl(), component, component->create());
    tabWidget->addTab(qwVectorChartAnal, QString("Vector Chart Anal"));

    verticalLayout->addWidget(tabWidget);

    verticalLayout->setStretch(0, 3);
    verticalLayout->setStretch(1, 2);

    centralWidget->setLayout(verticalLayout);
}
