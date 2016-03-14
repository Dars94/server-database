#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>

class database
{
private:
    QString driver;
    QString name;
    QSqlDatabase sdb;
public:
    database(QString dbname);
    int connect();
    int createTable();
    int add(QString qname, QString qemail, QString qpath);
    int remove(QString qemail);
    QString get(QString qemail);
};

#endif // DATABASE_H
