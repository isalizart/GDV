#ifndef RENDERVIEW_H
#define RENDERVIEW_H

#include <QWidget>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QCamera>

namespace Ui {
    class RenderView;
}

class RenderView : public QWidget
{
    Q_OBJECT

public:
    explicit RenderView(QWidget *parent = 0);
    ~RenderView();

protected:
    // returns root node of 3d scene
    Qt3DCore::QEntity* createScene();
    
    // currently only creates headlight
    void createLights();
    
    // sets camera parameters along with controller
    void setCameraAndParams(Qt3DRender::QCamera *cam);
    
protected slots:
    void showTrafo6j(bool visible);
    void showTrafo6k(bool visible);
    void showTrafo6l(bool visible);
    void showTrafo6m(bool visible);
    void showTrafo7b(bool visible);
    void showTrafo7c(bool visible);

private:
    Ui::RenderView *ui;
    
    Qt3DCore::QEntity *root;
    
    Qt3DRender::QCamera *camera;
    
    Qt3DCore::QEntity *node_6j, // holds subtree for exercise 7.b (6.j)
                      *node_6k, // holds subtree for exercise 7.b (6.k)
                      *node_6l, // holds subtree for exercise 7.b (6.l)
                      *node_6m, // holds subtree for exercise 7.b (6.m)
                      *node_7b, // holds subtree with untransformed box
                      *node_7c; // holds subtree for exercise 7.c (6.m)
};

#endif // RENDERVIEW_H
