#include "mainwidget.h"

/**
 * @brief MainWidget::MainWidget
 * @param parent
 * 主界面
 * @author 派蒙今天吃什么
 */
MainWidget::MainWidget(QWidget *parent)
    : QWidget{parent}
{
    this->setFixedSize(400, 700);
    //General paramete
    //词库高度
    int wordSet_height = 60;
    //动画执行时间 (单位 毫秒）
    int animation_time = 400;
    //添加词汇和复习词汇的左上角坐标
    QPoint btn_pos(10, 550);
    //添加词汇和复习词汇的高度
    int btn_height = 60;
    //添加词汇和复习词汇的水平间距
    int btns_dis = 50;

    //添加词汇和复习词汇的宽度
    int btn_width = (this->width() - (2*btn_pos.rx()) - btns_dis)/2;

    //创建词库按钮
    wordSet_btn = new myLabelButton(this, 255, 255, 255, 155);
    //设置名称为词库
    wordSet_btn->setText("词库");
    //调整大小
    wordSet_btn->myResize(this->width() + 100, wordSet_height);
    //移动至目标位置
    wordSet_btn->myMove(-50, this->height() - wordSet_btn->height());

    //创建添加新词界面
    addNew_btn = new myLabelButton(this, 255, 255, 255, 155);
    //设置名称
    addNew_btn->setText("添加词汇");
    //调整大小
    addNew_btn->myResize(QSize(btn_width, btn_height));
    //移动至目标位置
    addNew_btn->myMove(btn_pos);

    // 创建wordle按钮
    wordle_btn = new myLabelButton(this, 255, 255, 255, 155);
    wordle_btn->setText("WORDLE");
    wordle_btn->myResize(this->width() + 100, 60);
    wordle_btn->myMove(-50, 0);

    //复习词汇目标位置
    QPoint review_pos(btn_pos.rx() + btn_width + btns_dis, btn_pos.ry());
    //创建复习词汇界面
    review_btn = new myLabelButton(this, 255, 255, 255, 155);
    //设置名称
    review_btn->setText("复习词汇");
    //调整大小
    review_btn->myResize(btn_width, btn_height);
    //移动至目标位置
    review_btn->move(review_pos);

    /**
     * 这里打算建一个date对象
     */
    calendar = new Calendar(this, 255, 255, 255, 155);
    calendar->move(123, 200);

}
