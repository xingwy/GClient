#ifndef QUI_H
#define QUI_H

#include <QObject>
#include <QWidget>
#include <QMainWindow>

class QUi : public QWidget
{
    Q_OBJECT
public:
    explicit QUi(QWidget *parent = nullptr);

signals:

};

#endif // QUI_H
