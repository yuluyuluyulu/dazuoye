#include "hero.h"
#include "config.h"

hero::hero()
{
    //加载图片
    m_hero.load(":/images/image2.png");

    //初始化坐标
    m_Y = (GAME_HEIGHT-m_hero.height())*0.5;
    m_X = 0;

    //初始化矩形边框
    m_Rect.setWidth(m_hero.width());
    m_Rect.setHeight(m_hero.height());
    m_Rect.moveTo(m_X,m_Y);
}

void hero::shoot()
{
    //累计时间间隔记录变量
    m_recorder++;

    //未到时间间隔不发射
    if(m_recorder<JIANGE)
    {
        return;
    }

    //达到时间间隔,fashe
    m_recorder=0;

    for(int i=0;i<NUMBER;i++)
    {
        //空闲发射
        if( m_bullets[i].m_Free)
        {
            m_bullets[i].m_Free = false;

            //设置子弹坐标
            m_bullets[i].m_X=m_X+50;
            m_bullets[i].m_Y=m_Y+40;
            break;//一发
        }
    }
}

void hero::setPosition(int x, int y)
{
    m_X = x;
    m_Y = y;
    m_Rect.moveTo(m_X,m_Y);
}

