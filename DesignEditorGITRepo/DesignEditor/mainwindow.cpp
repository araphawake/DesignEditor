/* MainWindow.cpp 
 *
 * The main window where all elements of this program are displayed is 
 * configured by this class. Do not modify this file.
 * 
 * Author: Azevedo Moscoso Silva Cruz, Rafael; Cruz, RAMSC.
 * 25 October 2015
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "qfiledialog.h"
#include "qtextstream.h"
#include "qmessagebox.h"
#include "qboxlayout.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qwindow.h"
#include <cstdlib>
#include <QStyle>
#include <QDesktopWidget>

using namespace std;

// Identifier for the LINE shape.
const char * LINE_TEXT = "Line";
// Identifier for the CIRCLE shape.
const char * CIRCLE_TEXT = "Circle";
// Identifier for the ELLIPSE shape.
const char * ELLIPSE_TEXT = "Ellipse";
// Identifier for the RECTANGLE shape.
const char * RECTANGLE_TEXT = "Rectangle";
// Identifier for the SQUARE shape.
const char * SQUARE_TEXT = "Square";
// Identifier for the POLYLINE shape.
const char * POLYLINE_TEXT = "Polyline";
// Identifier for the RED color.
const char * RED_TEXT = "Red Ink";
// Identifier for the BLACK color.
const char * BLACK_TEXT = "Black Ink";
// Identifier for the BLUE color.
const char * BLUE_TEXT = "Blue Ink";
// Identifier for the YELLOW color.
const char * YELLOW_TEXT = "Yellow Ink";
// Identifier for the GREEN color.
const char * GREEN_TEXT = "Green Ink";
// Identifier for the CYAN color.
const char * CYAN_TEXT = "Cyan Ink";
// Identifier for the MAGENTA color.
const char * MAGENTA_TEXT = "Magenta Ink";
// Identifier for the DARK BLUE color.
const char * DARK_BLUE_TEXT = "Dark Blue Ink";
// Identifier for the DARK RED color.
const char * DARK_RED_TEXT = "Dark Red Ink";
// Identifier for the DARK GRAY color.
const char * DARK_GREY_TEXT = "Dark Grey Ink";
// Identifier for the DARK GREEN color.
const char * DARK_GREEN_TEXT = "Dark Green Ink";
// Identifier for the GRAY color.
const char * GRAY_TEXT = "Gray Ink";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

	// Setup the User Interface of the application.
    ui->setupUi(this);
    
    // Retrieve intel about the computer.
    QDesktopWidget dw;

    //this->setWindowTitle("DesignerEditor");
    // Set application window's size fixed and width button not pressed.  
    this->setFixedSize(dw.width() * 0.8, dw.height() * 0.8);
    this->widthButtonPressed = false;
    //this->move(dw.width() / 7, dw.height() / 8);

    //statusBar();
    QMenuBar * menuB = this->menuBar();
    QMenu * menuFichier = menuB->addMenu(tr("File"));

    QAction * open = new QAction(QIcon(":icons/images/open.png"), tr("&Open"), this);
    open->setToolTip(tr("Open existing file"));
    open->setStatusTip(tr("Open existing file"));
    open->setShortcut(tr("CTRL+O"));

    QAction * save = new QAction(QIcon(":icons/images/save.png"), tr("&Save"), this);
    save->setToolTip(tr("Save file"));
    save->setStatusTip(tr("Save file"));
    save->setShortcut(tr("CTRL+S"));

    QAction * exit = new QAction(QIcon(":icons/images/quit.png"), tr("&Exit"), this);
    exit->setToolTip(tr("Exit"));
    exit->setStatusTip(tr("Exit"));
    exit->setShortcut(tr("CTRL+E"));

    menuFichier->addAction(open);
    menuFichier->addAction(save);
    menuFichier->addAction(exit);

    QMenu * Tools = menuB->addMenu(tr("Tools"));

    //TODO The Polygon
    this->selectShape = new QActionGroup(this);
    selectShape->addAction(tr(CIRCLE_TEXT));
    selectShape->actions().back()->setToolTip(tr("Draw a Circle"));
    selectShape->actions().back()->setStatusTip(tr("Draw a Circle"));
    selectShape->actions().back()->setShortcut(tr("ALT+W"));
    //Circle reserved for the next release. There are still bugs to be fixed.
    selectShape->actions().back()->setEnabled(false);

    selectShape->addAction(tr(RECTANGLE_TEXT));
    selectShape->actions().back()->setToolTip(tr("Draw a Rectangle"));
    selectShape->actions().back()->setStatusTip(tr("Draw a Rectangle"));
    selectShape->actions().back()->setShortcut(tr("ALT+Z"));
    selectShape->addAction(tr(LINE_TEXT));
    selectShape->actions().back()->setToolTip(tr("Draw a Line"));
    selectShape->actions().back()->setStatusTip(tr("Draw a Line"));
    selectShape->actions().back()->setShortcut(tr("ALT+A"));
    selectShape->addAction(tr(ELLIPSE_TEXT));
    selectShape->actions().back()->setToolTip(tr("Draw an Ellipse"));
    selectShape->actions().back()->setStatusTip(tr("Draw an Ellipse"));
    selectShape->actions().back()->setShortcut(tr("ALT+Q"));
    selectShape->addAction(tr(POLYLINE_TEXT));
    selectShape->actions().back()->setToolTip(tr("Draw a Polyline"));
    selectShape->actions().back()->setStatusTip(tr("Draw a Polyline"));
    selectShape->actions().back()->setShortcut(tr("ALT+D"));

    selectShape->addAction(tr(SQUARE_TEXT));
    selectShape->actions().back()->setToolTip(tr("Draw a Square"));
    selectShape->actions().back()->setStatusTip(tr("Draw a Square"));
    selectShape->actions().back()->setShortcut(tr("ALT+X"));
    //Square reserved for the next release. There are still bugs to be fixed.
    selectShape->actions().back()->setEnabled(false);


    QMenu * Shapes = Tools->addMenu(tr("Shape"));
    Shapes->addActions(selectShape->actions());

    this->selectColor = new QActionGroup(this);
    selectColor->addAction(tr(RED_TEXT));
    selectColor->actions().back()->setToolTip(tr("Black ink"));
    selectColor->actions().back()->setStatusTip(tr("Red ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+R"));
    selectColor->addAction(tr(BLACK_TEXT));
    selectColor->actions().back()->setToolTip(tr("Red ink"));
    selectColor->actions().back()->setStatusTip(tr("Black ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+Z"));
    selectColor->addAction(tr(BLUE_TEXT));
    selectColor->actions().back()->setToolTip(tr("Blue ink"));
    selectColor->actions().back()->setStatusTip(tr("Blue ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+E"));
    selectColor->addAction(tr(YELLOW_TEXT));
    selectColor->actions().back()->setToolTip(tr("Yellow ink"));
    selectColor->actions().back()->setStatusTip(tr("Yellow ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+Q"));
    selectColor->addAction(tr(CYAN_TEXT));
    selectColor->actions().back()->setToolTip(tr("Cyan ink"));
    selectColor->actions().back()->setStatusTip(tr("Cyan ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+S"));
    selectColor->addAction(tr(MAGENTA_TEXT));
    selectColor->actions().back()->setToolTip(tr("Magenta ink"));
    selectColor->actions().back()->setStatusTip(tr("Magenta ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+D"));
    selectColor->addAction(tr(DARK_BLUE_TEXT));
    selectColor->actions().back()->setToolTip(tr("Dark Blue ink"));
    selectColor->actions().back()->setStatusTip(tr("Dark Blue ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+W"));
    selectColor->addAction(tr(DARK_RED_TEXT));
    selectColor->actions().back()->setToolTip(tr("Dark Red ink"));
    selectColor->actions().back()->setStatusTip(tr("Dark Red ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+X"));
    selectColor->addAction(tr(GREEN_TEXT));
    selectColor->actions().back()->setToolTip(tr("Green ink"));
    selectColor->actions().back()->setStatusTip(tr("Green ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+C"));
    selectColor->addAction(tr(DARK_GREEN_TEXT));
    selectColor->actions().back()->setToolTip(tr("Dark Green ink"));
    selectColor->actions().back()->setStatusTip(tr("Dark Green ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+F"));
    selectColor->addAction(tr(DARK_GREY_TEXT));
    selectColor->actions().back()->setToolTip(tr("Dark Gray ink"));
    selectColor->actions().back()->setStatusTip(tr("Dark Gray ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+A"));
    selectColor->addAction(tr(GRAY_TEXT));
    selectColor->actions().back()->setToolTip(tr("Gray ink"));
    selectColor->actions().back()->setStatusTip(tr("Gray ink"));
    selectColor->actions().back()->setShortcut(tr("SHIFT+V"));

    const QStringList colorIdentifiers = (QStringList()<<"Black"<<"Red"<<"Blue"
                                                  <<"Yellow"<<"Cyan"<<"Magenta"
                                                  <<"Dark Blue"<<"Dark Red"<<"Green"
                                                  <<"Dark Green"<<"Dark Gray"<<"Gray");

    this->ui->colorBox->addItems(colorIdentifiers);

    QObject::connect(this->ui->colorBox, SIGNAL(currentIndexChanged(int)), this, SLOT(colorBox_currentIndexChanged(int)));

    QMenu * Colors = Tools->addMenu(tr("Ink Color"));
    Colors->addActions(selectColor->actions());

    this->selectWidthPen = new QActionGroup(this);
    selectWidthPen->addAction(tr("Increase Width"));
    selectWidthPen->actions().back()->setToolTip(tr("Increase the width of the outline"));
    selectWidthPen->actions().back()->setStatusTip(tr("Increase the width of the outline"));
    selectWidthPen->actions().back()->setShortcut(Qt::Key_Up);
    selectWidthPen->addAction(tr("Decrease Width"));
    selectWidthPen->actions().back()->setToolTip(tr("Decrease the width of the outline"));
    selectWidthPen->actions().back()->setStatusTip(tr("Decrease the width of the outline"));
    selectWidthPen->actions().back()->setShortcut(Qt::Key_Down);
    selectWidthPen->addAction(tr("Increase Width Quickly"));
    selectWidthPen->actions().back()->setToolTip(tr("Increase the width of the outline quickly"));
    selectWidthPen->actions().back()->setStatusTip(tr("Increase the width of the outline quickly"));
    selectWidthPen->actions().back()->setShortcut(tr("Q"));
    selectWidthPen->addAction(tr("Decrease Width Quickly"));
    selectWidthPen->actions().back()->setToolTip(tr("Increase the width of the outline quickly"));
    selectWidthPen->actions().back()->setStatusTip(tr("Increase the width of the outline quickly"));
    selectWidthPen->actions().back()->setShortcut(tr("S"));

    QObject::connect(this->ui->WidthSlider, SIGNAL(valueChanged(int)), this, SLOT(widthSlider_valueChanged(int)));

    QMenu * widthControl = Tools->addMenu(tr("Outline Width Editor"));
    widthControl->addActions(selectWidthPen->actions());

    this->widthActions = selectWidthPen->actions();

    for(int i = 0; i < widthActions.count(); i++ )
        QObject::connect(widthActions.at(i), SIGNAL(triggered()), this, SLOT(updateWidth()));

    this->selectBrushStyle = new QActionGroup(this);
    selectBrushStyle->addAction(tr("No Brush"));
    selectBrushStyle->actions().back()->setToolTip(tr("No Brush"));
    selectBrushStyle->actions().back()->setStatusTip(tr("No Brush"));
    selectBrushStyle->actions().back()->setShortcut(tr("A"));
    selectBrushStyle->addAction(tr("Solid Pattern"));
    selectBrushStyle->actions().back()->setToolTip(tr("Uniform color"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Uniform color"));
    selectBrushStyle->actions().back()->setShortcut(tr("Z"));
    selectBrushStyle->addAction(tr("Extremely Dense"));
    selectBrushStyle->actions().back()->setToolTip(tr("Extremely dense brush pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Extremely dense brush pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("E"));
    selectBrushStyle->addAction(tr("Very Dense"));
    selectBrushStyle->actions().back()->setToolTip(tr("Very dense brush pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Very dense brush pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("R"));
    selectBrushStyle->addAction(tr("Somewhat Dense"));
    selectBrushStyle->actions().back()->setToolTip(tr("Somewhat dense brush pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Somewhat dense brush pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("T"));
    selectBrushStyle->addAction(tr("Half Dense"));
    selectBrushStyle->actions().back()->setToolTip(tr("Half dense brush pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Half dense brush pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("Y"));
    selectBrushStyle->addAction(tr("Somewhat Sparse"));
    selectBrushStyle->actions().back()->setToolTip(tr("Somewhat sparse brush pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Somewhat sparse brush pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("U"));
    selectBrushStyle->addAction(tr("Very Sparse"));
    selectBrushStyle->actions().back()->setToolTip(tr("Very sparse brush pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Very sparse brush pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("I"));
    selectBrushStyle->addAction(tr("Extremely Sparse"));
    selectBrushStyle->actions().back()->setToolTip(tr("Extremely sparse brush pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Extremely sparse brush pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("O"));
    selectBrushStyle->addAction(tr("Horizontal lines"));
    selectBrushStyle->actions().back()->setToolTip(tr("Horizontal lines pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Horizontal lines pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("P"));
    selectBrushStyle->addAction(tr("Vertical lines"));
    selectBrushStyle->actions().back()->setToolTip(tr("Vertical lines pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Vertical lines pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("D"));
    selectBrushStyle->addAction(tr("Crossing horizontal and vertical lines"));
    selectBrushStyle->actions().back()->setToolTip(tr("Crossing horizontal and vertical lines pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Crossing horizontal and vertical lines pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("F"));
    selectBrushStyle->addAction(tr("Backward diagonal lines"));
    selectBrushStyle->actions().back()->setToolTip(tr("Backward diagonal lines pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Backward diagonal lines pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("G"));
    selectBrushStyle->addAction(tr("Forward diagonal lines"));
    selectBrushStyle->actions().back()->setToolTip(tr("Forward diagonal lines pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Forward diagonal lines pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("H"));
    selectBrushStyle->addAction(tr("Crossing diagonal lines"));
    selectBrushStyle->actions().back()->setToolTip(tr("Crossing diagonal lines pattern"));
    selectBrushStyle->actions().back()->setStatusTip(tr("Crossing diagonal lines pattern"));
    selectBrushStyle->actions().back()->setShortcut(tr("J"));

    const QStringList brushStylesIdentifiers = (QStringList()<<"No Brush"<<"Solid"<<"+++Dense"
                                                  <<"++Dense"<<"+Dense"<<"Dense"
                                                  <<"Sparse"<<"+Sparse"<<"++Sparse"
                                                  <<"- Lines"<<"| Lines"<<"X Lines"
                                                  <<"/ Backward"<<"/ Forward"<<"X / Lines");

    this->ui->brushBox->addItems(brushStylesIdentifiers);

    QObject::connect(this->ui->brushBox, SIGNAL(currentIndexChanged(int)), this, SLOT(brushBox_currentIndexChanged(int)));

    QMenu * brushStyles = Tools->addMenu(tr("Brush Pattern"));
    brushStyles->addActions(selectBrushStyle->actions());

    this->brushActions = selectBrushStyle->actions();

    for(int i = 0; i < brushActions.count(); i++ )
        QObject::connect(brushActions.at(i), SIGNAL(triggered()), this, SLOT(updateBrushPattern()));

    this->selectCapStyle = new QActionGroup(this);
    selectCapStyle->addAction(tr("Square"));
    selectCapStyle->actions().back()->setToolTip(tr("Square border curves"));
    selectCapStyle->actions().back()->setStatusTip(tr("Square border curves"));
    selectCapStyle->actions().back()->setShortcut(tr("K"));
    selectCapStyle->addAction(tr("Round"));
    selectCapStyle->actions().back()->setToolTip(tr("Round border curves"));
    selectCapStyle->actions().back()->setStatusTip(tr("Round border curves"));
    selectCapStyle->actions().back()->setShortcut(tr("L"));
    selectCapStyle->addAction(tr("Flat"));
    selectCapStyle->actions().back()->setToolTip(tr("Flat border curves"));
    selectCapStyle->actions().back()->setStatusTip(tr("Flat border curves"));
    selectCapStyle->actions().back()->setShortcut(tr("M"));

    this->selectMode = new QActionGroup(this);
    selectMode->addAction(QIcon("://icons/images/cut.png"), tr("Edit"));
    selectMode->actions().back()->setToolTip(tr("Select and Edit"));
    selectMode->actions().back()->setStatusTip(tr("Select and Edit"));
    selectMode->actions().back()->setShortcut(tr("W"));
    selectMode->addAction(QIcon("://icons/images/paintbrush-symbol_318-9145.jpg"), tr("Draw"));
    selectMode->actions().back()->setToolTip(tr("Draw"));
    selectMode->actions().back()->setStatusTip(tr("Draw"));
    selectMode->actions().back()->setShortcut(tr("X"));

    QMenu * Mode = menuB->addMenu(tr("Mode"));
    Mode->addActions(selectMode->actions());

    for(int i = 0; i < selectMode->actions().count(); i++ )
        QObject::connect(selectMode->actions().at(i), SIGNAL(triggered()), this, SLOT(updateMode()));


    QAction * translate = new QAction(QIcon("://icons/images/move_arrow_cursor_direction_shift_pan_arrows-512.png"), tr("&Translate"), this);
    translate->setToolTip(tr("Translate figure"));
    translate->setStatusTip(tr("Translate figure"));
    translate->setShortcut(tr("."));

    Mode->addAction(translate);
    QObject::connect(translate, SIGNAL(triggered()), this, SLOT(updateMode()));

    QMenu * capStyle = Tools->addMenu(tr("Cap Style"));
    capStyle->addActions(selectCapStyle->actions());

    this->capActions = selectCapStyle->actions();

    for(int i = 0; i < capActions.count(); i++ )
        QObject::connect(capActions.at(i), SIGNAL(triggered()), this, SLOT(updateCapStyle()));

    this->selectJoinStyle = new QActionGroup(this);
    selectJoinStyle->addAction(tr("BevelJoin"));
    selectJoinStyle->actions().back()->setToolTip(tr(""));
    selectJoinStyle->actions().back()->setStatusTip(tr(""));
    selectJoinStyle->actions().back()->setShortcut(tr("V"));
    selectJoinStyle->addAction(tr("MiterJoin"));
    selectJoinStyle->actions().back()->setToolTip(tr(""));
    selectJoinStyle->actions().back()->setStatusTip(tr(""));
    selectJoinStyle->actions().back()->setShortcut(tr("B"));
    selectJoinStyle->addAction(tr("RoundJoin"));
    selectJoinStyle->actions().back()->setToolTip(tr(""));
    selectJoinStyle->actions().back()->setStatusTip(tr(""));
    selectJoinStyle->actions().back()->setShortcut(tr("N"));

    QMenu * joinStyle = Tools->addMenu(tr("Join Style"));
    joinStyle->addActions(selectJoinStyle->actions());


    this->joinActions = selectJoinStyle->actions();

    for(int i = 0; i < joinActions.count(); i++ )
        QObject::connect(joinActions.at(i), SIGNAL(triggered()), this, SLOT(updateJoinStyle()));


    //this->mainTextView = new QTextEdit(this);
    this->mainDrawView = this->ui->mainDraw;//new ZoneDeDessin(this);
    this->mainDrawView->setSlider(this->ui->WidthSlider);
    //setCentralWidget(this->mainDrawView);


    //setCentralWidget(mainTextView);

    this->shapeActions = selectShape->actions();

    this->colorActions = selectColor->actions();

    for(int i = 0; i < this->shapeActions.count(); i++ )
        QObject::connect(this->shapeActions.at(i), SIGNAL(triggered()), this, SLOT(updateShape()));

    for(int i = 0; i < this->colorActions.count(); i++ )
        QObject::connect(this->colorActions.at(i), SIGNAL(triggered()), this, SLOT(updateColor()));

    this->eraseAll = new QAction(tr("&Erase All"), this);
    this->eraseAll->setToolTip(tr("Reset canvas"));
    this->eraseAll->setStatusTip(tr("Reset Canvas"));
    this->eraseAll->setShortcut(tr("DEL"));

    Tools->addAction(eraseAll);
    QObject::connect(eraseAll, SIGNAL(triggered()), this, SLOT(eraseAllCallback()));

    QToolBar * toolBar = this->ui->mainToolBar;//addToolBar(tr("File"));
    toolBar->addAction(open);
    toolBar->addAction(save);
    toolBar->addAction(this->selectMode->actions().back());
    toolBar->addAction(this->selectMode->actions().front());
    toolBar->addAction(translate);
    toolBar->addAction(exit);

    QObject::connect(open, SIGNAL(triggered()), this, SLOT(openFile()));
    QObject::connect(save, SIGNAL(triggered()), this, SLOT(saveFile()));
    QObject::connect(exit, SIGNAL(triggered()), this, SLOT(quitApp()));

}

void MainWindow::eraseAllCallback() {
    this->mainDrawView->reset();
}

void MainWindow::updateMode() {

    QObject * sender = QObject::sender();

    if(sender == this->selectMode->actions().at(0)) {
        this->mainDrawView->setEditing(true);
        this->eraseAll->setEnabled(false);
    } else if(sender == this->selectMode->actions().at(1)) {
        this->mainDrawView->setEditing(false);
        this->eraseAll->setEnabled(true);
    } else {
        this->mainDrawView->setTranslation(true);
        this->eraseAll->setEnabled(false);
    }
}

void MainWindow::updateWidthSlider(int width) {
    this->ui->WidthSlider->setSliderPosition(width);
}

void MainWindow::updateWidth() {

    QObject * sender = QObject::sender();

        if(sender == this->selectWidthPen->actions().at(0)) {
            this->mainDrawView->setWidth(this->mainDrawView->getWidth() + 1);
        } else if(sender == this->selectWidthPen->actions().at(1) && (this->mainDrawView->getWidth() > 0 || this->mainDrawView->getEditState())) {
            this->mainDrawView->setWidth(this->mainDrawView->getWidth() - 1);
        } else if(sender == this->selectWidthPen->actions().at(2)) {
            this->mainDrawView->setWidth(this->mainDrawView->getWidth() + 3);
        } else if(sender == this->selectWidthPen->actions().at(3) && (this->mainDrawView->getWidth() > 3  || this->mainDrawView->getEditState())) {
            this->mainDrawView->setWidth(this->mainDrawView->getWidth() - 3);
        }

        this->widthButtonPressed = true;

        if(this->mainDrawView->getEditState())
            updateWidthSlider(this->mainDrawView->getWidthEditing());
        else
            updateWidthSlider(this->mainDrawView->getWidth());
}

void MainWindow::updateBrushPattern() {

    QObject * sender = QObject::sender();

    if(sender == this->selectBrushStyle->actions().at(0)) {
        this->mainDrawView->setBrushStyle(Qt::NoBrush);
        this->ui->brushBox->setCurrentIndex(0);
    } else if(sender == this->selectBrushStyle->actions().at(1)) {
        this->mainDrawView->setBrushStyle(Qt::SolidPattern);
        this->ui->brushBox->setCurrentIndex(1);
    } else if(sender == this->selectBrushStyle->actions().at(2)) {
        this->mainDrawView->setBrushStyle(Qt::Dense1Pattern);
        this->ui->brushBox->setCurrentIndex(2);
    } else if(sender == this->selectBrushStyle->actions().at(3)) {
        this->mainDrawView->setBrushStyle(Qt::Dense2Pattern);
        this->ui->brushBox->setCurrentIndex(3);
    } else if(sender == this->selectBrushStyle->actions().at(4)) {
        this->mainDrawView->setBrushStyle(Qt::Dense3Pattern);
        this->ui->brushBox->setCurrentIndex(4);
    } else if(sender == this->selectBrushStyle->actions().at(5)) {
        this->mainDrawView->setBrushStyle(Qt::Dense4Pattern);
        this->ui->brushBox->setCurrentIndex(5);
    } else if(sender == this->selectBrushStyle->actions().at(6)) {
        this->mainDrawView->setBrushStyle(Qt::Dense5Pattern);
        this->ui->brushBox->setCurrentIndex(6);
    } else if(sender == this->selectBrushStyle->actions().at(7)) {
        this->mainDrawView->setBrushStyle(Qt::Dense6Pattern);
        this->ui->brushBox->setCurrentIndex(7);
    } else if(sender == this->selectBrushStyle->actions().at(8)) {
        this->mainDrawView->setBrushStyle(Qt::Dense7Pattern);
        this->ui->brushBox->setCurrentIndex(8);
    } else if(sender == this->selectBrushStyle->actions().at(9)) {
        this->mainDrawView->setBrushStyle(Qt::HorPattern);
        this->ui->brushBox->setCurrentIndex(9);
    } else if(sender == this->selectBrushStyle->actions().at(10)) {
        this->mainDrawView->setBrushStyle(Qt::VerPattern);
        this->ui->brushBox->setCurrentIndex(10);
    } else if(sender == this->selectBrushStyle->actions().at(11)) {
        this->mainDrawView->setBrushStyle(Qt::CrossPattern);
        this->ui->brushBox->setCurrentIndex(11);
    } else if(sender == this->selectBrushStyle->actions().at(12)) {
        this->mainDrawView->setBrushStyle(Qt::BDiagPattern);
        this->ui->brushBox->setCurrentIndex(12);
    } else if(sender == this->selectBrushStyle->actions().at(13)) {
        this->mainDrawView->setBrushStyle(Qt::FDiagPattern);
        this->ui->brushBox->setCurrentIndex(13);
    } else if(sender == this->selectBrushStyle->actions().at(14)) {
        this->mainDrawView->setBrushStyle(Qt::DiagCrossPattern);
        this->ui->brushBox->setCurrentIndex(14);
    }
}


void MainWindow::updateCapStyle() {

    QObject * sender = QObject::sender();

    if(sender == this->selectCapStyle->actions().at(0)) {
        this->mainDrawView->setCap(Qt::SquareCap);
        this->ui->flat->setChecked(false);
        this->ui->round->setChecked(false);
        this->ui->square->setChecked(true);
    } else if(sender == this->selectCapStyle->actions().at(1)) {
        this->mainDrawView->setCap(Qt::RoundCap);
        this->ui->flat->setChecked(false);
        this->ui->round->setChecked(true);
        this->ui->square->setChecked(false);
    } else if(sender == this->selectCapStyle->actions().at(2)) {
        this->mainDrawView->setCap(Qt::FlatCap);
        this->ui->flat->setChecked(true);
        this->ui->round->setChecked(false);
        this->ui->square->setChecked(false);
    }
}

void MainWindow::updateJoinStyle() {

    QObject * sender = QObject::sender();

    if(sender == this->selectJoinStyle->actions().at(0)) {
        this->mainDrawView->setJoin(Qt::BevelJoin);
    } else if(sender == this->selectJoinStyle->actions().at(1)) {
        this->mainDrawView->setJoin(Qt::MiterJoin);
    } else if(sender == this->selectJoinStyle->actions().at(2)) {
        this->mainDrawView->setJoin(Qt::RoundJoin);
    }
}


void MainWindow::updateShape() {

    QObject * sender = QObject::sender();

    if(this->mainDrawView->getDrawType() != Geometry::POLYLINE
            || (this->mainDrawView->getDrawType() == Geometry::POLYLINE && this->mainDrawView->getDrawStatus() == false)) {
        if(sender == this->shapeActions.at(0)) {
            //this->mainDrawView->setDrawType(Geometry::CIRCLE);
            this->mainDrawView->setDrawType(Geometry::ELLIPSE);
        } else if(sender == this->shapeActions.at(1)) {
            this->mainDrawView->setDrawType(Geometry::RECTANGLE);
        } else if(sender == this->shapeActions.at(2)) {
            this->mainDrawView->setDrawType(Geometry::LINE);
        } else if(sender == this->shapeActions.at(3)) {
            this->mainDrawView->setDrawType(Geometry::ELLIPSE);
        } else if(sender == this->shapeActions.at(4)) {
            this->mainDrawView->setDrawType(Geometry::POLYLINE);
        } else if(sender == this->shapeActions.at(5)) {
            this->mainDrawView->setDrawType(Geometry::RECTANGLE);
            //this->mainDrawView->setDrawType(Geometry::SQUARE);
        }
    }

}

void MainWindow::updateColor() {

    QObject * sender = QObject::sender();

    if(sender == this->colorActions.at(0)) {
        this->mainDrawView->setCurrentColor(Qt::black);
        this->ui->colorBox->setCurrentIndex(0);
    } else if(sender == this->colorActions.at(1)) {
        this->mainDrawView->setCurrentColor(Qt::red);
        this->ui->colorBox->setCurrentIndex(1);
    } else if(sender == this->colorActions.at(2)) {
        this->mainDrawView->setCurrentColor(Qt::blue);
        this->ui->colorBox->setCurrentIndex(2);
    } else if(sender == this->colorActions.at(3)) {
        this->mainDrawView->setCurrentColor(Qt::yellow);
        this->ui->colorBox->setCurrentIndex(3);
    } else if(sender == this->colorActions.at(4)) {
        this->mainDrawView->setCurrentColor(Qt::cyan);
        this->ui->colorBox->setCurrentIndex(4);
    } else if(sender == this->colorActions.at(5)) {
        this->mainDrawView->setCurrentColor(Qt::magenta);
        this->ui->colorBox->setCurrentIndex(5);
    } else if(sender == this->colorActions.at(6)) {
        this->mainDrawView->setCurrentColor(Qt::darkBlue);
        this->ui->colorBox->setCurrentIndex(6);
    } else if(sender == this->colorActions.at(7)) {
        this->mainDrawView->setCurrentColor(Qt::darkRed);
        this->ui->colorBox->setCurrentIndex(7);
    } else if(sender == this->colorActions.at(8)) {
        this->mainDrawView->setCurrentColor(Qt::green);
        this->ui->colorBox->setCurrentIndex(8);
    } else if(sender == this->colorActions.at(9)) {
        this->mainDrawView->setCurrentColor(Qt::darkGreen);
        this->ui->colorBox->setCurrentIndex(9);
    } else if(sender == this->colorActions.at(10)) {
        this->mainDrawView->setCurrentColor(Qt::darkGray);
        this->ui->colorBox->setCurrentIndex(10);
    } else if(sender == this->colorActions.at(11)) {
        this->mainDrawView->setCurrentColor(Qt::gray);
        this->ui->colorBox->setCurrentIndex(11);
    }

}

void MainWindow::openFile()
{
    showFutureReleaseNotice();

    /*this->mainDrawView->interruptDrawing();

    QString openedFileName = QFileDialog::getOpenFileName( this,
     tr("Open Document"),
     tr("Text Files (*.txt)"));

    QFile document (openedFileName);

    if( document.open(QIODevice::ReadOnly | QIODevice::Text)) {

        QTextStream in (&document);

        this->mainTextView->setHtml(in.readAll());

        document.close();

    } else {
         << "File could not be loaded." << endl;
    }

    cout << "openFile" << qPrintable(openedFileName) << " file opened" << endl;*/
}

