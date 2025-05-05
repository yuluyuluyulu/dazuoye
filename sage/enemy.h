#ifndef ENEMY_H
#define ENEMY_H
#include<QPixmap>

class enemy
{
public:
    enemy();

    //更新坐标
    void updatePosition();

public:
    //enemy资源
    QPixmap m_enemy;

    //位置
    int m_X;
    int m_Y;

    //enemy的矩形边框
    QRect m_Rect;

    //状态
    bool m_Free;

    //速度
    int m_Speed;

};

#endif // ENEMY_H
