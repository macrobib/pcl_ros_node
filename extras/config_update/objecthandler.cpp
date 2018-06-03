#include "objecthandler.h"
#include <iostream>


objectHandler::objectHandler(QObject* const root):rootObj_(root), callbacks_(root)
{
    child_names_.push_back("Button1");
    child_names_.push_back("Button2");
    child_names_.push_back("Button3");
    child_names_.push_back("Button4");

    child_names_.push_back("Slider1");
    child_names_.push_back("Slider2");
    child_names_.push_back("Slider3");
    child_names_.push_back("Slider4");

    child_names_.push_back("Text1");
    child_names_.push_back("Text2");
    child_names_.push_back("Text3");
    child_names_.push_back("Text4");

    loadObjects();
}

objectHandler::~objectHandler(){}

void objectHandler::updateChildProperty(std::string name, std::string property, float value)
{
}

void objectHandler::updateChildProperty(std::string name, std::string property, int32_t value)
{
}

void objectHandler::updateChildProperty(std::string name, std::string property, std::string value)
{
}



void objectHandler::loadObjects()
{
    //Populate an array of QObjects.
    for(int i = 0; i < child_names_.size(); i++){
        std::string child(child_names_[i]);
        QObject* entry = rootObj_->findChild<QObject*>(child.c_str());
        if(entry)
            child_objects_[child] = entry;

        if(child == "Button1")
            QObject::connect(child_objects_[child], SIGNAL(button1Callback(QString)), &callbacks_, SLOT(button1Callback(QString)));
        else if(child == "Button2")
            QObject::connect(child_objects_[child], SIGNAL(button2Callback(QString)), &callbacks_, SLOT(button2Callback(QString)));
        else if(child == "Button3")
            QObject::connect(child_objects_[child], SIGNAL(button3Callback(QString)), &callbacks_, SLOT(button3Callback(QString)));
        else if(child == "Button4")
            QObject::connect(child_objects_[child], SIGNAL(button4Callback(QString)), &callbacks_, SLOT(button4Callback(QString)));
        else if(child == "Slider1")
            QObject::connect(child_objects_[child], SIGNAL(slider1Signal(double)), &callbacks_, SLOT(slider1Callback(double)));
        else if(child == "Slider2")
            QObject::connect(child_objects_[child], SIGNAL(slider2Signal(double)), &callbacks_, SLOT(slider2Callback(double)));
        else if(child == "Slider3")
            QObject::connect(child_objects_[child], SIGNAL(slider3Signal(double)), &callbacks_, SLOT(slider3Callback(double)));
        else if(child == "Slider4")
            QObject::connect(child_objects_[child], SIGNAL(slider4Signal(double)), &callbacks_, SLOT(slider4Callback(double)));
        else if(child == "Text1")
            QObject::connect(child_objects_[child], SIGNAL(text1Changed(QString)), &callbacks_, SLOT(text1Callback(QString)));
        else if(child == "Text2")
            QObject::connect(child_objects_[child], SIGNAL(text2Changed(QString)), &callbacks_, SLOT(text2Callback(QString)));
        else if(child == "Text3")
            QObject::connect(child_objects_[child], SIGNAL(text3Changed(QString)), &callbacks_, SLOT(text3Callback(QString)));
        else if(child == "Text4")
            QObject::connect(child_objects_[child], SIGNAL(text4Changed(QString)), &callbacks_, SLOT(text4Callback(QString)));

    }
}
