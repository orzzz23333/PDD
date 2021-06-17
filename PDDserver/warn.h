#ifndef WARN_H
#define WARN_H

#include <QWidget>

namespace Ui {
class Warn;
}

class Warn : public QWidget
{
    Q_OBJECT

public:
    explicit Warn(QWidget *parent = nullptr);
    ~Warn();
    void setText(QString str);

private:
    Ui::Warn *ui;
};

#endif // WARN_H
