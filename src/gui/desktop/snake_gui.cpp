#include "../../brick_game/snake/snake.h"
#include "ui_snake.h"

void Snake::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    static bool trigger = true;

    m_paint.begin(this);
    m_paint.setRenderHint(QPainter::Antialiasing);


    m_paint.setPen(QPen(Qt::black, 2));
    m_paint.drawRect(0, 0, m_width - 1, m_width - 1);

    if (m_state == GAME_INIT)
    {
    }
    else if (m_state == GAME_RUN)
    {
        m_paint.setPen(QPen(Qt::black, Snake::m_step, Qt::SolidLine, Qt::FlatCap));
        m_paint.drawPoints(&m_field[0], m_field.size());
    }
    else if (m_state == GAME_OVER)
    {
        if (trigger)
        {
            m_paint.setPen(QPen(Qt::lightGray, Snake::m_step, Qt::SolidLine, Qt::FlatCap));
            m_paint.drawPoints(&m_field[0], m_field.size());
            trigger = false;
        }
        else
        {
            m_paint.setPen(QPen(Qt::transparent, Snake::m_step, Qt::SolidLine, Qt::FlatCap));
            m_paint.drawPoints(&m_field[0], m_field.size());
            m_paint.eraseRect(m_target);
            trigger = true;
        }
        QTimer::singleShot(500, this, SLOT(update()));
    }

    m_paint.setPen(Qt::red);
    m_paint.setBrush(Qt::red);
    m_paint.drawEllipse(m_target);

    m_paint.end();
}