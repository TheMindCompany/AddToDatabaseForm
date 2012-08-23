#ifndef CARD_H
#define CARD_H

#include "cardui.h"
#include "trackersql.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDataWidgetMapper>

class QDataWidgetMapper;

class Card : public CardUI
{
    Q_OBJECT
public:
    explicit Card(QSqlQueryModel *model, QWidget *parent = 0);

    void setFormMap(QSqlQueryModel *model);
    void clearFields(void);

    QDataWidgetMapper *formMap;

public slots:
    void addRecord();
};

#endif // CARD_H
