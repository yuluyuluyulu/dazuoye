#ifndef HERO_H
#define HERO_H
#include<Qpixmap>
#include<QRect>
#include "bullet.h"

class hero
{
public:
    hero();

    //发射子弹
    void shoot();

    //设置英雄位置
    void setPosition(int x ,int y);

public:
    //对象
    QPixmap m_hero;

    //坐标
    int m_X;
    int m_Y;

    //人物矩形边框
    QRect m_Rect;

    //弹匣
    Bullet m_bullets[NUMBER];

    //发射间隔记录
    int m_recorder;
};

#endif // HERO_H