void MainWindow::showFutureReleaseNotice() {
    QDesktopWidget dw;

    QPushButton * okButton = new QPushButton( "OK" );

    QLabel * warn = new QLabel( "This feature will be available in a future release.", this );
    this->warning = new QVBoxLayout( );
    this->warning->addWidget(warn);
    this->warning->addWidget( okButton );
    this->warning->setAlignment(okButton, Qt::AlignCenter);
    this->warning->setAlignment(warn, Qt::AlignCenter);


    this->window = new QWidget();

    QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(returnProgram()));

    this->window->setLayout(warning);
    this->window->setFixedSize(this->mainDrawView->size().width() * 0.25, this->mainDrawView->size().height() / 5);
    this->window->move(dw.width() * 0.38 , dw.height() * 0.38);
    this->window->show();
}


void MainWindow::saveFile()
{
    this->mainDrawView->interruptDrawing();

    showFutureReleaseNotice();

    /*QString savedFileName = QFileDialog::getSaveFileName( this,
     tr("Open Document"),
     tr("Text Files *.txt"));

    QFile document (savedFileName);

    if(document.open(QIODevice::WriteOnly)) {//| QIODevice::Text)) {

        QDataStream file (&document);

        file << this->mainDrawView;
        //QTextStream out (&document);
        //out << this->mainTextView->toHtml();

        document.close();

    } else {
        cout << "File could not be loaded." << endl;
    }

    cout << qPrintable(savedFileName) << " file saved" << endl;
    */
}


