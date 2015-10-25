/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <Zonededessin.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    ZoneDeDessin *mainDraw;
    QWidget *widget;
    QSlider *WidthSlider;
    QLabel *label_3;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *brushBox;
    QComboBox *colorBox;
    QGroupBox *capStyleBox;
    QRadioButton *square;
    QRadioButton *round;
    QRadioButton *flat;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1615, 805);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(985, 648));
        QPalette palette;
        QBrush brush(QColor(51, 153, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMouseTracking(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainDraw = new ZoneDeDessin(centralWidget);
        mainDraw->setObjectName(QStringLiteral("mainDraw"));
        mainDraw->setGeometry(QRect(-1, -1, 1281, 771));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainDraw->sizePolicy().hasHeightForWidth());
        mainDraw->setSizePolicy(sizePolicy1);
        mainDraw->setMinimumSize(QSize(0, 0));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        mainDraw->setPalette(palette1);
        mainDraw->setCursor(QCursor(Qt::CrossCursor));
        mainDraw->setAutoFillBackground(true);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(1279, 0, 341, 771));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(300, 0));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush2(QColor(202, 202, 200, 176));
        brush2.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        widget->setPalette(palette2);
        widget->setLayoutDirection(Qt::LeftToRight);
        widget->setAutoFillBackground(true);
        WidthSlider = new QSlider(widget);
        WidthSlider->setObjectName(QStringLiteral("WidthSlider"));
        WidthSlider->setGeometry(QRect(110, 540, 31, 191));
        QPalette palette3;
        QBrush brush3(QColor(227, 227, 227, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        WidthSlider->setPalette(palette3);
        WidthSlider->setMaximum(39);
        WidthSlider->setValue(1);
        WidthSlider->setOrientation(Qt::Vertical);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 500, 121, 31));
        QFont font;
        font.setFamily(QStringLiteral("Segoe UI"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label_3->setFont(font);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 201, 221));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        groupBox->setPalette(palette4);
        groupBox->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 40, 51, 31));
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 120, 81, 31));
        label_2->setFont(font);
        brushBox = new QComboBox(groupBox);
        brushBox->setObjectName(QStringLiteral("brushBox"));
        brushBox->setGeometry(QRect(30, 80, 141, 21));
        QPalette palette5;
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush1);
        brushBox->setPalette(palette5);
        QFont font1;
        font1.setPointSize(10);
        brushBox->setFont(font1);
        brushBox->setAutoFillBackground(true);
        brushBox->setEditable(false);
        brushBox->setMaxCount(20);
        brushBox->setMinimumContentsLength(10);
        colorBox = new QComboBox(groupBox);
        colorBox->setObjectName(QStringLiteral("colorBox"));
        colorBox->setGeometry(QRect(30, 160, 141, 21));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        colorBox->setPalette(palette6);
        colorBox->setFont(font1);
        colorBox->setAutoFillBackground(true);
        colorBox->setEditable(false);
        capStyleBox = new QGroupBox(widget);
        capStyleBox->setObjectName(QStringLiteral("capStyleBox"));
        capStyleBox->setGeometry(QRect(30, 270, 201, 181));
        QFont font2;
        font2.setFamily(QStringLiteral("Segoe UI"));
        font2.setPointSize(12);
        capStyleBox->setFont(font2);
        square = new QRadioButton(capStyleBox);
        square->setObjectName(QStringLiteral("square"));
        square->setGeometry(QRect(30, 120, 95, 31));
        square->setChecked(true);
        round = new QRadioButton(capStyleBox);
        round->setObjectName(QStringLiteral("round"));
        round->setGeometry(QRect(30, 80, 95, 31));
        flat = new QRadioButton(capStyleBox);
        flat->setObjectName(QStringLiteral("flat"));
        flat->setGeometry(QRect(30, 40, 95, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1615, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy2);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        QBrush brush5(QColor(207, 219, 230, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush5);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        statusBar->setPalette(palette7);
        statusBar->setAutoFillBackground(true);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        brushBox->setCurrentIndex(-1);
        colorBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DesignerEditor", 0));
        label_3->setText(QApplication::translate("MainWindow", "Line Width", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Paint Brush", 0));
        label->setText(QApplication::translate("MainWindow", "Brush", 0));
        label_2->setText(QApplication::translate("MainWindow", "Ink Color", 0));
        brushBox->setCurrentText(QString());
        capStyleBox->setTitle(QApplication::translate("MainWindow", "Cap Style", 0));
        square->setText(QApplication::translate("MainWindow", "Square", 0));
        round->setText(QApplication::translate("MainWindow", "Round", 0));
        flat->setText(QApplication::translate("MainWindow", "Flat", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
