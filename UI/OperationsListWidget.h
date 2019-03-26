#ifndef OPERATIONSLISTWIDGET_H
#define OPERATIONSLISTWIDGET_H

#include <QListWidget>
#include <QDragMoveEvent>
#include "ui_operationslistwidget.h"

class OperationsListWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit OperationsListWidget(QWidget *parent = 0);
    ~OperationsListWidget();
    static inline QString operationBoxWidgetMimeType(){ return QStringLiteral("application/x-operationboxwidget"); }

protected:
    void dragMoveEvent(QDragMoveEvent* e);
    void dropEvent(QDropEvent* event);
    void startDrag(Qt::DropActions supportedActions);
    void dragEnterEvent(QDragEnterEvent* event);
    void keyPressEvent(QKeyEvent *e);
    Qt::DropAction supportedDropActions();

    int i;
signals:
    void itemDroped();

private:
    Ui::OperationsListWidget *ui;
};

#endif // OPERATIONSLISTWIDGET_H
