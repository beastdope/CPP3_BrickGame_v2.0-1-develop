#ifndef SNAKE_H
#define SNAKE_H

#define SSINGLESTEP

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QDateTime>
#include <QString>
#include <QElapsedTimer>  

class Snake : public QWidget
{
    Q_OBJECT

public:
    explicit Snake(QWidget *parent = nullptr);
    ~Snake();

    void startGame();
    Snake::state_T getState() const { return m_state; }
    Snake::direction_T getDirection() const { return m_direct; }
    QRect getTarget() const { return m_target; }

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    enum direction_T
    {
        MOVE_NONE = 0,
        MOVE_LEFT = 1,
        MOVE_RIGHT = 2,
        MOVE_UP = 3,
        MOVE_DOWN = 4,
    };
    enum state_T
    {
        GAME_INIT = 0,
        GAME_RUN = 1,
        GAME_OVER = 2,
        GAME_EXIT = 3
    };

    const static quint8 m_step = 10;
    const static quint8 m_size = 4;
    const static quint16 m_delay = 500;
    const static quint8 m_counter = 4;

    void initGame(void);
    void evalGame(const QPoint &pointNext);
    void initTarget(void);
    void evalTarget(void);
    template<typename T>
    T getNumber(T limit, T offset) const;

    QPainter m_paint;
    quint16 m_width;
    QVector<QPoint> m_field;
    QVector<QPoint>::iterator m_idx;
    QRect m_target;
    state_T m_state;
    direction_T m_direct;
    quint16 *m_seed;
    QTimer *m_timerLeft;
    QTimer *m_timerRight;
    QTimer *m_timerUp;
    QTimer *m_timerDown;
    QTime *m_timeTrigger;
    QTime *m_timeThreshold;

signals:
    void exit(void);

private slots:
    void moveLeft(void);
    void moveRight(void);
    void moveUp(void);
    void moveDown(void);

};

#endif // SNAKE_H
