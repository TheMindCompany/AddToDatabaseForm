#ifndef TRACKERSQL_H
#define TRACKERSQL_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlQueryModel>

class TrackerSql : public QSqlQueryModel
{
    Q_OBJECT
public:
    TrackerSql(QObject *parent = 0);

    void connectSQL(void);          // Start sql connections and initialize `dbQuery`(s).
    void setConnection(void);       // Set the connection parameters.
    void createConnection(void);    // Start the `db` connection.

    void setTableQuery(void);       // Create `dbQuery`(s).
    void refresh();                 // Refresh QSqlQueryModel

    // Allow write mode to QSqlQueryModel
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    QSqlDatabase    db;
    QString         dbHost,
                    dbName,
                    dbUser,
                    dbPass,
                    dbString;
    qint32          dbPort;

private:
    // Update members to QSqlQueryModel.
    bool setFirstName(int personId, const QString &firstName);
    bool setMiddleInitial(int personId, const QString &middleInitial);
    bool setLastName(int personId, const QString &lastName);
    bool setEmailAddress(int personId, const QString &emailAddress);
    bool setEmailDomain(int personId, const QString &emailDomain);
    bool setIsMember(int personId, const QString &isMember);
    /* Focusing on SurveyPerson table first.
    bool setQ0(int personId, const QString &q0);
    bool setQ1(int personId, const QString &q1);
    bool setQ2(int personId, const QString &q2);
    bool setQ3(int personId, const QString &q3);
    bool setQ4(int personId, const QString &q4);
    bool setQ5(int personId, const QString &q5);
    */

signals:
    
public slots:
    void submitNew(void);  // A idea(tmp maybe)
};

#endif // TRACKERSQL_H
