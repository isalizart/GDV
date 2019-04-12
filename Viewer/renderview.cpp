#include <Qt3DRender/QPointLight>
#include <Qt3DRender/QSceneLoader>
#include <Qt3DExtras>
#include <iostream>
#include <assert.h>

#include "renderview.h"
#include "ui_renderview.h"

#define CAMERA_DISTANCE 15.0f


RenderView::RenderView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RenderView),
    root(NULL),
    camera(NULL)
{
    ui->setupUi(this);
    
    node_6j = node_6k = node_6l = node_6m = node_7b = node_7c = NULL;

    // Create 3D render window and replace placeholder widget in UI
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(200, 255, 200));

    QWidget *container = QWidget::createWindowContainer(view);
    container->setGeometry(ui->viewarea->geometry());
    container->setSizePolicy(ui->viewarea->sizePolicy());
    
    ui->horizontalLayout->replaceWidget(ui->viewarea, container);
    delete ui->viewarea;
    ui->viewarea = container;
    
    // Create root node
    root = createScene();
    
    view->setRootEntity(root);
    
    // Parameterize camera
    setCameraAndParams(view->camera());
    
    // Creates headlight, requires valid camera
    createLights();
    
    // connect checkbox events to handlers
    QObject::connect(ui->checkBox_6j, &QCheckBox::stateChanged,
                     this, &RenderView::showTrafo6j);
    QObject::connect(ui->checkBox_6k, &QCheckBox::stateChanged,
                     this, &RenderView::showTrafo6k);
    QObject::connect(ui->checkBox_6l, &QCheckBox::stateChanged,
                     this, &RenderView::showTrafo6l);
    QObject::connect(ui->checkBox_6m, &QCheckBox::stateChanged,
                     this, &RenderView::showTrafo6m);
    QObject::connect(ui->checkBox_7b, &QCheckBox::stateChanged,
                     this, &RenderView::showTrafo7b);
    QObject::connect(ui->checkBox_7c, &QCheckBox::stateChanged,
                     this, &RenderView::showTrafo7c);
}

RenderView::~RenderView()
{
    delete ui;
}

Qt3DCore::QEntity* RenderView::createScene()
{
    // Root
    Qt3DCore::QEntity *scene = new Qt3DCore::QEntity();
    
    // base nodes for sub scenes for exercises 7.b and 7.c (6.j - 6.m)
    node_6j = new Qt3DCore::QEntity(scene);
    node_6k = new Qt3DCore::QEntity(scene);
    node_6l = new Qt3DCore::QEntity(scene);
    node_6m = new Qt3DCore::QEntity(scene);
    node_7b = new Qt3DCore::QEntity(scene);
    node_7c = new Qt3DCore::QEntity(scene);
    
    // Cube
    Qt3DExtras::QCuboidMesh *cubeMesh = new Qt3DExtras::QCuboidMesh();
    cubeMesh->setXExtent(2);
    cubeMesh->setYExtent(2);
    cubeMesh->setZExtent(2);
    
    Qt3DExtras::QPhongMaterial *cubeMat = new Qt3DExtras::QPhongMaterial();
    cubeMat->setDiffuse(QColor(255, 0, 0)); // can be reused for same color
    
    Qt3DCore::QTransform *cubeTransform = new Qt3DCore::QTransform();
    
    node_7b->addComponent(cubeMesh);
    node_7b->addComponent(cubeMat);
    node_7b->addComponent(cubeTransform);

    
    // TODO: 7.b)
    // Cube transformed according to exercise 6.j)
    
    // Cube transformed according to exercise 6.k)
    
    // Cube transformed according to exercise 6.l)
    
    // Cube transformed according to exercise 6.m)
    
    
    // TODO: 7.c)
    // Cube transformed according to exercise 6.m), but with transformation
    // hierarchy instead of single matrix (note that here node_7c should be
    // lowest in hierarchy to make toggling visibility work in that case).
    
    
    return scene;
}

void RenderView::setCameraAndParams(Qt3DRender::QCamera *cam)
{
    cam->lens()->setPerspectiveProjection(45.0f, 1.0f, 0.1f, 1000.0f);
    
    cam->setViewCenter(QVector3D(0, 0, 0));
    cam->setPosition(QVector3D(0, 0, CAMERA_DISTANCE));
    
    camera = cam;
    
    // Camera controls to allow changing viewpoint
    Qt3DExtras::QOrbitCameraController *camController =
                                new Qt3DExtras::QOrbitCameraController(root);
    camController->setCamera(cam);
    camController->setLinearSpeed(50.0f);
    camController->setLookSpeed(100.0f);
}

void RenderView::createLights()
{
    // Currently only point light that acts as headlight
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight();
    light->setIntensity(1);
    light->setColor(QColor(255, 255, 255));
    
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform();
    lightTransform->setTranslation(QVector3D(0, 0, CAMERA_DISTANCE));

    Qt3DCore::QEntity *lightNode = new Qt3DCore::QEntity(root);
    lightNode->addComponent(light);
    lightNode->addComponent(lightTransform);
    
    // connect to lambda func, where changed view is used to set light trafo
    assert(camera != NULL);
    QObject::connect(camera, &Qt3DRender::QCamera::viewMatrixChanged,
                     [=]() {
                         QMatrix4x4 viewmat = camera->viewMatrix();
                         lightTransform->setMatrix(viewmat.inverted());
                     });
}

void RenderView::showTrafo6j(bool visible)
{
    if (node_6j)
        node_6j->setEnabled(visible);
}

void RenderView::showTrafo6k(bool visible)
{
    if (node_6k)
        node_6k->setEnabled(visible);
}

void RenderView::showTrafo6l(bool visible)
{
    if (node_6l)
        node_6l->setEnabled(visible);
}

void RenderView::showTrafo6m(bool visible)
{
    if (node_6m)
        node_6m->setEnabled(visible);
}

void RenderView::showTrafo7b(bool visible)
{
    if (node_7b)
        node_7b->setEnabled(visible);
}

void RenderView::showTrafo7c(bool visible)
{
    if (node_7c)
        node_7c->setEnabled(visible);
}
