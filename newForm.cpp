/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newForm.cpp
 * Author: za
 *
 * Created on October 28, 2016, 7:15 AM
 */

#include "newForm.h"

#include <QMessageBox>
#include <QFileDialog>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl-1.7/pcl/io/ply_io.h>
#include <pcl-1.8/pcl/point_cloud.h>


const QString newForm::PCD_FILTER = "PCD file *.pcd (*.pcd)";
const QString newForm::PLY_FILTER = "PLY file *.ply (*.ply)";
const QString newForm::SELECT_A_FILE = "Select a file...";

newForm::newForm() {
    widget.setupUi(this);
    // tab 1 = convertply2pcd
    QObject::connect(widget.btnBrowsePLY, SIGNAL(clicked()), this, SLOT(onBtnBrowsePLYClicked()));
    QObject::connect(widget.btnConvert2PCD, SIGNAL(clicked()), this, SLOT(onBtnConvert2PCDClicked()));
    QObject::connect(widget.btnBrowsePCD, SIGNAL(clicked()), this, SLOT(onBtnBrowsePCDClicked()));
    QObject::connect(widget.btnConvert2PLY, SIGNAL(clicked()), this, SLOT(onBtnConvert2PLYClicked()));
}

void newForm::onBtnBrowsePLYClicked() {
    selectedFileName = QFileDialog::getOpenFileName(this, SELECT_A_FILE, QDir::homePath(), PLY_FILTER);
    widget.leFilePathPLY->setText(selectedFileName);
}

void newForm::onBtnConvert2PCDClicked() {
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    

    if (pcl::io::loadPLYFile<pcl::PointXYZRGB> (selectedFileName.toStdString(), *cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read file %s \n", selectedFileName.toStdString());
        return;
    }
    savedFileName = QFileDialog::getSaveFileName(this, "Save file", QDir::homePath(), PCD_FILTER);
    if (!savedFileName.endsWith(".pcd", Qt::CaseInsensitive))
        savedFileName += ".pcd";

    bool format = 1; // 1 is for binary mode, 0 is for ACII writing mode
    
//    // temporary code to also create a small point cloud file
//    QString temp = "20K-16OCT.pcd";
//    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloudSmart(new pcl::PointCloud<pcl::PointXYZRGB>);
//    typedef unsigned long int uint;
//    cloudSmart->resize(200000);
//    for (uint c = 0; c < 200000; c++)
//        cloudSmart->push_back(cloud->points[c]);
//    pcl::io::savePCDFile<pcl::PointXYZRGB>(temp.toStdString(), *cloudSmart, format);
    
    
    
    if (pcl::io::savePCDFile<pcl::PointXYZRGB>(savedFileName.toStdString(), *cloud, format))
        QMessageBox::warning(this, "Error", "Error while save pcd file.");
    else
        QMessageBox::information(this, "Success", "File converted successfully. \nSaved at: " + savedFileName);
}

void newForm::onBtnBrowsePCDClicked() {
    selectedFileName = QFileDialog::getOpenFileName(this, SELECT_A_FILE, QDir::homePath(), PCD_FILTER);
    widget.leFilePathPCD->setText(selectedFileName);
}

void newForm::onBtnConvert2PLYClicked() {
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    

    if (pcl::io::loadPCDFile<pcl::PointXYZRGB> (selectedFileName.toStdString(), *cloud) == -1) //* load the file
    {
        PCL_ERROR("Couldn't read file %s \n", selectedFileName.toStdString());
        return;
    }
    savedFileName = QFileDialog::getSaveFileName(this, "Save file", QDir::homePath(), PLY_FILTER);
    if (!savedFileName.endsWith(".ply", Qt::CaseInsensitive))
        savedFileName += ".ply";

    bool format = 1; // 1 is for binary mode, 0 is for ACII writing mode
    
//    // temporary code to also create a small point cloud file
//    QString temp = "20K-16OCT.pcd";
//    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloudSmart(new pcl::PointCloud<pcl::PointXYZRGB>);
//    typedef unsigned long int uint;
//    cloudSmart->resize(200000);
//    for (uint c = 0; c < 200000; c++)
//        cloudSmart->push_back(cloud->points[c]);
//    pcl::io::savePCDFile<pcl::PointXYZRGB>(temp.toStdString(), *cloudSmart, format);
    
    
    
    if (pcl::io::savePLYFile<pcl::PointXYZRGB>(savedFileName.toStdString(), *cloud, format))
        QMessageBox::warning(this, "Error", "Error while save ply file.");
    else
        QMessageBox::information(this, "Success", "File converted successfully. \nSaved at: " + savedFileName);
}