void MainWindow::quitApp()
{
        /*this->mainDrawView->interruptDrawing();

        QPushButton * yesButton = new QPushButton( "Yes" );
        QPushButton * noButton = new QPushButton( "No" );

        this->warning = new QVBoxLayout( );
        this->warning->addWidget( new QLabel( "Are you sure you want to quit?", this ) );
        this->warning->addWidget( yesButton );
        this->warning->addWidget( noButton );

        this->window = new QWidget();

        QObject::connect(yesButton, SIGNAL(clicked()), this, SLOT(exitProgram()));
        QObject::connect(noButton, SIGNAL(clicked()), this, SLOT(returnProgram()));

        this->window->setLayout(warning);

    this->window->show();*/

    this->exitProgram();

}

void MainWindow::closeEvent(QCloseEvent *event)
{

    this->mainDrawView->interruptDrawing();

    QMessageBox::StandardButton button = QMessageBox::question( this, "TP1", tr("Are you sure you want to quit?\n"),
                                                                   QMessageBox::Yes | QMessageBox::No,
                                                                   QMessageBox::Yes);
    if (button != QMessageBox::Yes) {
        event->ignore();
    } else {
        event->accept();
    }

}

void MainWindow::exitProgram()
{
   //this->window->close();
   this->close();
}

