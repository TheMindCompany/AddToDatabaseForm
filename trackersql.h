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
    virtual void setNewRecord(QString f, QString mi, QString l, QString ea, QString ed, bool member);

    QSqlDatabase    db;
    QString         dbHost,
                    dbName,
                    dbUser,
                    dbPass;
    qint32          dbPort;



};

#endif // TRACKERSQL_H
