#include "cardui.h"
#include <QFile>

CardUI::CardUI(QWidget *parent) :  QWidget(parent){
    cardFields();
    setLayout(card);
    cardID = new QLabel("");
    cardID->setHidden(true);
}

void CardUI::cardFields(void){
    createCardFields();
    arrangeCardFields();
    setCardStyle();
}

void CardUI::createCardFields(void){
    nameFields();
    emailFields();
    submitFields();
}

void CardUI::arrangeCardFields(void){
    infoRequest = new QVBoxLayout;
    card = new QHBoxLayout;

    infoRequest->addLayout(name);
    infoRequest->addLayout(email);
    infoRequest->addLayout(submit);

    card->addLayout(infoRequest);
}

void CardUI::nameFields(void){
    createNameFields();
    setNameFields();
    arrangeNameFields();
}

void CardUI::createNameFields(void){
    fnText = new QLineEdit;
    miText = new QLineEdit;
    lnText = new QLineEdit;
}

void CardUI::setNameFields(void){
    fnText->setMaximumWidth(190);
    miText->setMaximumWidth(50);
    lnText->setMaximumWidth(190);

    miText->setAlignment(Qt::AlignCenter);

    fnText->setPlaceholderText("First Name");
    miText->setPlaceholderText("MI");
    lnText->setPlaceholderText("Last Name");
}

void CardUI::arrangeNameFields(void){
    name = new QHBoxLayout;

    name->addWidget(fnText);
    name->addWidget(miText);
    name->addWidget(lnText);
}

void CardUI::emailFields(void){
    createEmailFields();
    setEmailFields();
    arrangeEmailFields();
}

void CardUI::createEmailFields(void){
    eaText = new QLineEdit;
    eAtLabel = new QLabel("@");
    edText = new QLineEdit;
}

void CardUI::setEmailFields(void){
    eaText->setPlaceholderText("Email Address");
    edText->setPlaceholderText("Email Domain");
}

void CardUI::arrangeEmailFields(void){
    email = new QHBoxLayout;

    email->addWidget(eaText);
    email->addWidget(eAtLabel);
    email->addWidget(edText);
}

void CardUI::submitFields(void){
    createSubmitFields();
    setSubmitFields();
    arrangeSubmitFields();
}

void CardUI::createSubmitFields(void){
    submitNew = new QPushButton("Add");
    isMember = new QCheckBox;
}

void CardUI::setSubmitFields(void){
    submitNew->setFixedWidth(100);
    submitNew->setFixedHeight(50);
    isMember->setText("Member");
}

void CardUI::arrangeSubmitFields(void){
    submitStatus = new QVBoxLayout;
    submit = new QHBoxLayout;

    submitStatus->addWidget(submitNew);
    submitStatus->addWidget(isMember);

    submit->addLayout(submitStatus);
}

void CardUI::setCardStyle(void){
    QFile stylesheet("C:/Users/MindTopOne/Desktop/Flash Backup/workplace/amsTracker/assets/cardDesktopStyle.qss");
    stylesheet.open(QFile::ReadOnly);
    QString setSheet = QLatin1String(stylesheet.readAll());
    setStyleSheet(setSheet);
 }
