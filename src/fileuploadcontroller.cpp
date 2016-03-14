#include "fileuploadcontroller.h"

FileUploadController::FileUploadController()
{}

void FileUploadController::service(HttpRequest& request, HttpResponse& response)
{
    //we recieved post with picture to check. Lets get it from temp file
    // and copy it to app files folder in order to check it!
   if (QTemporaryFile* image = request.getUploadedFile("userfile") ) {
       if (QFile::exists("E:/file1.png"))
       {
           QFile::remove("E:/file1.png");
       }
       bool rc = image->copy("E:/file1.png");
       qDebug() << "result is:" << rc ;
       if (rc ){
           //some magic face detection here
           response.write("true", true);
           //or false, true if face is not detected
       }
   }
   else {
       qDebug() << "doesnt exists";
   }
}

