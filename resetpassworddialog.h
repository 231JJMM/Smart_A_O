#ifndef RESETPASSWORDDIALOG_H
#define RESETPASSWORDDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ResetPasswordDialog; }
QT_END_NAMESPACE

class ResetPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResetPasswordDialog(const QString &token, QWidget *parent = nullptr);
    ~ResetPasswordDialog();

private slots:
    void on_pushButton_reset_clicked();

private:
    Ui::ResetPasswordDialog *ui;
    QString resetToken;
};

#endif // RESETPASSWORDDIALOG_H
