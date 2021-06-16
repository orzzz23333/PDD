#ifndef WARNING_H
#define WARNING_H

#include <QDialog>

namespace Ui {
class warning;
}

class warning : public QDialog
{
    Q_OBJECT

public:
    explicit warning(QWidget *parent = nullptr);
    ~warning();
    void setText(std::string str);

private:
    Ui::warning *ui;
};

#endif // WARNING_H
