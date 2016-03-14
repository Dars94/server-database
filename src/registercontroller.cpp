#include "registercontroller.h"

RegisterController::RegisterController(QObject* parent)
    : HttpRequestHandler(parent) {
    username="";
    email = "";
    // empty
}

void RegisterController::service(HttpRequest &request, HttpResponse &response) {
    //registration comes in 2 stages: login and email and 3 photos.

    if (request.getHeader("Content-Type").contains("multipart")){
        //if we recieving multipart data - this is our pictures.
        //we need to make folder in a style of "username+email" and place all 3 pics there
        QTemporaryFile* image;
        QDir().mkdir("E:/files/" + username + email);
        //here we need attach dir to db
        for (int i=0; i<3; i++){
            if ( image = request.getUploadedFile("regphoto" + QByteArray::number(i))){
            image->copy("E:/files/" + username + email+"/userfile" + QByteArray::number(i) + ".png");
            image->remove();
            if (i ==2 ){
                response.write("ok",true);
             }
            }
        }
    }
    else {
      //if this is not multipart data - we in a stage 1 -
      //need to recieve name and email, check it in db, and insert in db in case everything is ok
      bool isNewUser = false; //make false when db is added
      username = request.getParameter("username");
      email = request.getParameter("email");
     qDebug() << "username is:" << username;
     qDebug() << "email is:" <<email;

     //check username and email in db
     //if everything ok: isNewUser = true;
    if (isNewUser == true){
        response.write("true", true);
    }
    else {
        //isNewUser is false, -> user with the same email already exists in db. Sending false to client
        response.write("false", true);
    }
    }
}

