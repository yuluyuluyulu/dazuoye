#ifndef MAINSCENE_H
#define MAINSCENE_H
#include <QWidget>
#include<QTimer>
#include<map.h>
#include<hero.h>
#include "bullet.h"
#include "enemy.h"

class MainScene : public QWidget
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //初始化场景
    void initScene();

    //启动游戏
    void playGame();

    //更新游戏元素坐标
    void updatePosition();

    //绘制于屏幕
    void paintEvent(QPaintEvent*);

    //鼠标控制移动
    void mouseMoveEvent(QMouseEvent*);

    //enemy出场
    void enemyToScene();

    //碰撞检测
    void collisionDetection();

    //enemy数组
    enemy m_enemys[ENEMY_NUM];

    //enemy出场间隔记录
    int m_recorder;


    //地图对象
    Map m_map;

    //hero对象
    hero m_hero;

    //定时器
    QTimer m_Timer;

    //子弹对象
    //Bullet temp_Bullet;
};

#endif // MAINSCENE_H
