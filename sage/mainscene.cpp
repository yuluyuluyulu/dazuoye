#include "mainscene.h"
#include "config.h"
#include<QPainter>
#include<QMouseEvent>
#include<ctime>
MainScene::MainScene(QWidget *parent)
    : QWidget(parent)
{
    //初始化
    initScene();

    //启动游戏
    playGame();

}

MainScene::~MainScene()
{
}

void MainScene::initScene()
{
    //设置窗口尺寸
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //标题
    setWindowTitle(GAME_TITLE);

    //定时器
    m_Timer.setInterval(GAME_RATE);

    //初始化enemy出场时间间隔
    m_recorder=0;

    //随机数种子
    srand((unsigned int)time(NULL));


}

void MainScene::playGame()
{
    //启动定时器
    m_Timer.start();

    //发送信号
    connect(&m_Timer,&QTimer::timeout,[=]()
            {

                //enemy出场
                enemyToScene();

                //更新坐标
                updatePosition();

                //绘制
                update();

                //碰撞检测
                collisionDetection();
    });
}

void MainScene::updatePosition()
{
    //更新地图坐标
    m_map.mapPosition();

    //发射子弹
    m_hero.shoot();

    //计算非空闲子弹坐标
    for(int i=0;i<NUMBER;i++)
    {
        //非空闲
        if(m_hero.m_bullets[i].m_Free == false)
        {
            m_hero.m_bullets[i].updatePosition();
        }
    }

    //enemy出场
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //非空闲
        if(m_enemys[i].m_Free == false)
        {
            m_enemys[i].updatePosition();
        }
    }

    //测试子弹
    //temp_Bullet.m_Free = false;
    //temp_Bullet.updatePosition();
}

void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //绘制地图
    painter.drawPixmap(m_map.m_map1_posX,0,m_map.m_map1);
    painter.drawPixmap(m_map.m_map2_posX,0,m_map.m_map2);

    //绘制hero
    painter.drawPixmap(m_hero.m_X,m_hero.m_Y,m_hero.m_hero);

    //绘制子弹
    for(int i=0;i<NUMBER;i++)
    {
        //非空闲
        if(m_hero.m_bullets[i].m_Free == false)
        {
            painter.drawPixmap(m_hero.m_bullets[i].m_X,m_hero.m_bullets[i].m_Y,m_hero.m_bullets[i].m_Bullet);
        }
    }

    //绘制enemy
    for(int i=0;i<ENEMY_NUM;i++)
    {
        //非空闲
        if(m_enemys[i].m_Free == false)
        {
            painter.drawPixmap(m_enemys[i].m_X,m_enemys[i].m_Y,m_enemys[i].m_enemy);
        }
    }

    //测试子弹
    //painter.drawPixmap(temp_Bullet.m_X,temp_Bullet.m_Y,temp_Bullet.m_Bullet);

}

void MainScene::mouseMoveEvent(QMouseEvent * event)
{
    int x =event->x() - m_hero.m_Rect.width()*0.5;
    int y =event->y() - m_hero.m_Rect.height()*0.5;

    //边界检测
    if(x <=0)
    {
        x=0;
    }
    if(x >=GAME_WIDTH - m_hero.m_Rect.width())
    {
        x=GAME_WIDTH - m_hero.m_Rect.width();
    }
    if(y <=0)
    {
        y=0;
    }
    if(y >=GAME_HEIGHT - m_hero.m_Rect.height())
    {
        y=GAME_HEIGHT - m_hero.m_Rect.height();
    }

    m_hero.setPosition(x,y);

}

void MainScene::enemyToScene()
{
    //累计时间间隔记录变量
    m_recorder++;

    //未到时间间隔不出场
    if(m_recorder<ENEMY_INTERVAL)
    {
        return;
    }

    //达到时间间隔,出场
    m_recorder=0;

    for(int i=0;i<ENEMY_NUM;i++)
    {
        //空闲出场
        if( m_enemys[i].m_Free)
        {
            m_enemys[i].m_Free = false;

            //设置坐标
            m_enemys[i].m_X=GAME_WIDTH+m_enemys[i].m_Rect.width();
            m_enemys[i].m_Y=rand()%(GAME_HEIGHT-m_enemys[i].m_Rect.height());
            break;
        }
    }
}

void MainScene::collisionDetection()
{
    //bianli非空闲enemy
    for(int i=0;i<ENEMY_NUM;i++)
    {
        if( m_enemys[i].m_Free)
        {
            continue;
        }


        //遍历非空闲子弹
        for(int j=0;j<NUMBER;j++)
        {
            //空闲子弹continue
            if(m_hero.m_bullets[j].m_Free)
            {
                continue;
            }

            //相交则消失
            if(m_enemys[i].m_Rect.intersects(m_hero.m_bullets[j].m_Rect))
            {
                m_enemys[i].m_Free=true;
                m_hero.m_bullets[j].m_Free=true;
            }
        }
    }
}
