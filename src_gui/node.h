#ifndef NODE_H
#define NODE_H

#include <QVector>
#include <QVariantMap>
#include "gate.h"

// Node konstruktor should be private
class Node {
    friend class JsonFileHandler;
    friend class NodeFactory;
    friend class NodeCatalog;

public:
    struct Parameter {
        QString descr;
        QString key;
        QString name;
        QString type;
        QVariant value;
    };

    enum Status {
        idle,
        busy,
        finished,
        error,
    };

    Node();
    ~Node();
    QMap<QString, Parameter> *getParams();

    Node(QVector<Gate *> &inputGates, QVector<Gate *> &outputGates, QString &type,
         QString &name, QMap<QString, Parameter> &params);

    /**
     * @brief addGate add a Gate to the Node
     * @param gate
     */
    void addGate(Gate *gate);

    /**
     * @brief addGates add multiple Gates
     * @param gates
     * @param direction
     */
    void addGates(const QVector<Gate *> &gates, const bool &direction);
    void addGates(const QVector<Gate *> &gates);

    /**
 * @brief Set the position of the Node
 * @param x new position_x
 * @param y new position_y
 */
    void moveTo(float x, float y);

    void setType(const QString &type);

    QString getType();

    void setName(const QString &name);

    QString getName();

    QVector<Gate *> *getInputGates();

    QVector<Gate *> *getOutputGates();

    bool setParam(QString key, QVariant _value);

    bool removeParam(QString _key);

    QVariant getParamByKey(const QString &_key);

    QString toString();

    Gate *getGateByName(const QString &name);
    void addParam(QString key, Parameter p);
    float x() const;
    float y() const;

    QString getDescription();
    void setDescription(const QString &value);
    void setX(const float &newX);
    void setY(const float &newY);
    int getID() const;
    void setID(const int &value);
    QPoint getPosition();
    QPoint getGatePosition(QString gateName);
    Node::Parameter getParamStructByKey(const QString &key);
    Status getStatus() const;
    void setStatus(const Status &value);

    unsigned char getProgress() const;
    void setProgress(unsigned char value);
private:
    bool addParam(const QString &descr, const QString &_key, const QString &name, const QString &type,
                  const QVariant &_value);
    QString description;
    QVector<Gate *> inputGates, outputGates;
    QString type, name;
    int ID = -2;
    QMap<QString, Parameter> params;  // maps <identifier, value>
    unsigned char progress;
    Status status;
    float position_x;
    float position_y;
};

#endif  // NODE_H
