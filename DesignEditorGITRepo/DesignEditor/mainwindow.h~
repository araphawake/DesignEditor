#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/* MainWindow.cpp 
 *
 * The main window where all elements of this program are displayed is 
 * configured by this class. Do not modify this file.
 * 
 * Author: Azevedo Moscoso Silva Cruz, Rafael; Cruz, RAMSC.
 * 25 October 2015
 */

#include <QMainWindow>
#include "qtextedit.h"
#include "qboxlayout.h"
#include <QCloseEvent>
#include "Zonededessin.h"
#include "qaction.h"
#include "qslider.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
    	// Constructor of the class.
        explicit MainWindow(QWidget *parent = 0);
        // Method for closing the program.
        void closeEvent(QCloseEvent *event);
        // Method for updating the width value of the slider in the mainwindow UI.
        virtual void updateWidthSlider(int width);
        // Method to notice users about features which will be available only 
        // in the future releases.
        virtual void showFutureReleaseNotice();
     	// Destructor of the class MainWindow
        ~MainWindow();

    public slots:
    	// Slot method for updating the Shape of the current drawing.
        void updateShape();
        // Slot method for opening and loading a file. Not yet finished.
        void openFile();
        // Slot method for saving current drawing into a file.
        void saveFile();
        // Slot method for quitting the application.
        void quitApp();
        // Slot method for closing the application.
        void exitProgram();
        // Slot method for returning to the application without closing it.
        void returnProgram();
        // Slot method for updating the current color.
        void updateColor();
        // Slot method for updating the outline width used for painting.
        void updateWidth();
        // Slot method for updating the current type of brush used for painting.
        void updateBrushPattern();
        // Slot method for updating the Cap Style used for painting.
        void updateCapStyle();
        // Slot method for updating Join Style used for painting.
        void updateJoinStyle();
        // Slot method for updating the Mode of the application (DRAW, EDIT or TRANSLATE).
        void updateMode();
        // Slot method to erase all figures/drawings included into the canvas(ZoneDeDessin).
        void eraseAllCallback();

private slots:
		// Slot method for updating the current color selected in the UI.
        void colorBox_currentIndexChanged(int index);
        // Slot method for updating the brush type selected in the UI.
        void brushBox_currentIndexChanged(int index);
        // Slot method for updating the current width slider value selected in the UI.
        void widthSlider_valueChanged(int index);
		// Slot method for updating the value (checked or unchecked) of 
		//the box button corresponding to the cap style FLAT selected in the UI.
        void on_flat_clicked(bool checked);
		// Slot method for updating the value (checked or unchecked) of 
		//the box button corresponding to the cap style ROUND selected in the UI.
        void on_round_clicked(bool checked);
		// Slot method for updating the value (checked or unchecked) of 
		//the box button corresponding to the cap style SQUARE selected in the UI.
        void on_square_clicked(bool checked);

private:
		// A Window of notice concerning features planned for future releases.
        QWidget * window;
        // A container view for the window attribute.
        QVBoxLayout * warning;
        // The canvas which contains and manages all the drawing activities.
        ZoneDeDessin * mainDrawView;
        // A list of all actions concerning the adjustment of the current shape for drawing.
        QList<QAction*> shapeActions;
        // A list of all actions concerning the adjustment of the current color for drawing.
        QList<QAction*> colorActions;
        // A list of all actions concerning the adjustment of the current width for drawing.
        QList<QAction*> widthActions;
        // A list of all actions concerning the adjustment of the current brush for drawing.
        QList<QAction*> brushActions;
        // A list of all actions concerning the adjustment of the current Cap Style for drawing.
        QList<QAction*> capActions;
        // A list of all actions concerning the adjustment of the current Join Style for drawing.
        QList<QAction*> joinActions;
        // OBSOLETE: A text view used in a previous release.
        QTextEdit * mainTextView;
        // A group of actions concerning the update of the current shape.
        QActionGroup * selectShape;
        // A group of actions concerning the update of the current color.
        QActionGroup * selectColor;
        // A group of actions concerning the update of the current width.
        QActionGroup * selectWidthPen;
        // A group of actions concerning the update of the current brush style.
        QActionGroup * selectBrushStyle;
        // A group of actions concerning the update of the current cap style.
        QActionGroup * selectCapStyle;
        // A group of actions concerning the update of the current join style.
        QActionGroup * selectJoinStyle;
        // A group of actions concerning the update of the current Mode.
        QActionGroup * selectMode;
        // Action for cleaning the Canvas/ZoneDeDessin.
        QAction * eraseAll;
        // Flag to indicate if a button has been pressed for updating the width value.
        bool widthButtonPressed;
        // The User Interface of the application.
        Ui::MainWindow * ui;
};

#endif // MAINWINDOW_H
