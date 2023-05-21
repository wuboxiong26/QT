#ifndef SELECTLOGIN_H
#define SELECTLOGIN_H

#include <QWidget>

namespace Ui{
class SelectLogin;
}

class SelectLogin : public QWidget
{
    Q_OBJECT

public:
    explicit SelectLogin(QWidget *parent = 0);
    ~SelectLogin();


private slots:


private:
    Ui::SelectLogin *ui;
};

#endif // SELECTLOGIN_H
