#ifndef OBJECTHANDLER_H
#define OBJECTHANDLER_H
#include <unordered_map>
#include <string>
#include <QObject>
#include <vector>

#include "callbackhandler.h"

class objectHandler
{

    QObject* const rootObj_;
    CallbackHandler callbacks_;
    std::vector<std::string> child_names_;
    std::unordered_map<std::string, QObject*> child_objects_;
    void loadObjects();

public:
    objectHandler(QObject*const root);
    ~objectHandler();
    void updateChildProperty(std::string name, std::string property, std::string value);
    void updateChildProperty(std::string name, std::string property, int32_t value);
    void updateChildProperty(std::string name, std::string property, float value);
};

#endif // OBJECTHANDLER_H
