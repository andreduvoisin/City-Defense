#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QTextEdit>
#include <QString>
#include <QRadioButton>
#include <QListView>
#include <QStandardItemModel>
#include <QPixmap>
#include <QKeyEvent>
#include <QMainWindow>
#include <QGraphicsSceneMouseEvent>
#include <QLabel>
#include <QVBoxLayout>

#include "thing.h"
#include "fastenemy.h"
#include "slowenemy.h"
#include "bouncingenemy.h"
#include "player.h"
#include "blimp.h"
#include "city.h"
#include "graphicsscene.h"
#include "bullet.h"

#define WINDOW_X 300
#define WINDOW_Y 600

class GraphicsScene;

/** MainWindow handles all of the gameplay with Qt and
 * all other GUI-based entities in the program. */
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
	/** Default constructor. */
    explicit MainWindow();
    /** Default destructor. */
    ~MainWindow();
    /** Displays the view. */
	void show();
	void setKeyLeft(bool kl);
	void setKeyRight(bool kr);
	void setKeySpace(bool ks);
    
private:
	/** The scene for displaying the board. */
    GraphicsScene *scene;
    /** The view for displaying the board. */
    QGraphicsView *view;
    /** Buttons for starting, pausing, and quitting the game. */
    QPushButton *startButton, *pauseButton, *quitButton;
    /** Gameplay timer. */
    QTimer *moveTimer, *createTimer;
    Player *player;
    City *city;
    vector<Thing*> enemies;
    vector<Bullet*> bullets;
    bool keyLeft, keyRight, keySpace, prevKeySpace;
    QGraphicsPixmapItem *background;
    int numMoveTicks;

public slots:
	/** Starts the game based on the inputs. Called when the start button is pressed. */
	void start();
	/** Pauses the game. */
	void pause();
	/** Ends the game. Called when the end button is pressed. */
	void quit();
	void handleMoveTimer();
	void handleCreateTimer();
};

#endif // MAINWINDOW_H
