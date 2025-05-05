#include "bullet.h"

Bullet::Bullet()
{
    //加载资源
    m_Bullet.load(":/images/image4.png");

    //子弹坐标
    m_Y = (GAME_HEIGHT-m_Bullet.height())*0.5;
    m_X = 0;

    //子弹状态
    m_Free = true;

    //子弹速度
    m_Speed = SPEED;

    //子弹边框
    m_Rect.setWidth(m_Bullet.width());
    m_Rect.setHeight(m_Bullet.height());
    m_Rect.moveTo(m_X,m_Y);
}

void Bullet::updatePosition()
{
    //空闲
    if (m_Free)
    {
        return;
    }

    //子弹向右移动
    m_X+=m_Speed;
    m_Rect.moveTo(m_X,m_Y);

    //屏幕外变为空闲
    if(m_X<=-m_Rect.width())
    {
        m_Free=true;
    }


}
