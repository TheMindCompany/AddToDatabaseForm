#include "card.h"

Card::Card(QSqlQueryModel *model, QWidget *parent) :  CardUI(parent){
    setFormMap(model);
}

void Card::setFormMap(QSqlQueryModel *model){

    formMap = new QDataWidgetMapper(this);
    formMap->setModel(model);
    formMap->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    formMap->addMapping(cardID, 0);
    formMap->addMapping(fnText, 2);
    formMap->addMapping(miText, 3);
    formMap->addMapping(lnText, 4);
    formMap->addMapping(eaText, 5);
    formMap->addMapping(edText, 6);
    formMap->addMapping(isMember, 7);
    /* Focusing on SurveyPerson table first.
    formMap->addMapping(q0, 2);
    formMap->addMapping(q1, 3);
    formMap->addMapping(q2, 4);
    formMap->addMapping(q3, 5);
    formMap->addMapping(q4, 6);
    formMap->addMapping(q5, 7);*/

    connect(submitNew, SIGNAL(clicked()), model, SLOT(submit()));
    //connect(formMap, SIGNAL(currentIndexChanged(int)), submitNew, SLOT(sendUpdate(model)));
}

