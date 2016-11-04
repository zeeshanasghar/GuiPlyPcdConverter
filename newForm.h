/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newForm.h
 * Author: za
 *
 * Created on October 28, 2016, 7:15 AM
 */

#ifndef _NEWFORM_H
#define _NEWFORM_H

#include "ui_newForm.h"

class newForm : public QMainWindow {
    Q_OBJECT
public:
    newForm();
private:
    Ui::newForm widget;
    QString selectedFileName;
    QString savedFileName;

    const static QString PCD_FILTER;
    const static QString PLY_FILTER;
    const static QString SELECT_A_FILE;
private slots:
    void onBtnBrowsePLYClicked();
    void onBtnConvert2PCDClicked();
    void onBtnBrowsePCDClicked();
    void onBtnConvert2PLYClicked();
};

#endif /* _NEWFORM_H */
