#ifndef REGISTERCONTROLLER_H
#define REGISTERCONTROLLER_H
#include "httprequesthandler.h"
#include <string.h>
#include <QDir>
#include "database.h"

class RegisterController : public HttpRequestHandler {
    Q_OBJECT
public:
    RegisterController(QObject* parent=0);
    void service(HttpRequest& request, HttpResponse& response);
private:
    QByteArray username;
    QByteArray email;
};

#endif // REGISTERCONTROLLER_H
