#include "enemy.h"
#include "config.h"

enemy::enemy()
{
    //enemy资源
    m_enemy.load(":/images/image5.png");

    //enemy位置
    m_X=0;
    m_Y=0;

    //enemy状态
    m_Free = true;

    //enemy速度
    m_Speed = ENEMY_SPEED;

    //enemy边框
    m_Rect.setWidth(m_enemy.width());
    m_Rect.setHeight(m_enemy.height());
    m_Rect.moveTo(m_X,m_Y);
}

void enemy::updatePosition()
{
    //空闲
    if (m_Free)
    {
        return;
    }

    //enemy向左移动
    m_X-=m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //屏幕外变为空闲
    if(m_X<=-m_Rect.width())
    {
        m_Free=true;
    }
}
