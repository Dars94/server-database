#include "database.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtDebug>

database::database(QString dbname)
{
    name = dbname;
    driver = "QSQLITE";
    sdb = QSqlDatabase::addDatabase(driver);
}

int database::connect()
{
    sdb.setDatabaseName(name);
    if (!sdb.open())
    {
        qDebug() << sdb.lastError().text();
        return -1;
    }
    qDebug() << "connected\n";
    return 0;
}

int database::add(QString qname, QString qemail, QString qpath)
{
    QSqlQuery query;
    query.prepare("insert into users (name, email, path) values (:qname, :qemail, :qpath);");
    query.bindValue(":qname", qname);
    query.bindValue(":qemail", qemail);
    query.bindValue(":qpath", qpath);
    bool execute = query.exec();
    if (!execute)
    {
        qDebug() << query.lastError().text();
        return -1;
    }
    return 0;
}

int database::remove(QString qemail)
{
    QSqlQuery query;
    query.prepare
            ("delete from users where email = :qemail;");
    query.bindValue(":qemail", qemail);
    bool execute = query.exec();
    if (!execute)
    {
        qDebug() << query.lastError().text();
        return -1;
    }
    return 0;
}

QString database::get(QString qemail)
{
    QSqlQuery query;
    query.prepare
            ("select path from users where email = :qemail;");
    query.bindValue(":qemail", qemail);
    bool execute = query.exec();
    if (!execute)
    {
        qDebug() << query.lastError().text();
        return query.lastError().text();
    }
    QSqlRecord record = query.record();
    if (query.next())
    {
        qDebug() << query.value(record.indexOf("path")).toString();
        return query.value(record.indexOf("path")).toString();
    }
    return "not found";
}

int database::createTable()
{
    QSqlQuery query;

     bool execute  = query.exec("create table person "
              "(username varchar(20) primary key, "
              "email varchar(20), "
              "path varchar(30))");

    if (!execute)
    {
        qDebug() << query.lastError().text();
        return -1;
    }
    return 0;
}
