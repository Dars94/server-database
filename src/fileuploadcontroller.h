#ifndef FILEUPLOADCONTROLLER_H
#define FILEUPLOADCONTROLLER_H

#include "httprequest.h"
#include "httpresponse.h"
#include "httprequesthandler.h"
#include "database.h"

class FileUploadController : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(FileUploadController)
public:

    /** Constructor */
    FileUploadController();

    /** Generates the response */
    void service(HttpRequest& request, HttpResponse& response);
};

#endif // FILEUPLOADCONTROLLER_H
