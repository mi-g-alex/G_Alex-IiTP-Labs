#include <QtWidgets>
#include "../figures/figures.h"
#include "../figures/figureTriangle.h"
#include "../figures/figureSquare.h"
#include "../figures/figureCircle.h"
#include "../figures/figureRhombus.h"
#include "../figures/figureStar/star_5.h"
#include "../figures/figureStar/star_6.h"
#include "../figures/figureStar/star_7.h"
#include "../figures/figureStar/star_8.h"
#include "../figures/figureHexagon.h"
#include "../figures/figurePolyline.h"

class mainWindow : public QWidget {
Q_OBJECT
public:
    explicit mainWindow(QWidget *obj = nullptr);

private:
    figures **figuresArray = new figures *[10];

    // Radio buttons
    QRadioButton *triangleButton;
    QRadioButton *circleButton;
    QRadioButton *rhombusButton;
    QRadioButton *rectangleButton;
    QRadioButton *starButton;
    QSpinBox *spin5to8;
    QRadioButton *hexagonButton;
    QRadioButton *polylineButton;

    // Actions Buttons
    QRadioButton *drawButton;
    QRadioButton *moveButton;
    QPushButton *sizeP;
    QPushButton *sizeM;
    QPushButton *rotateL;
    QPushButton *rotateR;

    QLabel *textCenter;
    QLabel *textSquare;
    QLabel *textPerimeter;


    QTimer *timer = new QTimer;

    // Figures
    figureTriangle *triangle = new figureTriangle;
    figureCircle *circle = new figureCircle;
    figureRhombus *rhombus = new figureRhombus;
    figureSquare *square = new figureSquare;

    star_5 *star5 = new star_5;
    star_6 *star6 = new star_6;
    star_7 *star7 = new star_7;
    star_8 *star8 = new star_8;

    figureHexagon *hexagon = new figureHexagon;
    figurePolyline *polyline = new figurePolyline;


    bool isShift = false;
    int selectedFigureID = 0;
    int cnt = 0;

    void setInfo();

private slots:

    void selectFigure();

    void closeButtonClicked();

    void upSize();

    void downSize();

    void rotateLeft();

    void rotateRight();

    void star();

    void on_sizeP_pressed();

    void on_sizeP_released();

    void on_sizeM_pressed();

    void on_sizeM_released();

    void on_rotateL_pressed();

    void on_rotateL_released();

    void on_rotateR_pressed();

    void on_rotateR_released();

protected:
    void paintEvent(QPaintEvent *) override;

    void mousePressEvent(QMouseEvent *me) override;

    void mouseMoveEvent(QMouseEvent *me) override;

    void mouseReleaseEvent(QMouseEvent *me) override;

    void keyPressEvent(QKeyEvent *ke) override {
        if (ke->modifiers() & Qt::ShiftModifier) {
            isShift = true;
        }
    }

    void keyReleaseEvent(QKeyEvent *ke) override {
        if (!(ke->modifiers() & Qt::ShiftModifier)) {
            isShift = false;
        }
    }

};

