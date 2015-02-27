#ifndef SINGLETONRENDER_H
#define SINGLETONRENDER_H

#include "mainwindow.h"
#include "mesh.h"
#include "node.h"
#include "drawobject.h"

// The life of the singleton instantiation is for the duration of the
// application.

class SingletonRender {
public:
    // The instance function returns a pointer to a static variable and thus is
    // declared static.
    static SingletonRender *instance();

    // will load all images in ../Data/Images/ into the allImages Map
    bool loadImages();

    //16 by 16 Tile images for the node
    /*
     * 0|1|2
     * 3|4|5
     * 6|7|8
     */
    QPixmap nodeTiles[9];

    bool createTilesFromImage(QPixmap *Sprite);

    QPixmap* createTiledPixmap(int x, int y);

    void setUi(Ui::MainWindow *ui);

    /*
   * Renders the whole mesh
   */
    void renderMesh(Mesh *workMesh);

    /*
     * Clears the MeshField
     */
    void clearMeshField();

    bool deleteMeshDrawing(int objectID);

    /*
     *Testfunction of Deleting
     * Returns all ID's of given widget
     */
    QVector<int> *getChildrenIDs();








    /**
      recieves a connection and will render it on the mesheditor widget

     * @brief renderConnection
     * @param conToRender the connection that will be rendered
     */
    void renderConnection(Connection *conToRender,int ID);

    void renderConnections();


    /*
   * Renders a node.
   *
   */
    void renderNode(Node *nodeToRender, int nodeID);

    /*
   * Render one Node Type in the Catalog
   *
   */
    void renderNodeType(Node *nodeToRender, QWidget *parent, int position);

    /*
   * This will Render all Nodes in the Type Catalog.
   */
    void renderCatalogContent(QVector<Node> NodeVektor);

    /*
     * Draws a line from start x y to end x y
     *
     */
    void drawLine(double start_x, double start_y, double end_x ,double end_y);

    void drawLine(QLine line);

    void drawLine(QPoint start, QPoint end);

    void drawLines(QVector<QPoint> *pointVector);

    void drawLines(QVector<QPoint> *pointVector, QPoint *point);






    QPoint getOutputGateDrawOffset() const;
    void setOutputGateDrawOffset(const QPoint &value);

    QPoint getInputGateDrawOffset() const;
    void setInputGateDrawOffset(const QPoint &value);

    void dehighlightObject(int ID);
    void highlightObject(int ID);

    QPixmap *getImage(QString name);
    void highlightGates(QString gateType);
    void dehighlightGates();
private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_Apply_clicked(QAbstractButton *button);

private:

    void paintEvent(QPaintEvent *event);

    void clearAll(QWidget *parent); // Deletes all children of given parent

    QPainter painter;

    // this is the map containing all raw Images.
    // Qstring is the same as the filename
    // QPixmap a .png image
    QMap<QString, QPixmap *> allImages;

    QPoint inputGateDrawOffset;
    QPoint outPutGateDrawOffset;

    //Different lists because we will need to work differently with them
    QMap<int, DrawObject *> allDrawnNodes;
    QMap<int, QVector<DrawObject *> > allConnections;
    QMap<int, QVector<QLine> > allLines;
    QColor lineColor = QColor(30,30,35);

    // window of application
    Ui::MainWindow *ui;

    //###### singleton stuff ########

    // Private so that it can  not be called
    // Only the class function Instance can call the constructor. Public access to
    // the constructor is denied.
    SingletonRender();

    // The constructor, copy constructor and assignment operator are all private
    // to ensure that the
    // programmer using the singleton class can only create a single instance of
    // the class using only the Instance() function.

    // copy constructor is private
    SingletonRender(SingletonRender const &){};

    // assignment operator is private
    SingletonRender &operator=(SingletonRender const &){
        return *this;
    };

    // pointer to this instance
    static SingletonRender *m_pInstance;
};

#endif  // SINGLETONRENDER_H
