#ifndef UPDATEENTRY_H
#define UPDATEENTRY_H
#include <QString>




struct UpdateEntry
{
    QString localLocationTag;
    QString fileName;
    int version;
    QString OSDir;//used flag to tell us to download from sub dir.
};


#endif // UPDATEENTRY_H
