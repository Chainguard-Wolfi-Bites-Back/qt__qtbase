// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QApplication>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QCalendarWidget>
#include <QVBoxLayout>

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget()
    {
        QWidget *stackWidget = new QWidget;
        stackWidget->setFixedSize(400, 300);
        button = new QPushButton("pushbutton", stackWidget);
        plainTextEdit = new QPlainTextEdit(stackWidget);
        plainTextEdit->setWordWrapMode(QTextOption::NoWrap);
        QString s = "foo bar bar foo foo bar bar foo";
        for (int i = 0; i < 10; ++i) {
            plainTextEdit->appendPlainText(s);
            s.remove(1, 2);
        }
        calendar = new QCalendarWidget(stackWidget);
        button->move(10, 10);
        button->resize(100, 100);
        plainTextEdit->move(30, 70);
        plainTextEdit->resize(100, 100);
        calendar->move(80, 40);

        QWidget *buttonOps = new QWidget;
        QVBoxLayout *l = new QVBoxLayout(buttonOps);
        QPushButton *lower = new QPushButton("button: lower");
        connect(lower, SIGNAL(clicked()), button, SLOT(lower()));
        l->addWidget(lower);
        QPushButton *raise = new QPushButton("button: raise");
        connect(raise, SIGNAL(clicked()), button, SLOT(raise()));
        l->addWidget(raise);

        lower = new QPushButton("calendar: lower");
        connect(lower, SIGNAL(clicked()), calendar, SLOT(lower()));
        l->addWidget(lower);
        raise = new QPushButton("calendar: raise");
        connect(raise, SIGNAL(clicked()), calendar, SLOT(raise()));
        l->addWidget(raise);
        QPushButton *stackUnder = new QPushButton("calendar: stack under textedit");
        connect(stackUnder, SIGNAL(clicked()), this, SLOT(stackCalendarUnderTextEdit()));
        l->addWidget(stackUnder);

        lower = new QPushButton("lower textedit");
        connect(lower, SIGNAL(clicked()), plainTextEdit, SLOT(lower()));
        l->addWidget(lower);
        raise = new QPushButton("raise textedit");
        connect(raise, SIGNAL(clicked()), plainTextEdit, SLOT(raise()));
        l->addWidget(raise);

        QHBoxLayout *mainLayout = new QHBoxLayout(this);
        mainLayout->addWidget(buttonOps);
        mainLayout->addWidget(stackWidget);
    }

private Q_SLOTS:
    void stackCalendarUnderTextEdit()
    {
        calendar->stackUnder(plainTextEdit);
    }

private:
    QPushButton *button;
    QPlainTextEdit *plainTextEdit;
    QCalendarWidget *calendar;
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Widget w;
    w.show();
    return app.exec();
}

#include "main.moc"