void MainWindow::returnProgram()
{
    this->window->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::colorBox_currentIndexChanged(int index) {

    //TODO All the other colors.
    if(index == 0) {
        this->mainDrawView->setCurrentColor(Qt::black);
    } else if(index == 1) {
        this->mainDrawView->setCurrentColor(Qt::red);
    } else if(index == 2) {
        this->mainDrawView->setCurrentColor(Qt::blue);
    } else if(index == 3) {
        this->mainDrawView->setCurrentColor(Qt::yellow);
    } else if(index == 4) {
        this->mainDrawView->setCurrentColor(Qt::cyan);
    } else if(index == 5) {
        this->mainDrawView->setCurrentColor(Qt::magenta);
    } else if(index == 6) {
        this->mainDrawView->setCurrentColor(Qt::darkBlue);
    } else if(index == 7) {
        this->mainDrawView->setCurrentColor(Qt::darkRed);
    } else if(index == 8) {
        this->mainDrawView->setCurrentColor(Qt::green);
    } else if(index == 9) {
        this->mainDrawView->setCurrentColor(Qt::darkGreen);
    } else if(index == 10) {
        this->mainDrawView->setCurrentColor(Qt::darkGray);
    } else if(index == 11) {
        this->mainDrawView->setCurrentColor(Qt::gray);
    }

}

void MainWindow::brushBox_currentIndexChanged(int index) {

    //TODO All the other colors.
    if(index == 0) {
        this->mainDrawView->setBrushStyle(Qt::NoBrush);
    } else if(index == 1) {
        this->mainDrawView->setBrushStyle(Qt::SolidPattern);
    } else if(index == 2) {
        this->mainDrawView->setBrushStyle(Qt::Dense1Pattern);
    } else if(index == 3) {
        this->mainDrawView->setBrushStyle(Qt::Dense2Pattern);
    } else if(index == 4) {
        this->mainDrawView->setBrushStyle(Qt::Dense3Pattern);
    } else if(index == 5) {
        this->mainDrawView->setBrushStyle(Qt::Dense4Pattern);
    } else if(index == 6) {
        this->mainDrawView->setBrushStyle(Qt::Dense5Pattern);
    } else if(index == 7) {
        this->mainDrawView->setBrushStyle(Qt::Dense6Pattern);
    } else if(index == 8) {
        this->mainDrawView->setBrushStyle(Qt::Dense7Pattern);
    } else if(index == 9) {
        this->mainDrawView->setBrushStyle(Qt::HorPattern);
    } else if(index == 10) {
        this->mainDrawView->setBrushStyle(Qt::VerPattern);
    } else if(index == 11) {
        this->mainDrawView->setBrushStyle(Qt::CrossPattern);
    } else if(index == 12) {
        this->mainDrawView->setBrushStyle(Qt::BDiagPattern);
    } else if(index == 13) {
        this->mainDrawView->setBrushStyle(Qt::FDiagPattern);
    } else if(index == 14) {
        this->mainDrawView->setBrushStyle(Qt::DiagCrossPattern);
    }

}


void MainWindow::widthSlider_valueChanged(int index) {

    if(!this->widthButtonPressed) {
        static int previousValue = 0;

        int interval = index - previousValue;

        previousValue = index;

        if(this->mainDrawView->getWidth() + interval >= 0 || this->mainDrawView->getEditState())
            this->mainDrawView->setWidth(this->mainDrawView->getWidth() + interval);

    } else {
        this->widthButtonPressed = false;
    }
}

void MainWindow::on_flat_clicked(bool checked) {
    if(checked) {
        this->mainDrawView->setCap(Qt::FlatCap);
    }
}

void MainWindow::on_round_clicked(bool checked) {
    if(checked) {
        this->mainDrawView->setCap(Qt::RoundCap);
    }
}

void MainWindow::on_square_clicked(bool checked) {
    if(checked) {
        this->mainDrawView->setCap(Qt::SquareCap);
    }
}
