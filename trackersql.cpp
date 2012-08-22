#include "trackersql.h"

// Start connect and set main QSqlQueryModel data from database.
TrackerSql::TrackerSql(QObject *parent): QSqlQueryModel(parent) {
    db = QSqlDatabase::addDatabase("QMYSQL");
    connectSQL();
}

void TrackerSql::connectSQL(void){
    setConnection();
    createConnection();
    setTableQuery();
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
void TrackerSql::submitNew(void){

}

void TrackerSql::setTableQuery(void){
    setQuery("SELECT * FROM SurveyPerson");
}

Qt::ItemFlags TrackerSql::flags(const QModelIndex &index) const{
    Qt::ItemFlags flags = QSqlQueryModel::flags(index);
    if (index.column() == 1 || index.column() == 2)
        flags |= Qt::ItemIsEditable;
    return flags;
}

bool TrackerSql::setData(const QModelIndex &index, const QVariant &value, int role){
    if (index.column() < 1 || index.column() > 2)
        return false;

    QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
    int id = data(primaryKeyIndex).toInt();

    clear();

    bool ok;
    if (index.column() == 1) {
        ok = setFirstName(id, value.toString());
    } else {
        ok = setLastName(id, value.toString());
    }
    refresh();
    return ok;
}

void TrackerSql::refresh(){
    setQuery("select * from SurveyPerson");
}

bool TrackerSql::setFirstName(int personId, const QString &firstName){
    QSqlQuery query;
    query.prepare("update SurveyPerson set firstName = ? where id = ?");
    query.addBindValue(firstName);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setMiddleInitial(int personId, const QString &middleInitial){
    QSqlQuery query;
    query.prepare("update SurveyPerson set middleInitial = ? where id = ?");
    query.addBindValue(middleInitial);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setLastName(int personId, const QString &lastName){
    QSqlQuery query;
    query.prepare("update SurveyPerson set lastName = ? where id = ?");
    query.addBindValue(lastName);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setEmailAddress(int personId, const QString &emailAddress){
    QSqlQuery query;
    query.prepare("update SurveyPerson set emailAddress = ? where id = ?");
    query.addBindValue(emailAddress);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setEmailDomain(int personId, const QString &emailDomain){
    QSqlQuery query;
    query.prepare("update SurveyPerson set emailDomain = ? where id = ?");
    query.addBindValue(emailDomain);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setIsMember(int personId, const QString &isMember){
    QSqlQuery query;
    query.prepare("update SurveyPerson set isMember = ? where id = ?");
    query.addBindValue(isMember);
    query.addBindValue(personId);
    return query.exec();
}

/* Focusing on SurveyPerson table first.
bool TrackerSql::setQ0(int personId, const QString &q0){
    QSqlQuery query;
    query.prepare("update SurveyResponse set q0 = ? where id = ?");
    query.addBindValue(q0);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setQ1(int personId, const QString &q1){
    QSqlQuery query;
    query.prepare("update SurveyResponse set q1 = ? where id = ?");
    query.addBindValue(q1);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setQ2(int personId, const QString &q2){
    QSqlQuery query;
    query.prepare("update SurveyResponse set q2 = ? where id = ?");
    query.addBindValue(q2);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setQ3(int personId, const QString &q3){
    QSqlQuery query;
    query.prepare("update SurveyResponse set q3 = ? where id = ?");
    query.addBindValue(q3);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setQ4(int personId, const QString &q4){
    QSqlQuery query;
    query.prepare("update SurveyResponse set q4 = ? where id = ?");
    query.addBindValue(q4);
    query.addBindValue(personId);
    return query.exec();
}

bool TrackerSql::setQ5(int personId, const QString &q5){
    QSqlQuery query;
    query.prepare("update SurveyResponse set q5 = ? where id = ?");
    query.addBindValue(q5);
    query.addBindValue(personId);
    return query.exec();
}
*/

/*
BELOW ARE THE TABLES USED IN THIS PROGRAM


CREATE TABLE `Survey` (
 `surveyID` int(11) NOT NULL AUTO_INCREMENT,
 `name` varchar(40) DEFAULT NULL,
 `description` varchar(200) DEFAULT NULL,
 PRIMARY KEY (`surveyID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

CREATE TABLE `SurveyPerson` (
 `surveyPersonID` int(11) NOT NULL AUTO_INCREMENT,
 `surveyID` int(11) NOT NULL,
 `firstName` varchar(50) NOT NULL,
 `middleInitial` varchar(2) DEFAULT NULL,
 `lastName` varchar(50) DEFAULT NULL,
 `emailAddress` varchar(64) NOT NULL,
 `emailDomain` varchar(254) NOT NULL,
 `isMember` int(11) NOT NULL,
 PRIMARY KEY (`surveyPersonID`),
 FOREIGN KEY (`surveyID`) REFERENCES `Survey`(`surveyID`) ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;

CREATE TABLE `SurveyResult` (
 `surveyResultID` int(11) NOT NULL AUTO_INCREMENT,
 `surveyPersonID` int(11) NOT NULL,
 `q0` int(11) NOT NULL,
 `q1` int(11) DEFAULT NULL,
 `q2` int(11) DEFAULT NULL,
 `q3` int(11) DEFAULT NULL,
 `q4` int(11) DEFAULT NULL,
 `q5` int(11) DEFAULT NULL,
 PRIMARY KEY (`surveyResultID`),
 FOREIGN KEY (`surveyPersonID`) REFERENCES `SurveyPerson`(`surveyPersonID`) ON UPDATE CASCADE ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1 ;



TEST DATA

INSERT INTO `Survey` (`name`, `description`) VALUES
('Signup Drive (Location: SGMH)', 'AITP Fall 2012 signup drive.  In the SGMH meeting area.'),
('Signup Drive (Location: Center)', 'AITP Fall 2012 signup drive.  In the free speech meeting area.');

INSERT INTO `themind1_AMS`.`SurveyPerson` (`surveyPersonID`, `surveyID`, `firstName`, `middleInitial`, `lastName`, `emailAddress`, `emailDomain`, `isMember`) VALUES
(NULL, '1', 'Brandon', 'L', 'Clark', 'webmind', 'hotmail.com', '1'),
(NULL, '2', 'Sonia', 'M', 'Ramirez', 'nipigapa', 'aol.com', '0');

INSERT INTO `SurveyResult` (`surveyResultID`, `surveyPersonID`, `q0`, `q1`, `q2`, `q3`, `q4`, `q5`) VALUES
( NULL, 1, 1, NULL, NULL, NULL, NULL, NULL),
( NULL, 2, 0, NULL, NULL, NULL, NULL, NULL);
*/


