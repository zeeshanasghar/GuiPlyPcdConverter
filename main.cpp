/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: za
 *
 * Created on October 28, 2016, 7:15 AM
 */

#include <QApplication>

#include "newForm.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    newForm nf;
    nf.show();
    // create and show your widgets here

    return app.exec();
}
