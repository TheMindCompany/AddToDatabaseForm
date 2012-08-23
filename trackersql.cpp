#include "trackersql.h"

// Start connect and set main QSqlQueryModel data from database.
TrackerSql::TrackerSql(QObject *parent): QSqlQueryModel(parent) {
    db = QSqlDatabase::addDatabase("QMYSQL");
    connectSQL();
}

void TrackerSql::connectSQL(void){
    setConnection();
    createConnection();
}

void TrackerSql::setConnection(void){
    dbHost = "www.themindspot.com";
    dbName = "themind1_AMS";
    dbUser = "themind1_ams";
    dbPass = "nerdsrule";
    dbPort = 3306;
}

void TrackerSql::createConnection(void){
    db.setHostName(dbHost);
    db.setPort(dbPort);
    db.setDatabaseName(dbName);
    db.setUserName(dbUser);
    db.setPassword(dbPass);
    db.open();
}

// Start database edits

void TrackerSql::setTableQuery(void){
    setQuery("SELECT * FROM SurveyPerson");
}

void TrackerSql::setNewRecord(QString f, QString mi, QString l, QString ea, QString ed, bool member){

    QSqlDatabase dbQue;
    dbQue.cloneDatabase(db, "QUE");
    dbQue.open();
    QSqlQuery newRecord;

    newRecord.prepare("INSERT INTO `SurveyPerson` (`surveyPersonID`, `surveyID`, `firstName`, `middleInitial`, `lastName`, `emailAddress`, `emailDomain`, `isMember`)"
                      "VALUES (:id, :sid, :f, :mi, :l, :ea, :ed, :member)");
    newRecord.bindValue(":id", NULL);
    newRecord.bindValue(":sid", 1);
    newRecord.bindValue(":f",f);
    newRecord.bindValue(":mi",mi);
    newRecord.bindValue(":l",l);
    newRecord.bindValue(":ea",ea);
    newRecord.bindValue(":ed",ed);
    newRecord.bindValue(":member",member);
    newRecord.exec();
    newRecord.clear();
    newRecord.finish();
    dbQue.removeDatabase("QUE");
    dbQue.close();
}


