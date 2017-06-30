//
// Created by BluesJiang on 2017/6/29.
//

#ifndef PLATERECOGNITION_DATAMANAGER_H
#define PLATERECOGNITION_DATAMANAGER_H

#include <mysql.h>
#include <iostream>
#include <vector>
#include "../model/PlateModel.h"

class DataManager {
    MYSQL* connect, mysql;
    const std::string ip, user, pwd, dbname;
public:
    DataManager();
    std::string queryPassword(std::string username);
    int queryPlateInfoWithOwner(std::string owner, PlateModel& retPlate);
    int queryPlateInfoWithPlate(std::string plate, PlateModel& retPlate);
    int queryPlateInfoWithOwners(std::vector<std::string> owners, std::vector<PlateModel>& retVec);
    int queryPlateInfoWithPlates(std::vector<std::string> plates, std::vector<PlateModel>& retVec);
    int queryPlateInfoWithPlateKeyword(std::string keyword, std::vector<PlateModel>& retVec);

    virtual ~DataManager();

private:
    int queryPlateInfo(std::string ownerOrPlate, std::string key, PlateModel &retPlate);
    int queryPlateInfo(std::string ownerOrPlate, std::vector<std::string> keys, std::vector<PlateModel> &retVec);
    int querySingleObject(std::string sql_str, PlateModel &retPlate);
    int queryMultiObject(std::string sql_str, std::vector<PlateModel> &retPlate);
    void connectDB();
    int reconnectDB();
};



#endif //PLATERECOGNITION_DATAMANAGER_H